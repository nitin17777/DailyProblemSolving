#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
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
        for(auto & y:a)cin>>y;

        int last = a.back()+ 2*(x-a.back());
        a.push_back(last);

        //0 to x and x to 0

        //Determine min tank capacity that would allow the travel

       
        int ans = a[0];

        for(int i = 1;i<a.size();i++)
        {
            ans = max(ans,a[i] - a[i-1]);
        }
        cout<< ans<<'\n';
    }

    return 0;
}