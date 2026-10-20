#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> targetIndices(vector<int>& a, int target)
{
    int n = a.size();

    sort(a.begin(),a.end());

    map<int,vector<int>>idx;

    for(int i = 0;i<n;i++)
    {
        idx[a[i]].push_back(i);
    }
    return idx[target];
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   vector<int>a = {1,2,5,2,3};
   vector<int>ans = targetIndices(a,2);;
   for(auto &x:ans)cout<<x<<" ";
   cout<<endl;


    return 0;
}