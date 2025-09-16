#include<bits/stdc++.h>
using namespace std;
using i64 = int64_t;


vector<int>sieve(int n)
{
    vector<bool>isPrime(n+1,true);

    vector<int>primes;

    isPrime[0] = isPrime[1] = false; //since 1 and 0 are false

    for(int i=2;i<=n;i++)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            for(long long j = 1LL *i*i;j<=n;j+=i)
            {
                isPrime[j] = false;                
            }
        }

    }

}

bool isGood(int n , vector<int>&primes)
{
    int temp = n;

    for(int p :primes)
    {

    }



}

int countGoodNumbers(int l, int r) 
{
    vector<int>primes = sieve(sqrt(r) + 1); //precomputing primes

    int countGood = 0;


    for(int num = l ; num <= r; num++)
    {
        if(isGood(num,primes))
        countGood++;
    }
    return countGood;
}



int main() 
{
    int l, r;
    cin >> l >> r;  // input range

    cout << countGoodNumbers(l, r) << endl;  // call the solver

    return 0;
}