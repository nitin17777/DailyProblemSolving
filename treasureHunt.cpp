#include<bits/stdc++.h>
using namespace std;

bool solve(int x,int y,int a)
{
    //Treasue burried at depth of a.5 meters

    // B-> x meters of soil each day

    //yes if little b digs first else no

    //number of pairs of ops = a/x+y

    return a%(x+y) >= x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int x,y,a;
        cin>>x>>y>>a;

        cout<<(solve(x,y,a)? "Yes":"No")<<endl;
    }
    return 0;
}