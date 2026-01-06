#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>&a)
{
    /*
    Equality characteristic = arr b where bi = 1,if both of a's neighbour are equal to ai

    0 otherwise

    We are given array b, we have to determine if any array a exists or not


    */

    string s = "";

    for(auto & x: a)
    s+=to_string(x);

    size_t pos = s.find("101");
    if(pos != string::npos)return false;
    
    return true;
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

        cout<<(solve(a)?"Yes":"No")<<endl;
    }
    return 0;
}