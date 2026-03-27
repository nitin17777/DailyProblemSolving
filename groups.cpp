#include<bits/stdc++.h>
using namespace std;


// bool solve(vector<vector<int>>&a)
// {
//     int m = a.size(),n = a[0].size();

//     /*

//     Each group will be attendinng exactly one lesson each week during 
    
//     Determine if we can choose two different week days to schedule the lessons for the group

//     */


// }

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<vector<int>> a(n, vector<int>(5));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> a[i][j];
            }
        }
        
        bool possible = false;
        
        // Try all pairs of days
        for (int d1 = 0; d1 < 5; d1++) {
            for (int d2 = d1 + 1; d2 < 5; d2++) {
                
                int cntA = 0, cntB = 0;
                bool ok = true;
                
                for (int i = 0; i < n; i++) {
                    
                    if (a[i][d1] == 0 && a[i][d2] == 0) {
                        ok = false; // belongs to "none" group
                        break;
                    }
                    else if (a[i][d1] == 1 && a[i][d2] == 0) {
                        cntA++;
                    }
                    else if (a[i][d1] == 0 && a[i][d2] == 1) {
                        cntB++;
                    }
                }
                
                // Check balance condition
                if (ok && cntA <= n/2 && cntB <= n/2) {
                    possible = true;
                }
            }
        }
        
        cout << (possible ? "YES\n" : "NO\n");
    }
    
    return 0;
}