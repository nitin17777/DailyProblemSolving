#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<pair<int,int>>solve(vector<int>a,int n)
{

    int mid = n/2;

    vector<pair<int,int>>ans;


    bool left = false, right = false;
    for(int i = 0;i<mid;i++)
    {
        if(a[i] == 0)left = true;
    }

    for(int i = mid;i<n;i++)
    {
        if(a[i] == 0)right = true;
    }

    int currN = n;

    if(right)
    {
        ans.push_back({mid+1,currN});
        currN = mid + 1;
    }

    if(left)
    {
        ans.push_back({1,mid});
        currN = currN - (mid-1);
    }

    ans.push_back({1,currN});

    return ans;

}


/*
vector<pair<int,int>>solve(vector<int>a,int n)
{

    /*

    Do the following operations on a until it's length becomes 1

    Replace [al,....ar] with MEX(al,....ar)

    And after that length of a will decrease by r-l


    Find the sequence of ops such that final remaining after ops is 0 
    
    

    //We just need to make every occurence 0 disapppear from the array

    //whenever we will encounter 0 -> combine it with next element dosn;t matter what is there



    //cover all zeroes in one subarray of at max size = n - 2

    int fs = 0,ls = n-1;

    for(int i = 0;i<n;i++)
    {
        if(a[i] == 0)
        {
            fs = i;
            break;
        }
    }

    for(int i=n-1;i>=0;i--)
    {
        if(a[i] == 0)
        {
            ls= i;
            break;
        }
    }

    vector<pair<int,int>>ans;

    ans.push_back({fs+1,ls+1});

    if(fs-0 > 0)
    {
        ans.push_back({1,fs+1});
    }

    if(ls<n-1)
    {
        ans.push_back({ls+1,n});
    }
    return ans;

}*/

      
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

        vector<pair<int,int>>ans = solve(a,n);

        cout<<ans.size()<<endl;

        for(auto & x:ans)
        {
            cout<<x.first << " " << x.second <<endl;
        }    
    }

    return 0;
}