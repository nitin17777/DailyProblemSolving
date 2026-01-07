#include<bits/stdc++.h>
using namespace std;

int minutes(string s)
{
    int hr = (s[0] - '0')*10 + (s[1]-'0');
    int mn = (s[3] - '0') * 10 + (s[4] -'0');


    if(hr == 0 && mn == 0)return 24* 60;

    int ans = hr*60 + mn;
}

int findMinDifference(vector<string>& timePoints)
{
    //Return the min minute diff bw any two points in the list


    //Just convert every element of string to minutes and form a new array

    vector<int>arr;
    for(auto& s:timePoints)
    {
        int m = minutes(s);
        arr.push_back(m);
    }

    int mini = INT_MAX;

    sort(arr.begin(),arr.end());


    for(int i =1;i<arr.size();i++)
    {
        int diff = arr[i] - arr[i-1];
        mini = min(mini,diff);
    }

    //circular difference case
    mini = min(mini,1440 - arr.back()+arr[0]);
    
    return mini;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string>t = {"23:59","00:00"};
    cout<<findMinDifference(t)<<endl;


    return 0;
}