#include<bits/stdc++.h>
#define ll long long
using namespace std;

int totalNumbers(vector<int>& digits)
{
    nint totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        // Count how many copies of each digit we have
        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        // Try every three-digit even number
        for (int num = 100; num <= 998; num += 2) {
            int x = num;

            int a = x / 100;          // hundreds
            int b = (x / 10) % 10;    // tens
            int c = x % 10;           // units

            // Check if we have enough copies of each digit
            vector<int> need(10, 0);
            need[a]++;
            need[b]++;
            need[c]++;

            bool possible = true;

            for (int d = 0; d <= 9; d++) {
                if (need[d] > freq[d]) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                ans++;
        }

        return ans;
    }
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
    
    }

    return 0;
}