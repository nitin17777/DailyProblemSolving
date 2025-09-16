#include<bits/stdc++.h>
using namespace std;

vector<int> productQueries(int n, vector<vector<int>>& queries)
{
    const int MOD = 1e9 +7;

    vector<int>powers; //to store powers of 2

    for(int i = 0;i <31;i++)
    {
        if(n&(1<<i))
        {
            powers.push_back(1<<i); //adding 2^i  to the powers list
        }
    }

    sort(powers.begin(),powers.end());


    // Precomputing prefix product for faster query celebration
    vector<long long>prefix(powers.size()); // long long to avoid overflow

    prefix[0] = powers[0] % MOD;
    for(int i =1;i <powers.size();i++)
    {
        prefix[i] = (prefix[i-1] * powers[i]) % MOD;
    }

    vector<int>ans;

    for(auto&q:queries)
    {
        int l = q[0];
        int r = q[1];

        if(l == 0)
        {
            //if range starts from 0, product is simply prefix[r]
            ans.push_back(prefix[r] % MOD);//all products from 0 to r
        }
        else////////////************* */
        {
            long long num = prefix[r];
            long long denom = prefix[l-1];

            long long inv = 1; // store modular inverse
            long long base = denom; // base for exponentiation
            long long exp = MOD-2; //power for modular inverse

            while(exp > 0)
            {
                if(exp &1) 
                inv = (inv * base) %MOD;

                base = (base*base) %MOD;
                exp>>=1;
            }
            ans.push_back((num *inv) %MOD);
        }
    }
    return ans;
}

int main()
{


    int n = 15;
    vector<vector<int>>queries = {
        {0,1}, {2,2}, {0,3}
    };

    vector<int>ans = productQueries(n,queries);

    for(auto & an: ans)
    {
        cout<<an<<" ";
    }
    cout<<endl;

    return 0;
}