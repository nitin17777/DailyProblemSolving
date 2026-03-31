#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&a)
{
    int n = a.size();

    /*

    We can do :
                if ith chair is marked, end the game 
                Otherwise sit on the chair or skip it and move to the next chair
                If decide to sit on the chair, then after standing mark that chair visited and move to the next

                Determine the max numbers of chairs we can sit on
    */

    //Start from the first chair
    //We need to delay the time by which we will be facing the already visited chair


    int cnt = 0;

    for(int i =0 ;i<n;i++)
    {
        if(a[i] <= i+1)cnt++;
    }
    return cnt;
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
        cout<<solve(a)<<endl;
        
    }
    return 0;
}