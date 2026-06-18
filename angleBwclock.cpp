#include<bits/stdc++.h>
#define ll long long
using namespace std;

double angleClock(int hour, int minutes)
{
    hour%=12;

    //Minute hand moves 5 degree every minute
    double minuteAngle = minutes*6.0;

    //And it moves 30 degree each hour and 0.5 degree each minutes
    double hourAngle = hour*30.0 + minutes*0.5;

    double diff = abs(hourAngle-minuteAngle);

    return min(diff,360.0-diff);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<angleClock(12,30)<<'\n';

    return 0;
}