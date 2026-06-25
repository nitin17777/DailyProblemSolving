#include<bits/stdc++.h>
#define ll long long
using namespace std;



//Didn't understood the question and solution much

int solve(vector<int>&a,int n)
{
    //determine the min number of nesting dolls that can make this sequence

    map<int,int>cnt;
    set<int>b;

    for(auto & x:a)
    {
        cnt[x]++;
        b.insert(x);
        b.insert(x+1);
    }

    int last = 0;
    int res = 0;

    for(auto &x:b)
    {
        //Number of dolls of size x
        int c = cnt[x];

        //If there are more dolls of size x than there were of size x-1,
        res+=max(0,c-last);
        last = c;
    }
    return res;
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

        cout<<solve(a,n)<<'\n';
        //Find the min number of nesting dolls 
    
    }

    return 0;
}


