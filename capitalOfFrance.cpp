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

        int mn = INT_MAX,mx = 0;

        vector<int>a(n);
        for(auto&x:a)
        {
            cin>>x;

            mn = min(mn,x);
            mx = max(mx,x);
        }

        /*

        ith restaurant has ai rating 

        Chooses two adjacent restautants and increases the rating of lower rated restaurant by 1



        Max delicacy after performing zero or more operations


        
        */
        //Max value cannot increase, so msb (ans) = msb(max(a))


        //If min element has lower msb than the maximum rating: then minimum can be increased upto 2^b -1

        //Can't do anything if smallest and biggest elements are same
        if(mn==mx)
        {
            cout<<mx<<'\n';
            continue;
        }

        //finding the highest set bit position for a 32 bit integer
        int k = 31 - __builtin_clz(mx^mn);

        //Made the highest achievable number starting with k as it's highest bit 
        int mask = (1<<(k+1))-1;

        //Finally combining those remaining bit mx  
        cout<<(mx | mask)<<'\n';
    }

    return 0;
}