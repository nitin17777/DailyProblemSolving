#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(vector<int>&a,int n)
{
    /*

    iulina drinks only from odd numbered glasses while jher date drinks from even numebered glasses

    Wants to find a contiguous subarray such that they both have smae amount of juice 
    */

    

    //Determine the subarray such that sums of even and odd parity in that sub is same


    //Flipping all elements at even indices
    for(int i = 0;i<n;i+=2)a[i] = -a[i];

    ll pref = 0;
    //  IMPORTANTR RESULT : if two prefix sums are equal, then the subarray between them has sum 0 ,otherwise, no subarray has sum 0
    
    set<ll>st;
    st.insert(0);

    for(auto & x:a)
    {
        pref+=x;
        if(st.count(pref))return true;//When two prefix values are same

        st.insert(pref);
    }
    return false;
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


        vector<int>a(n);
        for(auto & x:a)cin>>x;

        cout<<(solve(a,n)?"Yes":"NO")<<endl;
    }

    return 0;
}