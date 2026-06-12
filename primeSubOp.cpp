#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool primeSubOperation(vector<int>& nums)
{
    int n= nums.size();

    // Pick any element and any prime number strictly smaller than it and : nums[i] - p

    // Return true if we can make nums stricly inreasing

    int mx = *max_element(nums.begin(),nums.end());

    vector<bool>isPrime(mx+1,true);
    isPrime[0] = isPrime[1] = false;

    for(int i =2;i*i <= mx;i++)
    {
        if(isPrime[i])
        {
            for(int j = i*i; j<=mx; j+=i)
            {
                isPrime[j] = false;
            }
        }
    }

    vector<int>primes;
    for(int i = 2;i<=mx;i++)
    {
        if(isPrime[i])primes.push_back(i);
    }

    int prev = 0;
    for(int x:nums)
    {
        int limit = x-prev;

        // we want prime number just less than limit
        auto it = lower_bound(primes.begin(),primes.end(),limit);

        if(it!=primes.begin())
        {
            it--;
            x-=*it;
        }

        //Final check for element at that index
        if(x<=prev)return false;

        //Assigning new prev
        prev = x;
    }

    return true;
}



      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {4,9,6,10};
    cout<<(primeSubOperation(nums)?"True":"False")<<endl;

    return 0;
}