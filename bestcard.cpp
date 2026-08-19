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

        bool good = true;
        //if one of the numbers x and y are divisible by each other ->smaller value card wins, else bigger card wins
        for(int i =2;i<=n;i++)
        {
            if(((n+1)%i )== 0)
            {
                good=false;
                break;
            }
        }
        cout<<(good?"Yes":"No")<<'\n';
    }
    return 0;
}