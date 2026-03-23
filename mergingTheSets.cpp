#include<bits/stdc++.h>
using namespace std;

bool solve(int n, int m,vector<vector<int>>&v)
{

    //We have to choose sets such that every integer between 1 and m is included in atleast one the chosen set



    //We have to determine if ther exists atleast 3 ways to choose the sets


    /*
    Firstly check if selecting all the sets cover all numbers from 1 to m or not , if not, return NO

    Then for every set : Go and ask can i remove this set, if more than equal to sets can be removed return yes else no
    
    */

    // cnt[x] = number of sets that contain element x
    vector<int>cnt(m,0);

    //Number of distinct elemnents covered currently
    int t = 0;

    for(int i = 0;i<n;i++)
    {
        for(int x : v[i])
        {
            if(cnt[x] == 0)t++; //As x is newly covered
            cnt[x]++;
        }
    }

    int ans = (t==m)?1:0;


    //Now try skipping each set i and check if remaining sets still cover all the elements
    for(int i = 0;i<n;i++)
    {

        //Temporarily removing set i from coverage
        for(int x:v[i])
        {
            cnt[x]--;

            if(cnt[x] == 0)t--; //Means x is no longer covered by any set
        }

        if(t==m)ans++;


        //restore set i back now
        for(int x:v[i])
        {
            if(cnt[x] == 0)t++;
            cnt[x]++;
        }

        if(ans>=3)break;
    }
    return ans>=3;
}

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

        vector<vector<int>>v(n);
        for(int i = 0;i<n;i++)
        {
            int l;
            cin>>l;

            for(int j = 0;j<l;j++)
            {
                int x;
                cin>>x;
                x--;
                v[i].push_back(x);
            }
        }
        cout<<(solve(n,m,v)?"Yes":"No")<<endl;
    }
    return 0;
}