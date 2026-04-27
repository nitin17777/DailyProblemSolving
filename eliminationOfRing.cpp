#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int>&a)
{
    int n = a.size();


    /*

    IF two adj elements in sequence are equal at any time -> one of them willl be erased instantly


    HE can perform this step until sequence becomes empty: Choose an element and erase it

    Determine the max number of operations he could perform 
    
    So we need to just make sure 


    Just delete any one occurence of same digit
    */

    set<int>st(a.begin(),a.end());

    int ele = st.size();

    if(ele == 2)
    return n/2 + 1;
    
    else return n;

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

        for(auto&x:a)cin>>x;

        cout<<solve(a)<<endl;

    
    }

    return 0;
}