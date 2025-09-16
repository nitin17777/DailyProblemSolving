#include<iostream>
#include<vector>

using namespace std;

struct Job
{
    int id;
    int dead;
    int profit; 
};

class Solution
{
    public:

    bool cmp(Job a,Job b)
    {
        return a.profit > b.profit;
    }

    
    vector<int>jobSchedule(vector<int>arr,int n)
    {

        sort(arr, arr+n, cmp);

        int maxDeadline = INT_MIN;

        for(int i = 0;i <n; i++)
        {
            maxiDeadLine = max(maxiDeadline,arr[i].dead);
        }

        vector<int>schedule(maxiDeadline + 1, -1);


        int count = 0;
        int maxProfit = 0;

        for(int i=0; i<n;i++)
        {
            int currProfit = arr[i].profit;

            int currJobID = arr[i].dead;

            for(int k = currDead; k< 0; k--)

            {
                if(schedule[k] == -1)
                {
                    count++;

                    maxprofit +=currProfit;
                    schedule[k] = currJobID;
                    break;

                }
            }
        }


    }
};

int main()
{
    return 0;

}