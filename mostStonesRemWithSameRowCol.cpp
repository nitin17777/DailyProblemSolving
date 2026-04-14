#include<bits/stdc++.h>
#define ll long long
using namespace std;


//Didn't understood much
unordered_map<int,int>parent;

//Find parent of node with path compression
int find(int x)
{
    if(!parent.count(x))parent[x] = x;

    if(parent[x] == x)return x;

    return parent[x] = find(parent[x]);
}


//Uniting same nodes into same components
void unite(int x,int y)
{
    int px = find(x);
    int py = find(y);

    //Merge only if they belong to different comps

    if(px != py)
    {
        parent[px] = py;
    }
}

int removeStones(vector<vector<int>>& stones)
{
    parent.clear();

    for(auto & stone :stones)
    {
        int row = stone[0];
        int col = stone[1] + 10001;//to separate row and column
        unite(row,col);
    }
    //A stone can be removed if it share same row or col with the unremoved stone


    //Return the most possible number of stones that can be removed


    //For each component remove the stone until only 1 stone is left in that component

    //ans = size of given stone array - total comps present

    unordered_set<int>comps;

    //Counting unique connected components
    for(auto & stone: stones)
    {
        comps.insert(find(stone[0]));
    }

    return stones.size() - comps.size();

}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>s = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout<<removeStones(s)<<endl;
    return 0;
}