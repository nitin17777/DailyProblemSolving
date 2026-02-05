#include<bits/stdc++.h>
using namespace std;

int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
{

    //Return the max profit we can achieve after assigning the workerts to the job
    int ans=0;

    //
    for(int i = 0;i < worker.size();i++)
    {
        int j=0;
        while(difficulty[j] < worker[i])j++;

        
        ans+=profit[j];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>dif = {2,4,6,8,10};
    vector<int>profit = {10,20,30,40,50};
    vector<int>work = {4,5,6,7};
    cout<<maxProfitAssignment(dif,profit,work)<<endl;

    return 0;
}