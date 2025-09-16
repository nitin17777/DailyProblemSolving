#include<bits/stdc++.h>
using namespace std;

//Returns shortes distance from src to all other vertices
vector<int>dijkstra(vector<vector<int>>&vec, int vertices, int edges, int source)
{

    //Creating adjanecy list
    unordered_map<int,list<pair<int,int>>>adj;

    for(int i = 0; i< vertices;i++)
    {
        int u =  vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //Creation of distance array woth infinite value initially
    vector<int>dist(vertices);
    for(int i = 0 ;i<vertices;i++)
    {
        dist[i] = INT_MAX;
    }

    //creation of set on basis of (distance,node)
    set<pair<int,int>>st;

    //initiallise distance and set with source node
    dist[source]=0;


    st.insert(make_pair(0,source));

    while(!st.empty())
    {
        //Fetch top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        //Remove top record now
        st.erase(st.begin());


        //Traverse on neighbours
        for(auto neighbour : adj[topNode])
        {
            if(nodeDistance + neighbour.second < dist[neighbour.first])
            {
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));

                //IF record found then erase it
                if(record != st.end())
                {
                    st.erase(record);
                }

                //Distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;
                st.insert(make_pair(dist[neighbour.first] , neighbour.first));


            }
        }

    }
    return dist;

}

int main()
{
    return 0;
    
}
