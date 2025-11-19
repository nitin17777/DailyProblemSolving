#include<bits/stdc++.h>
using namespace std;


bool isPos(vector<int>&s)
{
    int n = s.size();

    /*
    worst case for any clock i : going to end or first: 2(n-i) or 2(i-1)
    and we will solve this question taking these extremums onnly

    so max gap : 2*(max(i-1,n-1))
    */

    for(int i = 0;i<n;i++)
    {
        int need = 2*max(i,n-i-1);
        if(s[i] <= need)return false;
    }
    return true;
}

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;

        vector<int>s(n);
        for(auto&x: s)cin>>x;

        cout<<(isPos(s)? "YES": "NO")<<endl;

    }
    return 0;
    
}
