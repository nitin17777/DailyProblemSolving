#include<bits/stdc++.h>
using namespace std;

int minGold(vector<int>& wealth)
{
    int n = wealth.size();
    
    // Special case: if n <= 2, more than half can never be unhappy
    if(n <= 2) return -1;
    
    sort(wealth.begin(), wealth.end());
    
    int maxWealth = wealth[n-1];
    
    // We need strictly more than n/2 people to be unhappy
    // So at least (n/2 + 1) people should be unhappy
    int requiredUnhappy = n/2 + 1;
    
    // The (requiredUnhappy)th person from the end should be unhappy
    // After sorting, this is wealth[n - requiredUnhappy]
    int medianWealth = wealth[n - requiredUnhappy];
    
    // For median person to be unhappy:
    // medianWealth < (totalWealth + x) / (2 * n)
    // 2 * n * medianWealth < totalWealth + x
    // x > 2 * n * medianWealth - totalWealth
    
    long long totalWealth = 0;
    for(int w : wealth) totalWealth += w;
    
    long long x = 2LL * n * medianWealth - totalWealth + 1;
    
    // x cannot be negative
    if(x <= 0) return -1;
    
    return (int)x;
}

int main()
{
    int t;
    cin >> t;
    
    while(t--)
    {
        int n;
        cin >> n;
        
        vector<int> wealth(n);
        for(auto& x : wealth) cin >> x;
        
        cout << minGold(wealth) << endl;
    }
    return 0;
}