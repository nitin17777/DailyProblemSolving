#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> findMissingElements(vector<int>& a)
{
    int n = a.size();

    sort(a.begin(),a.end());
    vector<int>ans;

    int curr = a[0];

    int i =1;

    while(i<n)
    {
        if(a[i]!=curr+1)ans.push_back(curr+1);
        else i++;

        curr++;
    }
    return ans;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a = {1,4,2,5};
    
    vector<int>ans = findMissingElements(a);
    for(auto& x:ans)cout<<x<<" ";
    cout<<endl;

    return 0;
}