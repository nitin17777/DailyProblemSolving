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
        int n;
        cin>>n;

        vector<int>pos(n+5);

        vector<int>a(n+5);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            pos[a[i]]=i%2;//to determine even or odd position
        }
        
        /*
        hill if: there exists an index k such that :

        first k elements are strictly increasing
        And last m-k+1 elements are strictly decreasing

        We can : choose i and swap ai, ai+2

        determine if we can turn array a into hill by performign any number of operation


        We can arbitrarily arrange elements placed in same parity

        */

        //We just need to determine if we can fit in the given number of odds and evens in given space or not

        int balance = 0;

        bool possible = true;
        for(int x=n; x>0; x--)
        {
            if(pos[x]%2==0)balance++;
            if(pos[x]%2==1)balance--;

            if(abs(balance)>1)
            {
                possible = false;
                break;
            }
        }
        cout<<((possible)?"YES":"NO")<<'\n';
    }
    return 0;
}