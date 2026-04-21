#include<bits/stdc++.h>
#define ll long long
using namespace std;


vector<vector<int>> groupThePeople(vector<int>& gs)
{

    int n = gs.size();

    //gs[1] = 3 -> Person 1 must be in group of size 3

    //Returnn a list of groups such that each person i is in a group of size gs[i]

}


      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>gs = {3,3,3,3,3,1,3};
    vector<vector<int>>ans = groupThePeople(gs);

    for(auto an :ans)
    {
        for(auto& x:an)cout<<x<<" ";


        cout<<endl;
    }

    return 0;
}