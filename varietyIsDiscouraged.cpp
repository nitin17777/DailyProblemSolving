#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int>solve(vector<int>&a,int n)
{

    vector<int>ans(2);

    /*
    score = len(b) - distinct elements in b

    We need to remove some subarrays from a at most once

    Return the operation such that score of a is max and length of the array is minimum


    */

    //score is max

    unordered_map<int,int>freq;
    for(auto & x:a)freq[x]++;

    

    //removing any element will not increase our score as len will decrease and distinct(a) will decrease as well

    //Find longest subarray in which the elements have only 1 occurence

    int bestLen = 0;
    int bestR = -1, bestL = -1;
    int currLen = 0,start = 0;
    //currlen = current length of consecutive globally unique elements
    //start = starting index of current segment

    //finding the longest contiguous segment where each element appears once exactly in the whole array globally

    for(int i = 0;i<n;i++)
    {

        //Check if it is unique globally
        if(freq[a[i]] == 1)
        {
            //if starting a new valid segment -> mark it's start index
            if(currLen  == 0)start = i;

            currLen++;

            if(currLen > bestLen)
            {
                bestLen = currLen;
                bestL = start;
                bestR = i;
            }
        }

        else
        {
            currLen =0;
        }
    }

    if(bestLen == 0)return {};

    return {bestL + 1,bestR+1};
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int>a(n);
        for(auto& x:a)cin>>x;

        vector<int>ans = solve(a,n);

        if(ans.empty())cout<<0<<endl;
        
        else cout<<ans[0]<<" "<<ans[1]<<endl;
    }

    return 0;
}




