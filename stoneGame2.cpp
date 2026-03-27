#include<bits/stdc++.h>
using namespace std;


//Aim is to end the game with most stones
//alice will start
//On each player's turn the player can take all the stones in the first X remaining  pile 

int n;

vector<int> suffix;
int dp[101][101]; // constraints safe

int solve(int i, int M)
{

    //Base case: No piles left
    if (i >= n) return 0;
    
    //If already computed, reuse the result
    if (dp[i][M] != -1) return dp[i][M];
    
    // If we can take all remaining piles in one move
    if (i + 2*M >= n) return suffix[i];
    
    int ans = INT_MAX;
    

    //Trying all other possible X
    for (int X = 1; X <= 2*M; X++) {
        int opponent = solve(i + X, max(M, X));
        ans = min(ans, opponent);
    }
    
    return dp[i][M] = suffix[i] - ans;
}


int stoneGameII(vector<int>& piles)
{
    n = piles.size();
    suffix.resize(n);
    
    suffix[n-1] = piles[n-1];
    for (int i = n-2; i >= 0; i--) {
        suffix[i] = piles[i] + suffix[i+1];
    }
    
    memset(dp, -1, sizeof(dp));
    
    return solve(0, 1);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>p = {2,7,9,4,4};
    cout<<stoneGameII(p)<<endl;
    return 0;
}