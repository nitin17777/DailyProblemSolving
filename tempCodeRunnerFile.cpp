#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr)
{
    int n = arr.size();
    sort(arr.begin(),arr.end());

    int mini = INT_MAX;

    for(int i=1;i<n;i++)
    {
        mini = min(mini,arr[i]- arr[i-1]);
    }
    vector<vector<int>>ans;

    for(int i =1;i<n;i++)
    {
        if(arr[i] - arr[i-1] == mini)
        {
            ans.push_back({arr[i-1],arr[i]});
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>arr = {4,2,1,3};
    vector<vector<int>>ans = minimumAbsDifference(arr);

    for(auto & an :ans)
    {
        for(auto &x: an)cout<<x<<" ";

        cout<<endl;
    }
    return 0;
}