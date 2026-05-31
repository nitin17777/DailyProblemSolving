#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool asteroidsDestroyed(int mass, vector<int>& ast)
{
    int n = ast.size();

    //Detemrine if all the asteroids can be destroyed


    //an asteroid can be destroyed if: it's mass is lesss than current mass of the planet
    

    //So accumulate all the nums less than mass first 

    ll m = mass;

    sort(ast.begin(),ast.end());

    int i = 0;
    while(i<n)
    {
        if(ast[i]<=m)
        {
            m+=ast[i];
            i++;
        }
        else return false;
    }
    return true;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>ast = {3,9,19,5,21};
    cout<<asteroidsDestroyed(10,ast)<<endl;

    return 0;
}