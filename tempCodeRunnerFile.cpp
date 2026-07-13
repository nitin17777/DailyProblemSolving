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

    vector<int>a(n);
    for(auto & x:a)cin>>x;


    //Calculate sum after performing each query

    while(q--)
    {
        //if t = 1 -> i and x
        //if t = 2 -> new value of each element
        int t;
        cin>>t;

        if(t==1)
        {
            int i,x;
            cin>>i>>x;
            a[i] = x;
        }

        else
        {
            int x;
            cin>>x;

            op2(a,x);
        }

        cout<< accumulate(a.begin(),a.end(),0)<<'\n';
    }
    return 0;
}