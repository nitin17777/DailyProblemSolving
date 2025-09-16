#include<iostream>
#include<vector>

using namespace std;

bool isPossible(int X, int k, vector<int>& durations,int eventTime)
{
    int n = durations.size();
    int cnt = 0;
    int currentTime = 0;
    int maxGap = 0;

    for(int i = 0;i <n;i++)
    {
        if(currentTime <= eventTime - durations[i])
        {
            
        }
    }

}

int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime)
{
    //we have to maximise the longest free time interval during an event of duration eventTime

    //order of meetings should be same + no overlaps should be there + each meeting should be inside event duration

    int n = startTime.size(); // for number of meetings

    vector<int>durations(n); //for storing the duration of each event

    //calculating duration of each meeting
    for(int i = 0;i < n;i++)
    {
        durations[i] = endTime[i]- startTime[i];
    }

        int low = 0; // min possible free time
        int high = eventTime; // max possible free time
        int ans; 

        while(low <= high)
        {
            int mid = (high + low)/2;

            if(isPossible(mid,k,durations,eventTime))
            {
                ans= mid;
                low = mid+1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return ans;
}



int main()
{
    int eventTime = 5, k = 1;
    vector<int>startTime = {1,3};
    vector<int>endTime = {2,5};


    int ans = maxFreeTime(eventTime,k,startTime,endTime);

    cout<<ans<<endl;

    return 0;
    
}
