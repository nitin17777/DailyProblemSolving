#include<bits/stdc++.h>
using namespace std;

// function to check if we can repair all cars withing given time
bool canRepair(vector<int> & ranks ,int cars , long long time)
{
    int repaired = 0;

    for(int rank : ranks)  // iterating over each mechanic
    {
        long long n = sqrt(time/rank); // this is the max number of cars this mechanic can repair withing given time

        repaired += n;

        if(repaired >= cars)
        return true;
    }
    return false; // in case we can't repair all cars in time
}


// actual function to find minimum time to repair all cars
int minRepairTime(vector<int>& ranks, int cars)
{
    long long left = 1; // minimum possible time will be 1 minute

    long long right = (long long)*min_element(ranks.begin(), ranks.end()) * (long long)cars * cars;

    while(left<right)
    {
        long long mid = right + (right - left) / 2;

        if(canRepair(ranks, cars, mid))
        {
            right = mid;
        }
        else
        {
            left = mid +1;
        }
    }
    return left;
}

int main()
{
    vector<int> ranks = {4,5,7};
    int cars = 10;

    cout<<"Minimum Repair Time: "<<minRepairTime(ranks,cars) <<endl;
    
    return 0;
}