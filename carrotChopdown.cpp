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
        int n,m;
        cin>>n>>m;

        vector<int>a(n);
        for(auto & x:a)cin>>x;

        //For each operation -> Choose a set of carrots,including already chooped carrots

        //Max number of carrots we can sell after using machine exactly 1 time

        //let l = length of carrot , then it is divided into 2 carrrots of size x and l-x

        //if freq of any element is greater than n/2 -> freq*2 + 

        // else return n

        //for any x answer is the number of carrots greater than x + carrots of length 2x
        sort(a.begin(),a.end());

        unordered_map<int,int>freq(m+1);
        for(auto &x:a)freq[x]++;

        vector<int>suffix(m+2,0);

        for(int x = m;x>=1;x--)
        {
            suffix[x] = suffix[x+1]+freq[x];
        }

        int ans=0;
        for(int x = 1;x<=m;x++)
        {
            ans = max(ans,suffix[x]+(2*x <= m? freq[2*x]:0));
        }
        cout<<ans<<'\n';
    }
    return 0;
}