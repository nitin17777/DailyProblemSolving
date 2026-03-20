#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>&a)
{
    int n = a.size();

    /*

    We can : choose any number from first bag and move it to the secodn bag
           : Choose a number from bag 1 that is also in bag 2 and increaseit by one


    Determine if it is possible to make the content of both bags identical

    We can perform both the ops any number of times
    
    */

    sort(a.begin(),a.end());
    int mx = 0;

    for(int i = 0;i<n;i+=2)
    {
        //Checking if both elements of the pair can be equal after increments
        if(max(mx,a[i]) != max(mx,a[i+1]))return false;


        //After using this pair, future values must be at least this + 1
        mx = max(mx,a[i]) + 1;
    }

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