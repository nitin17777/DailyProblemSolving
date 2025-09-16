#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll seller(ll n)
{
    // he can sell 3^x watermelons for 3 ^ x+1 +  x⋅3^x−1 
    //buy exactly n watermelons such that he has to make least possible number of deals
    // 1 watermelons for 3
    // 3 watermelons for 9 + 1 = 10 coins  --> 1 for 3.33
    // 9 watermelons for 27 + 6 = 33 coins -->1 for 3.66
    // 27 watermelons for 108 coins -->1 for 3.27

    //store precomputed costs for each power level
    vector<ll>cost;

    //start with cost for x =0;

    ll c = 3;






    


}

int main()
{
    int n = 8; //26
    cout<<seller(n)<<endl;
    
    return 0;
    
}
