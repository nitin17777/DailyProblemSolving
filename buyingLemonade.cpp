#include<bits/stdc++.h>
using namespace std;
#define ll long long

int solve(vector<int>&a,int k)
{
    int n = a.size();

    //Determine the min number of button presses needed to guarantee that you receive atleast k cans of lemonade

    //The optimal strategy would  be:  Press each button atleast once frist,becasue we are sure of getting 1 one can atleast from every slot

    sort(a.begin(),a.end());
    ll cans = 0, x= 0,prev = 0;

    if(k < a[0] * n)return k;

    for(int i = 0; i < n;i++)
    {
        ll diff = a[i] - prev;
        ll gain = diff * (n-i);

        if(cans + gain >= k)break;

        cans+=gain;
        prev = a[i];
        x++;// May cause one failed press
    }
    return k+x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(auto & x:a)cin>>x;

        cout<<solve(a,k)<<endl;
    }
    return 0;
}