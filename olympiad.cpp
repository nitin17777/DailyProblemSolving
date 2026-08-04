#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    int n;
    cin>>n;

    vector<int>a(n);
    for(auto&x:a)cin>>x;

    sort(a.begin(),a.end());

    set<int>st(a.begin(),a.end());


    int k =st.size();

    if(a[0]==0)cout<<k-1<<endl;

    else cout<<k<<endl;

    return 0;
}