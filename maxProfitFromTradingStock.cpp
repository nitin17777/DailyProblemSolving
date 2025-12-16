#include <bits/stdc++.h>
using namespace std;

int maxProfit(int n, vector<int> &present, vector<int> &future, vector<vector<int>> &hierarchy, int budget)
{
    /*
    Each employee is assigned a uid from 1 to n and employee 1 is the CEO
    present[i] = current price at which ith employee can buy a stock today

    future[i] = Expected price at which ith employee cnan sell the stock tomorrow

    heirarchy[i] = [ui,vi] -> Employee ui is the direct boss of vi

    budget = total available funds

    //Policy ->IF an employee's direct boss purchases their own stock , then employee can buy their stock at half the origianl price


    Return the max profit that can be achieved without exeeding the given budget

    //////////////////////////////////

    profit[i] = future[i] - present[i]

    And present[i] depends upon whether their boss bought or not


    Didn't bought -> present[i]
    Bought -> present[i] / 2
    */

    vector <
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> present = {1, 2}, future = {4, 3};

    vector < vector<int> h = {{1, 2}};

    cout << maxProfit(2, present, future, h, 3) << endl;

    return 0;
}