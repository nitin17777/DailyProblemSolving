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
        ll n,x1,x2,k;
        cin>>n>>x1>>x2>>k;

        //at time 0 : Reimu is at position x1 and rem at x2

        //rem moves to adj posi or stays in place, over the entire game she can do so only k times

        //Rem can do the same 

        //If they are at same posi after doing this-> remu cathces and game ends

        //find number of seconds till he finds her
            
        if(n<=3)
        {
            cout<<1<<'\n';
            continue;
        }

        cout<<min(abs(x1-x2),n-abs(x1-x2))+k<< '\n';
    }

    return 0;
}