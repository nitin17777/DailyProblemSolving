#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>>& g, int k)
{
    int m = g.size(),n=g[0].size();
    vector<vector<int>> temp = g;

    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            int newPosi = i;
            int newPosj = j+k;

            if(newPosj > n-1)
            {   
                newPosi += newPosj/n;
                newPosi%=m;

                newPosj%=n;
            }
            temp[newPosi][newPosj] = g[i][j];
        }
    }
    return temp;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>g = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>>ans = shiftGrid(g,1);

    for(auto&row:ans)
    {
        for(auto&x:row)cout<<x<<" ";

        cout<<endl;
    }

    cout<<endl;

    return 0;
}