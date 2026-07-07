#include<bits/stdc++.h>
#define ll long long
using namespace std;



int removeCoveredIntervals(vector<vector<int>>& inte)
{
    sort(inte.begin(),inte.end(),[](vector<int>&a,vector<int>&b)
    {
        if(a[0] == b[0])return a[1]>b[1];

        return a[0] < b[0];
    }
    );

    //since first interval is gauranteed to stay after sorting,even among equal endpoints

    int ans = 1;
    int maxR = inte[0][1];

    for(int i = 1;i<inte.size();i++)
    {
        //For not covered
        if(inte[i][1] > maxR)
        {
            ans++;
            maxR = inte[i][1];
        }
    }
    return ans;
}

//BRUTE FORCE APPROACH
int removeCoveredIntervals2(vector<vector<int>>& inte)
{
    int n = inte.size();

    int cnt = 0;
    for(int i = 0;i<n;i++)
    {
        bool isCov = false;
        for (int j = 0;j<n;j++)
        {
            if(i==j)continue;

            
            int x1 = inte[i][0];
            int y1 = inte[i][1];

            int x2 = inte[j][0];
            int y2 = inte[j][1];

            if(x1 >= x2 && y1 <= y2 )
            {
                isCov = true;
                break;
            }
        }
        if(isCov)cnt++;
    }
    return n-cnt;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>inte = {{1,4},{3,6},{2,8}};
    cout<<removeCoveredIntervals(inte)<<'\n';

    return 0;
}

// 1 2 3 4 
//     3 4 5 6
//   2 3 4 5 6 7 8