#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solve(string&u,int n,int x,int s)
{
    /*

    X tables with s seats each 

    HE can either assign them a table or kick them out of the party

    Determine the max number of people she can make sit

    Extrovert -> Non empty table only
    Intorvert -> Empty table only
    Ambivert -> Any table
    

    
    */



}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,x,s;
        cin>>n>>x>>s;

        string u(n);
        cin>>u;
        cout<solve(u,n,x,s)<<endl;
    }

    return 0;
}