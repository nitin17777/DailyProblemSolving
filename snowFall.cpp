#include<bits/stdc++.h>
#define ll long long
using namespace std;



vector<int>solve(vector<int>&a,int n)
{
    //f(a) = number of arrays whose product is divisble by 6


    //Reorder the array such that f(a) is minimised

    //just sideline the already present multiples of 6

    //Just maximise the distance bw multiples of 3 and 2


    vector<int>two,three,other,ans,both;

    for(int i = 0;i<n;i++)
    {
        if(a[i]%6 == 0)both.push_back(a[i]);
        else if(a[i]%2 == 0)two.push_back(a[i]);
        else if(a[i]%3 == 0)three.push_back(a[i]);
        else other.push_back(a[i]);
    }

    for(auto & x:two)ans.push_back(x);
    for(auto & x:other)ans.push_back(x);
    for(auto & x:three)ans.push_back(x);
    for(auto & x:both)ans.push_back(x);

    

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
        int n;
        cin>>n;


        vector<int>a(n);
        for(auto & x:a)cin>>x;

        vector<int>ans = solve(a,n);

        for(auto & x:ans)cout<<x<<" ";

        cout<<endl;    
    }

    return 0;
}