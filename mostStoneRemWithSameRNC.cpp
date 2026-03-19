#include<bits/stdc++.h>
using namespace std;

unordered_map<int,int>parent;

int removeStones(vector<vector<int>>& stones)
{
    //A stone can be removed if it shares either the same row or col as another stone has not been removed

    //Return the largest possible number of stones can be removed

    

    int n = stones.size();
    


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>s = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout<<removeStones(s)<<endl;
    
    return 0;
}