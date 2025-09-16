#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


//comparator function to sort meetings by their ending time(ascending order)
bool cmp(pair<int,int>a, pair<int,int>b)
{
    return a.second < b.second; // sorting based on meetings and time 
}

int maxMeetings(vector<int>start,vector<int>end, int n)
{
    vector<pair<int,int>>v; // for storing starting and ending time of each meeting

    for(int i =0;i <n; i++)
    {
        pair<int,int>p = make_pair(start[i], end[i]);//creating pair of start and end time of each meeting
        v.push_back(p);//now pushing these pairs in vector
    }

    //soritng meetings based ont their ending times
    sort(v.begin(),v.end(),cmp);

    int count = 1;

    int ansEnd = v[0]. second; // ending time for first meeting

    for(int i = 1; i < n ; i++)
    {
        if(v[i].first > ansEnd)
        {
            count++;
            ansEnd = v[i].second;
        }
    }
    return count;
}

int main()
{
    vector<int>start = {1,3,0,5,8,5};
    vector<int>end = {2,4,6,7,9,9};
    int n = 6;

    int ans = maxMeetings(start,end,n);
    cout<<ans<<endl;

    return 0;

}