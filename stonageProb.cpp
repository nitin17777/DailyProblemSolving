#include<bits/stdc++.h>
#define ll long long
using namespace std;

void op2(vector<int>&a,int x)
{
    for(int i=0;i<a.size();i++)
    {
        a[i] = x;
    }
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,q;
    cin>>n>>q;

    vector<ll>a(n+1);
    

    //Calculate sum after performing each query

    ll sum = 0;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }


    //LAst time each index was individually updated
    vector<int>lastUpdate(n+1,0);

    //Value assigned to elements in last type 2 query
    ll allValue = 0;

    int globalTime = 0;//timestamp of last type2 query

    while(q--)
    {
        //if t = 1 -> i and x
        //if t = 2 -> new value of each element
        int t;
        cin>>t;

        if(t==1)
        {
            int i;
            ll x;
            cin>>i>>x;

            ll oldValue;

            if(lastUpdate[i] < globalTime)oldValue = allValue;
            else oldValue = a[i];

            sum-=oldValue;
            sum+=x;

            a[i] = x;

            lastUpdate[i] = globalTime;
        }

        else
        {
            ll x;
            cin>>x;

            globalTime++;
            allValue = x;
            sum = 1LL * n *x;
        }

        cout<< sum <<'\n';
    }
    return 0;
}