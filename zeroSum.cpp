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
    
        int sm = 0;
        vector<int>a(n);
        for(auto & x:a)
        {
            cin>>x;
            sm+=x;
        }

        //We can multiply i and i+1 by minus in each step 
        //Can we get sum of elements equal to 0?

        cout<<((abs(sm)%4 == 0)?"Yes" : "No")<<'\n';
    }
    return 0;
}