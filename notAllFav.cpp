#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,k;
        cin>>n>>k;

        vector<int>a(n);
        for(auto&x:a)cin>>x;

        //Arranged n cakes in row in an order
        //k types of flavours are there : 1....k

        //We want a contiguous subsegment of  pieces such that at least one flavour which doesn't occur in the subsegment 
        //find max possible length of such a subsegment

        //Possible k = 1,2,3,4....k ->atleast one of them should not come in our subsegment

        //So as soon as our set size gets graeater than req size, we can record our answer

        map<int,int>freq;
        int ans = 0;

        int left = 0;

        for(int right = 0;right<n;right++)
        {
            freq[a[right]]++;

            while(freq.size() == k)
            {
                freq[a[left]]--;
                
                if(freq[a[left]] == 0)freq.erase(a[left]);
                left++;
            }
            ans =max(ans,right-left+1);
        }
        cout<< ans << '\n';    
    }

    return 0;
}


// 1 1 2 2 1
