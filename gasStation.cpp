#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    // gas[i] -> amount of gas at ith station

    // at each station i , we can refuel gas[i] amount

    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < gas.size(); i++)
    {
        int balance = gas[i] - cost[i]; // net fuel gained or lost at station i

        total += balance; // track overall feasibility

        tank += balance; // track current journey feasibility

        // if tank value gets negative , it means we can't reach station(i+1)
        if (tank < 0)
        {
            start = i + 1; // reset start to the next station
            tank = 0;      // and reset tank because we restart here
        }
    }
    return (total < 0) ? -1 : start;
}

int main()
{
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};

    cout << canCompleteCircuit(gas, cost) << endl;

    return 0;
}