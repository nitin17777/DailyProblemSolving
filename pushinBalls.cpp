#include <bits/stdc++.h>
using namespace std;

bool solve(vector<string>&a)
{
    int n= a.size(),m = a[0].size();

    //Each time he can push a ball either from the leftmost edge of a particular row or topmost edge of particular column of the grid

    //Solution: A ball cannot appear with an empty left and empty top

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            if(a[i][j] == '1')
            {

                bool zerol = false,zerou = false;

                //Check left of this cell
                for(int k = 0;k<j;k++)
                {
                    if(a[i][k] == '0')zerol = true;
                }

                //Check above this cell
                for(int k = 0;k<i;k++)
                {
                    if(a[k][j] == '0')zerou = true;
                }

                if(zerol && zerou)return false;
            }
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        vector<string>a(n);
        for(int i = 0;i<n;i++)
        {
            cin>>a[i];
        }
        cout<<(solve(a)? "Yes":"No")<<endl;
    }
    return 0;
}