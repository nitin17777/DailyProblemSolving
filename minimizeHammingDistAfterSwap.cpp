#include<bits/stdc++.h>
#define ll long long
using namespace std;

//Find the ultimate parent of node(path compression)
int findParent(int x,vector<int>& parent)
{
    //if node is it's own parent ->it's root
    if(parent[x] == x)return x;

    return parent[x] = findParent(parent[x],parent);
}


//Uniting two nodes now
void unite(int a,int b,vector<int>&parent,vector<int>&size)
{
    a = findParent(a,parent);
    b = findParent(b,parent);


    //Merging if different groups
    if(a!=b)
    {
        //Making sure that bigger component becomes parent
        if(size[a] < size[b])swap(a,b);

        parent[b] = a; //attaching b under a
    
        size[a] += size[b];
    }
}

int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& as)
{
    int n = source.size();

    /*

    as[i] = [ai,bi] -> swap elements at index ai and bi of source array


    Hamming distance  =  Number of postions wjhere elements are different

    Return the min hamming distance of source and target after performing any amount of swaps on source array

    
    */

    //size[i] = number of noes in component whose parent is i

   vector<int>parent(n),size(n,1);

   //Initially every node is it's own parent
   for(int i = 0;i<n;i++)parent[i] = i;

   //Build connected components using allowed swaps
   //And if we can swap i and j -> they belong to same component

   for(auto & e: as)
   {
        unite(e[0],e[1],parent,size);
   }


   //Now grouping indices by their component parent
   //and each group represents indices where we can freely rearrange values
   unordered_map<int,vector<int>>groups;
   for(int i = 0;i<n;i++)
   {

        //Now putting all indices with same parent together
        int p = findParent(i,parent);
        groups[p].push_back(i);
   }


   int ans = 0;

   //now processing each group independently
   for(auto & g :groups)
   {

        //freq tells how many times each vlaue appears in source
        unordered_map<int,int>freq;

        //Count all source values in this component
        for(int idx: g.second)
        {
            freq[source[idx]]++;
        }

        for(int idx: g.second)
        {

            //if value exists in source component->match it
            if(freq[target[idx]] > 0)
            {
                freq[target[idx]]--;
            }
            else ans++;
        }
   }
   return ans; 
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>s = {1,2,3,4},t = {2,1,4,5};

    vector<vector<int>>as = {{0,1},{2,3}};
    cout<<minimumHammingDistance(s,t,as)<<endl;

    return 0;
}