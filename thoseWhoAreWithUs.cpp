#include<iostream>
#include<vector>

using namespace std;

int maxValue(vector<vector<int>>&a,int m , int n)
{
    //cell at intersection of i and jth column contains number aij
    //we are given a matrix and if  i==r or j==c decrease the value at a[i][j] and by doing this operation find the min possible value


    for(int i = 0; i<m.size())

}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>>a;

        for(int i = 0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
    }
    return 0;
}
