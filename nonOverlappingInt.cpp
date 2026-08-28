#include<bits/stdc++.h>
#define ll long long
using namespace std;

int eraseOverlapIntervals(vector<vector<int>>& intervals)
{
    //intervals[i] = {starti, endi}

    //Return the min number of intervals to be removed to make the intervals non overalapping


    //sorting based on the ending time of each inteval
    sort(intervals.begin(),intervals.end(),[](auto&a,auto&b)
    {
        return a[1]<b[1];  
    });

    int cnt = 0;
    int lastEnd = intervals[0][1];

    for(int i = 1;i<intervals.size();i++)
    {
        if(intervals[i][0] < lastEnd)cnt++;

        else lastEnd = intervals[i][1];
    }
    return cnt;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>intervals = {{1,2},{2,3},{3,4},{1,3}};

    cout<<eraseOverlapIntervals(intervals)<<endl;

    return 0;
}