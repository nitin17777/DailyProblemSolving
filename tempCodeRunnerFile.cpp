#include<bits/stdc++.h>
using namespace std;

int solve(int x,int y,int k)
{
    //Return min moves required to land on point (x,y)
    //At each step he must alter 

    int yy = (y+k-1)/k;
    int xx = (x+k-1)/k;

    if(yy >= xx)return 2*yy;
    else return 2*xx-1;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int x,y,k;
        cin>>x>>y>>k;

        cout<<solve(x,y,k)<<endl;
    }
    return 0;
}