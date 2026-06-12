#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()

using namespace std;


vector<int>solve(vector<int>&a,int n)
{

    vector<int>ans;

    /*Remove a[j], now check if remaining array is good or not

    now remaining sum = totalSum - a[j]

    now : x = totalSum - x; => there must be some x : x = remainingSum / 2;

    so if remainingSum is odd -> no that index 
    */

    ll sum = 0 ;
    for(auto&x:a)sum+=x;

    unordered_map<ll,int>cnt;
    for(auto&x:a)cnt[x]++;


    for(int i = 0;i<n;i++)
    {
        sum-=a[i];
        cnt[a[i]]--;

        if(sum%2==0)
        {
            ll target = sum/2;

            if(cnt[target] > 0)ans.push_back(i+1);
        }

        sum+=a[i];
        cnt[a[i]]++;
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    
    vector<int>a(n);
    for(auto&x:a)cin>>x;

    vector<int>ans = solve(a,n);

    if(ans.empty())
    {
        cout<<0<<endl;
    }
    else
    {
        cout<<ans.size()<<endl;
        for(auto& x:ans)cout<<x<<" ";
    }

    cout<<endl;

    return 0;
}