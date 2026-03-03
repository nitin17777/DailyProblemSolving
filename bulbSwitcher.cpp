#include<bits/stdc++.h>
using namespace std;

int bulbSwitch(int n)
{
    //Return the number of bulbs that are on after n rounds

    //First turn on all the bulbs, and then turn off every secodn bulb


    //Turn off every 2i bulb ,and in third round toggle every bulb

    // Count multiple of 2 and 3, then subtract total multiples of 6 from it 

    return sqrt(n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<bulbSwitch(3)<<endl;

    return 0;
}