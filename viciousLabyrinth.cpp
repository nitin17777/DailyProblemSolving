#include<bits/stdc++.h>
using namespace std;

vector<int>solve(int n,int k)
{
    //Cell i is i away from the exit, and cell n is the exit


    //Everyone must use teleporter exactly k times

    //No teleporter can lead to the same cell it is in

    //Teleporter in cell i can translocate the person to cell ai


    //Find the config such that it minimises the distance of very one from the exit

    vector<int>ans(n);

    if(k%2 == 0)//even k -> n-1 wala to n and rest other to n-1
    {
        fill(ans.begin(),ans.end(),n-1);
        ans[n-2] = n;
    }

    //When k is odd
    else
    {
        fill(ans.begin(),ans.end(),n);
        ans[n-1] = n-1;
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;

        vector<int>ans = solve(n,k);
        for(auto & x:ans)cout<<x<<" ";

        cout<<endl;

        
    }
    return 0;
}