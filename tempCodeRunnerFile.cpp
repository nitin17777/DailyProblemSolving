#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll minCost(vector<ll> &a)
{
    /*

    Choose a position i and make all elements to left of i equal to ai and cost = (i-1) * ai

    Choose a position i and make all elements to right of i equal to ai and cost = (n−i) * ai

    What would be the minimum total cost to make all elements of array equal


    We are checking if we make the whole array equal to this number x how costly will it be  and then picking the cheapest option at the end

    */

    int n = a.size();

    ll ans = LLONG_MAX;

    int i = 0;
    while (i < n)
    {