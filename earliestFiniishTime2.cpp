#include<bits/stdc++.h>
#define ll long long
using namespace std;


int solve(vector<int>& start1, vector<int>& duration1, vector<int>& start2,vector<int>& duration2)
{

    int f1 = INT_MAX;
    for(int i =0;i<start1.size();i++)
    {
        f1 = min(f1,start1[i] + duration1[i]);
    }

    int f2 = INT_MAX;
    for(int i = 0;i<start2.size();i++)
    {
        f2 = min(f2,max(start2[i],f1) + duration2[i]);
    }
    return f2;
}

int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration)
{
    /*

    A tourist must experience exactly one ride from each category
    Ride finishes at : t + duration time and can board another ride immediately after that

    Return the earliest possible time at which tourist can finish both 
    

    Ride should start early and finish early : sort by start time first

    */

    int lw = solve(landStartTime, landDuration, waterStartTime, waterDuration);
    int wl = solve(waterStartTime, waterDuration, landStartTime, landDuration);


    return min(wl,lw);
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>lst = {2,8}, ld = {4,1}, wst = {6},wd = {3};

    cout<<earliestFinishTime(lst,ld,wst,wd)<<endl;

    return 0;
}