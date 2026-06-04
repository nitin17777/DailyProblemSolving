#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll MOD = 998244353;
const int N = 200005;



ll fact[N];
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    fact[0] = 1;
    for(int i = 1;i<N;i++)
    {
        fact[i] = (fact[i-1] *i)%MOD; 
    }

    while(t--)
    {
        string s;
        cin>>s;

        int n = s.size();

        //Choose any character from string and erase it and make the string alternating


        // Calculate: Min ops to make s alternating and number of different shortest sequences of ops that makes s alternating    
        
        
        //Delete the char that has a[i-1]same

        vector<int>blocks;
        int len = 1;

        for(int i = 1;i<n;i++)
        {
            if(s[i] == s[i-1])len++;
            else
            {
                blocks.push_back(len);
                len = 1;
            }
        }

        blocks.push_back(len);
        
        int k = blocks.size();

        int ops = n-k;


        ll ways = 1;

        for(int x:blocks)
        {
            ways = (ways *x)%MOD;
        }

        ways = (ways * fact[ops])%MOD;
        
        cout<<ops<<" "<< ways<<endl;
    }
    return 0;
}