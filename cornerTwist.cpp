#include<bits/stdc++.h>
using namespace std;

// More cleaner approach
bool solve(vector<vector<int>>&a,vector<vector<int>>&b)
{

    //Determine if we can transform the grid a into b using these given operations any number of times

    int n = a.size(),m = a[0].size();

    /*
    
    Invariant :

    Allowed operations: 
    1 2       2 1
    2 1       1 2

    Total addition = 6 and 6%3 = 0

    Row sum modulo 3 and col sum modulo 3 remains unchanged

    */

    //Computing row and col sum modulo 3

    vector<int>rowA(n,0),rowB(n,0);
    vector<int>colA(m,0),colB(m,0);


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            rowA[i] = (rowA[i] + a[i][j])%3;
            rowB[i] = (rowB[i] + b[i][j])%3;

            colA[j] = (colA[j] + a[i][j])%3;
            colB[j] = (colB[j] + b[i][j])%3;
        }
    }

    //Checking row invariants
    for(int i = 0;i<n;i++)
    {
        if(rowA[i]  != rowB[i])
        {
            return false;
        }
    }

    // Check column invariants
    for(int j = 0; j < m; j++)
    {
        if(colA[j] != colB[j])
        {
            return false;
        }
    }
    return true;
}

/*
bool solve(vector<vector<int>>&a,vector<vector<int>>&b)
{

    //Determine if we can transform the grid a into b using these given operations any number of times

    int n = a.size(),m = a[0].size();


    for(int i = 0;i<n-1;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            int diff = (b[i][j] - a[i][j]+3 )%3;

            if(diff == 1)
            {
                //Use pattern {1 2 / 2 1}

                a[i][j] = (a[i][j] + 1)%3;
                a[i][j+1] = (a[i][j+1] + 2)% 3;
                a[i+1][j] = (a[i+1][j] +2)%3;
                a[i+1][j+1] = (a[i+1][j+1] + 1)%3;
            }

            else if(diff == 2)
            {
                //Apply operation 2 1 / 1 2
                a[i][j] = (a[i][j] + 2)%3;
                a[i][j+1] = (a[i][j+1] + 1)% 3;
                a[i+1][j] = (a[i+1][j] +1)%3;
                a[i+1][j+1] = (a[i+1][j+1] + 2)%3;
            }
        }
    }
    return a==b;
}*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        vector<vector<int>>a(n,vector<int>(m));
        for(int i = 0;i<n;i++)
        {
            string s; 
            cin>>s;

            for(int j=0;j<m;j++)
            {
                a[i][j] = s[j]-'0';
            }
        }

        vector<vector<int>>b(n,vector<int>(m));
        for(int i = 0;i<n;i++)
        {
            string s;
            cin>>s;

            for(int j=0;j<m;j++)
            {
                b[i][j] = s[j] - '0';
            }
        }

        cout<<(solve(a,b)?"Yes":"No")<<endl;
        
    }
    return 0;
}