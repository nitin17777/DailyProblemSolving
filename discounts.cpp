#include <bits/stdc++.h>
using namespace std;

int minCost(vector<long long> &prices, vector<long long> &vouchers)
{
    // buy product i individually paying ai coins
    // or use discount voucher to buy it as part of group purchase

    // we have k discount voucherswith values bi ....

    // voucher of value x allows us to select x products and pay only for the x- 1 most expnesive ones
    // each product can be included in at most one discount group

    // max total cost to purchase all n products
}

int main()
{
    vector<long long> prices = {18, 3, 7, 2, 9};
    vector<long long> vouchers = {3, 1, 1};

    int ans = minCost(prices, vouchers);

    return 0;
}
