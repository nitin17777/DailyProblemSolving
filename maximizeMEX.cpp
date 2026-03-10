#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&a,int x)
{
    int n = a.size();

    //WE can increase any element of the array by x any number of times

    //Find the max value of mex of a after optimally performing these ops

    /*
    Key points: MEX can atmost be equal to n

    */

    vector<int> freq(n+5);
    for(int i = 0;i<n;i++)
    {
        if(a[i] <n)freq[a[i]]++;
    }

    for(int i=0;i<n;i++)
    {
        if(freq[i] == 0)return i;

        if(freq[i] > 1)
        {
            //reseting freq of i to 1 
            int extra = freq[i] -1;
            freq[i] = 1;

            //Increase the frequency of (i+x)th element by extras
            //Optimised here : As we don't care of 
            if(i+x <= n)freq[i+x] += extra;
        }
    }
    return n;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;

        vector<int>a(n);
        for(auto & x:a)cin>>x;

        cout<<solve(a,x)<<endl;
        
    }
    return 0;
}