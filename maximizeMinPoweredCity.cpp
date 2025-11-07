#include <iostream>
#include <vector>

using namespace std;

bool can(int x, vector<int> &stations, int r, int k)
{
    int n = stations.size();

    // Calculating intitial power of each city using sliding window
    vector<int> power(n, 0);

    int windowSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (i + r < n)
            windowSum += stations[i + r];

        if (i - r - 1 >= 0)
            windowSum -= stations[i - r - 1];

        power[i] = windowSum;
    }
}

long long maxPower(vector<int> &stations, int r, int k)
{
    // we have to return the max possible min power of city, if additional power stations are built

    // if range is r: power station at city i can provide power to all cities j such that mod(i,j) <= r
}

int main()
{
    vector<int> stations = {1, 2, 4, 5, 8};
    cout << maxPower(stations, 1, 2) << endl;

    return 0;
}
