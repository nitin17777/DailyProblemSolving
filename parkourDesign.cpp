#include<bits/stdc++.h>
using namespace std;

bool solve(int x,int y)
{

    if((x+y) %3 != 0)return false;
    
    if(y < -x / 4.0 || y > x /2.0)return false;
    
    return true;
}

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

        cout<<(solve(n,m)?"Yes" : "No")<<endl;
        
    }
    return 0;
}