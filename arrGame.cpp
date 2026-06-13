#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(vector<ll>&a,ll k)
{

    
   // Select some i < j and appennd |ai -aj| at the end of array
   // Find min value of ARRAY after k operations are performed
       
    


    // 1 3 7 9 15
    // 1 3 7 9 15 2
    // 1 3 7 9 15 2 1
    ll n = a.size();

    if(k>=3)return 0;


    sort(a.begin(),a.end());
    
    ll ans = a[0];

    for(int i = 0;i<a.size()-1;i++)ans= min(ans,a[i+1]-a[i]);
    
    if(k==1)return ans;

    //Now k == 2
    for(int i=0;i<n;i++)
    {
        for(int j =0;j<i;j++)
        {
            ll v = a[i] - a[j];

            //First element greater than equal to d
            ll p = lower_bound(a.begin(),a.end(),v) - a.begin();


            // Checking which one is smaller just greater or just smaller one?
            if(p<n)ans = min(ans,a[p] - v);
            if(p>0)ans = min(ans,v -a[p-1]); 
        }
    }
    return ans;
}
  
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll n,k;
        cin>>n>>k;

        vector<ll>a(n);
        for(auto & x:a)cin>>x;

        cout<<solve(a,k)<<'\n';
    }

    return 0;
}

/*

4 7 12 15 (INITIALLY)

4 7 12 15 3
4 7 12 15 3 3
4 7 12 15 3 3 0


*/