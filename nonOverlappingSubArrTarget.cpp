#include<bits/stdc++.h>
#define ll long long
using namespace std;

int minSumOfLengths(vector<int>& arr, int target)
{
    int n = arr.size();
    const int INF = 1e9;
    /*

    Find two non overlapping sub arrays with sum equal to target, then sum of lenghts of two sub arrays must be minimum

    Return min sum of lengths of two required sub arrays or return -1 if unable to find any 
    */

    //Final answer would be minimum sum of prefix and suffix within all indices

    vector<int>pref(n,INF);

    //pref[i] = min length of subarray with sum target that ends at or before index i

    //suff[i] = min length of subarrayw with sum target that starts at or after index i 


    int left = 0;
    ll sum = 0;

    int ans = INF;

    for(int right =0;right<n;right++)
    {
        //Adding current element to sum
        sum += arr[right];

        //Shrinking window when it's sum becomes greater than target
        while(sum > target)
        {
            sum -= arr[left];
            left++;
        }
        
        //If current window has sum equal to target ->arr[left....right]is valid array
        if(sum==target)
        {
            int len = right-left+1;

            // IF there is a valid subarray completely before left , combine it with current one
            if(left > 0 && pref[left-1] != INF)
            {
                ans = min(ans, len+pref[left-1]);
            }

            //storing the shortest valid subarray seen so far
            if(right==0)pref[right] =len;
            else pref[right] = min(pref[right-1],len);
        }

        else
        {
            //No valid subarray ending at right -> just carry forward the previous best
            if(right>0)pref[right] = pref[right-1];
        }
    }
    return ans == INF?-1 : ans;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>arr = {3,2,2,4,3};

    cout<<minSumOfLengths(arr,3)<<endl;

    return 0;
}