#include<bits/stdc++.h>
using namespace std;


const int N=1000010;
int T,n;
int a[N],b[N];

void init()
{
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
}

void solve()
{
    /*
    select subset s' such that f(s') - g(s') is maximized

    If segment [a[i],b[i]] is inside [a[j],b[j]],it will not add any length but may create cycles in the graph thus increasing g(s)

    */

    vector<int>tag(n+4,1),ans;

    // tag[i] = 1 => We keep segment i intitially
    //tag[i] = 0 => segment i is contained inside another and should be removed

    for(int i =1;i<=n;i++)
    {
        for(int j =1;j<=n;j++)
        {
            if(i==j)continue;


            if(a[j] <= a[i] && b[i] <= b[j])tag[i]=0;
        }
        if(tag[i])ans.push_back(i);
    }

    cout<<ans.size()<<endl;

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i] << (i+1 ==ans.size()? "\n": " ");
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>T;
    while(T--)
    {
        init();
        solve();
    }
    return 0; 
}
