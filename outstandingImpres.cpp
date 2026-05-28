#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(int l,int r,map<int,int>&fixed,vector<int>&pref)
{

    //Unique if: wi != wj for all j with j!=i

    //For every index check if it can become unique

    /*

    Check numbers which has l==r firstly

    Now for every li,ri check if any other number can be there between then instead of these fixed nums -> if yes ->add 1 ,else add 0    
    */


    if(l==r)
    {
        return fixed[l]==1;
    }

    int occupied = pref[r]-pref[l-1];

    return occupied < (r-l+1);
}
      
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

        string ans = "";

        map<int,int>fixed;
        
        vector<pair<int,int>>idx;

        int mx = 0;
        while(n--)
        {
            int l,r;
            cin>>l>>r;

            if(l==r)fixed[l]++;

            idx.push_back({l,r});
            
            mx = max(mx,r);//Needed to count sufficient prefix sum
        }


        //Optimisation part now
        vector<int>pref(mx+2,0);
        //pref[i] = how many occupied numbers  exists from 1 to i

        //Marked all the singletons 
        for(auto & x:fixed)pref[x.first] =1;
        

        for(int i = 1;i<=mx;i++)
        {
            pref[i] += pref[i-1];
        }


        for(auto &x:idx)
        {
            if(solve(x.first,x.second,fixed,pref))ans+='1';
            else ans+='0';
        }
        cout<<ans<<endl; 
    }
    return 0;
}