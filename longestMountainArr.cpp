#include<bits/stdc++.h>
#define ll long long
using namespace std;

int longestMountain(vector<int>& a)
{

    int n = a.size();
    int ans = 0;

    /*
    Return the length of the longest subarray which is a mountain, else return 0

    */

    // for every element check if it is peak or not and extend the mountain to both sides.

    for(int i = 1;i<n-1;i++)
    {
        if(a[i] > a[i-1] && a[i]>a[i+1])
        {
            int l = i,r=i;

            while(l>0 && a[l] > a[l-1])l--;

            while(r < n-1 && a[r] > a[r+1])r++;
            ans = max(ans, r-l+1);
        }
    }
    return ans;  
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a = {2,1,4,7,3,2,5};
    cout<<longestMountain(a)<<endl;


    return 0;
}