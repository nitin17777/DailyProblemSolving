#include<bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>>& graph)
{

    int m = graph.size(),n = graph[0].size();

    //Return the array containing all the safe nodes of the graph 


}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    
    vector<vector<int>>g = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int>ans = eventualSafeNodes(g);
    for(auto& x:ans)cout<<x<<" ";

    cout<<endl;

    return 0;
}