#include<bits/stdc++.h>
#define ll long long
using namespace std;

int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats)
{
    //rs[i] = [rowi, seati] -> seati in rowi is reserved


    //A 4 person group must be assigned to four seats in the same row
    //a block can be used if noone of it's seats are reserved

    //return how many 4 person groups can be assigned
    
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>rs = {{1,2},{1,3},{1,8},{2,6},{3,1},{3,10}};
    cout<<maxNumberOfFamilies(3,rs)<<endl;

    return 0;
}