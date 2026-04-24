#include<bits/stdc++.h>
#define ll long long
using namespace std;

int furthestDistanceFromOrigin(string moves)
{

    vector<int>mov(3);
    int n = moves.size();


    for(auto & x:moves)
    {
        if(x=='L')mov[0]++;
        else if(x == 'R')mov[1]++;
        else mov[2]++;
    }

    char maxi = 'L';

    if(mov[0]<mov[1])maxi = 'R';


    int right = mov[1],left = mov[0];

    if(maxi == 'R')right+=mov[2];
    else left+=mov[2];


    return abs(right - left);
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<furthestDistanceFromOrigin("L_RL__R")<<endl;

    return 0;
}