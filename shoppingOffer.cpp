#include<bits/stdc++.h>
using namespace std;

int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs)
{
    // special[i][j] = number of pieces of jth item in ith offer and special[i][n] = price of ith offer

    //Return the lowest price we have to pay
    

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>special = {{3,0,5},{1,2,10}};
    vector<int>needs = {3,2},price = {2,5};

    cout<<shoppingOffers(price,special,needs)<<endl;

    return 0;
}