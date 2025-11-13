#include <bits/stdc++.h>
using namespace std;

int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
{
    // price[i] = price of ith item
    // needs[i] = need of pieces i wants to buy

    // special[i][j] = number of piece of j item in ith offer and special[i][n] = price of the ith offer

    // we have to return the lowest price we have to pay for exaclty certain items as given
}

int main()
{
    vector<int> price = {2, 5};
    vector<vector<int>> special = {{3, 0, 5}, {1, 2, 10}};
    vector<int> needs = {3, 2};

    cout << shoppingOffers(price, special, needs) << endl;

    return 0;
}
