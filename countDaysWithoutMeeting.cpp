#include<bits/stdc++.h>
using namespace std;

int countDays(int days,vector<vector<int>>&meetings)
{
    sort(meetings.begin(),meetings.end());


    vector<pair<int,int>>merged; //vector to store merged intervals



    int start = meetings[0][0];
    int end = meetings[0][1];


    for(int i = 1;i<meetings.size();i++)
    {
        if(meetings[i][0] <= end+1 )
    }

}







/*  TLE aara h is method se nade numbers ke liye
// we have to return the days when the employee is free to work




int countDays(int days, vector<vector<int>>& meetings)
{
    int n = meetings.size();



//creating busy array to mark busy day
    vector<bool>busy(days+1,false); //true means day is occupied by meeting
    //bool->(size of vector, intial assignment)


    //marking all days with meetings as busy
    for(auto meeting : meetings) // iterating through each meeting in meetings 
    {

        //meeting refer to that array in meetings like (2,5)
        int start = meeting[0]; //get the starting day of meeting 
        int end = meeting[1];//get the ending day of meeting

        //Marking all days between start and end as true(busy)
        for(int i = start; i<=end; i++)
        {
            busy[i] = true;
        }
    }

    //counting days when no meetings are scheduled
    int freeDays = 0;

    for(int i =1; i<=days; i++)
    {
        if(!busy[i])
        {
            freeDays++;

        }
    }
    return freeDays;
}
*/


int main()
{
    vector<vector<int>>arr ={{2, 5}, {7, 9}};
    int days =10;

    int ans = countDays(days,arr);

    cout<<"No. of days without meeting: "<<ans<<endl;
    return 0;

}