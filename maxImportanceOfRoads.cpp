#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll maximumImportance(int n, vector<vector<int>>& roads)
{
    /*
    r[i] = a[i],b[i] : Denotes the bidirectional road connecting cities ai and bi


    Return the max total importance of all roads possible


    Sort in the order of highest elements in adjacency matrix of each element,Assign the numbers accordingly and then for every connected road, find the importance
    */

    vector<int>cnt(n);

    //Counting degree of each city
    for(auto &road : roads)
    {
        cnt[road[0]]++;
        cnt[road[1]]++;
    }

    //Now we have to how many components the given component is connected to.

    //MAx heap : Degree, that city
    priority_queue<pair<int,int>>pq;
    for(int i =0;i<n;i++)
    {
        pq.push({cnt[i], i});
    }

    vector<int>distri(n);

    int temp = n;
    while(!pq.empty())
    {
        auto[a,idx] = pq.top();
        pq.pop();

        distri[idx] = temp--;
    }

    ll ans = 0;
    for(auto & road:roads)
    {
        ans += distri[road[0]] + distri[road[1]];
    }
    return ans;
}


//Another cleaner approach: 
ll maximumImportance2(int n, vector<vector<int>>& roads)
{
    vector<int>deg(n,0);

    for(auto &r : roads)
    {
        deg[r[0]]++;
        deg[r[1]]++;
    }

    // Assigning highest degree city the highest val to maximise 
    sort(deg.begin(),deg.end());

    ll ans = 0;

    for(int i = 0;i <n;i++)
    {
        ans += 1LL * deg[i] * (i+1);
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(false);
    

    vector<vector<int>>r = {{0,1},{1,2},{2,3},{0,2},{1,3},{2,4}};
    cout<<maximumImportance2(5,r)<<endl;

    return 0;
}