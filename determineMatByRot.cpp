#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>&m)
{
    int n = m.size();


    //Transpose
    for(int i = 0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            swap(m[i][j] , m[j][i]);
        }
    }

    //Reverse each row
    for(int i =0 ;i<n;i++)
    {
        reverse(m[i].begin(),m[i].end());
    }
}

bool findRotation(vector<vector<int>>& m, vector<vector<int>>& t)
{

    int n = m.size();

    //Detemrine if we can obtain t by 90 degree rotations or not

    //IF top row is equal to any of the adjacent walls then true else false

    for(int i = 0;i<4;i++)
    {
        if(m == t)return true;

        rotate(m);
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>m = {{0,1},{1,0}}, t = {{1,0},{0,1}};

    cout<<(findRotation(m,t)?"True":"False")<<endl;
    return 0;
}