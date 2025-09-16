#include<bits/stdc++.h>

using namespace std;


bool isValidDivision(int s1,int s2,int s3)
{
    if(s1 == s2 && s2 == s3)
    {
        return true;
    }

    set<int>uniqueValues = {s1,s2,s3};
    if(uniqueValues.size()==3)
    {
        return true;

    }

    return false;
}


pair<int,int>solve(vector<int>&arr)
{
    //we need to choose two intgers l and r such that they divide an array into three non empty parts such that sum of each part modulo 3 is either same or different

    //since we are working with mod 3 so only possible remainders can be 0,1,2

    int n = arr.size();

    if(n <3)
    {
        return {-1,-1};
    }

    //building prefix sum
    vector<long long>prefix(n+1,0);

    for(int i = 0;i < n;i++)
    {
        prefix[i+1] = prefix[i] + arr[i];
    }

    for(int l = 1; l<=n-2; l++)
    {
        for(int r = l+1; r<=n-1; r++)
        {
            int s1 = prefix[l] %3;
            int s2 = (prefix[r] - prefix[l])%3;
            int s3 = (prefix[n] - prefix[r])%3;


            s2 = (s2 + 3)%3;
            s3 = (s3 + 3)%3;


            if(isValidDivision(s1,s2,s3))
            {
                return {l,r};
            }
            
        }
    }
    return {0,0};
}

int main()
{

    int t;
    cin>>t;
    while(t--)
    {

    int n;
    cin>>n;

    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    pair<int,int>ans= solve(arr);

    cout<<ans.first<<" "<<ans.second<<endl;
    }

    cout<<endl;

    return 0; 
}
