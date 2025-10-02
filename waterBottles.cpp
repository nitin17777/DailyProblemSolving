#include <iostream>
#include <vector>

using namespace std;

int numWaterBottles(int numBottles, int numExchange)
{
    // numBottle are initially full of water
    // we can exchange numExchange empty water bottles from market with one fulll water bottle

    // return the max number of bottles you can drink

    int total = 0;
    int empty = 0;
    while (numBottles)
    {
        total += numBottles; // Drink all current full bottles
        empty += numBottles; // now bottle remaining after drinking

        numBottles = empty / numExchange; // bottles we will get to drink in exchange

        empty = empty % numExchange;
    }
    return total;
}

int main()
{

    cout << numWaterBottles(9, 3);

    return 0;
}
