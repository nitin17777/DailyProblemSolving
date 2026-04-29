#include<bits/stdc++.h>
#define ll long long
using namespace std;


vector<int>parent;


//Find leader of the set
int find(int x)
{
    if(parent[x] != x)parent[x] = find(parent[x]);

    return parent[x];   
}

//to make two sets part of same group -> Merge
void unite(int x,int y)
{
    parent[find(x)] = find(y);
}


bool equationsPossible(vector<string>& equations)
{
    parent.resize(26);
    for(int i=0 ; i<26;i++)parent[i] = i;

    //processing "==" equations
    for(auto& eq:equations)
    {
        if(eq[1] == '=')
        {
            int x = eq[0] - 'a';
            int y = eq[3] - 'a';

            unite(x,y);
        }
    }

    //now processing !=  equations

    for(auto & eq:equations)
    {
        if(eq[1] == '!')
        {
            int x = eq[0]-'a';
            int y = eq[3]-'a';

            if(find(x) == find(y))return false;
        }
    }
    //no conflicts found
    return true;
}
    



      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string>eq = {"a==b","b!=a"};
    cout<<(equationsPossible(eq)?"True":"False")<<endl;

    return 0;
}