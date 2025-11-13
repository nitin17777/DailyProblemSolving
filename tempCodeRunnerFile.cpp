#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    //we have to insert the given interval in the existing interval
    int n = intervals.size();
    int m = intervals[0].size();

    //Compare the end of last interval with start of the new interval

    vector<vector<int>>ans;

    int open = newInterval[0],close = newInterval[1];

    for(auto curr : intervals)
    {
        if(curr[1] < open)
        {
            ans.push_back(curr);
        }

        else if(curr[0] > close)
        {
            ans.push_back(newInterval);
            newInterval = curr;
            
        }

        else
        {
            newInterval[0] = min(newInterval[0],curr[0]);
            newInterval[1] = max(newInterval[1],curr[1]);
            
        }
    }

    ans.push_back(newInterval);
    return ans;

}

int main()
{
    vector<vector<int>>intervals = {{1,3},{6,9}};
    vector<int>newInterval = {2,5};

    vector<vector<int>>ans = insert(intervals,newInterval);

    for(auto&an :ans)
    {
        for(auto&a : an)cout<<a<<" ";

        cout<<endl;
    }
    return 0;
    
}
