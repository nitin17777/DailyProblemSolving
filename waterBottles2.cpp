#include <iostream>
#include <vector>

using namespace std;

int maxBottlesDrunk(int numBottles, int numExchange)
{
    // drink numExchange full water bottles and exchange those with one full water bottle,and
    // when done then increase numExchange by one

    // return max bottles you can drink

    int drunk = 0, empty = 0;

    while (numBottles > 0) // until full bottles = 0 && emptyBottles < numExchange7
    {

        // drink full bottles -> they become empty->exchange as per numExchange->then again we will get a full bottle ->drink it->and add that drunk bottle to empty and drunk

        drunk += numBottles;
        empty += numBottles;
        numBottles = 0;

        // exchange as long as empty bottles > numExchange
        if (empty >= numExchange) //
        {
            empty -= numExchange;
            numExchange++;

            numBottles++; // since 1 more bottle added
        }
        else
        {
            break;
        }
    }
    return drunk;
}

int main()
{
    cout << maxBottlesDrunk(13, 6) << endl;

    return 0;
}
