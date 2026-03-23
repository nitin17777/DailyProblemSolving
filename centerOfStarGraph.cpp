#include<bits/stdc++.h>
using namespace std;

int findCenter(vector<vector<int>>& e)
{
    //Just the find the component whcih is connected to all other components as well

    //But just seeing two components would be sufficient

    int a = e[0][0];
    int b = e[0][1];
    int c = e[1][0];
    int d = e[1][1];

    if(a==c || a==d)return a;

    return b;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>g = {{1,2},{2,4},{4,2}};
    cout<<findCenter(g)<<endl;

    return 0;
}//