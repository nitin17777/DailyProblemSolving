#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int maxEvents(vector<vector<int>>events)
{
    //we are given: events[i] = [startDayi, endDayi],and you can attend one event at a time only , now we have to return the max number of events that we can attend

    //1->sort all events by start day
    sort(events.begin(),events.end());

    //2-> Use min heap to store end days of availabe events
    priority_queue<int,vector<int>,greater<int>>minHeap;
    int i = 0;
    int day = 1; //current day
    int res = 0; // number of events that we can attend


    int maxDay = 0;
    for(auto & e: events)
    {
        
    }






    //3->Then iterate day by day from earliest to the latest possible day


    


}

int main()
{

    vector<vector<int>>events = {
        {1,2},{2,3},{3,4}
    };

    int ans = maxEvents(events);

    cout<<ans<<endl;

    return 0;
    
}
