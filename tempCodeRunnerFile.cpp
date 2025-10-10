#include<iostream>
using namespace std;


int maximumEnergy(vector<int>& energy, int k)
{
    //after absorbing energy from magician i , we will be instantly transported to magician i+k and this will continue till i+k does not exist

    //return the max possible energy gained

    //and when yu reach certain magician you must take energy 


    //so find max energy we can gain 

    int n = energy.size();

    vector<vector<long long>dp(n);

    long long ans = LLONG_MIN;

    for (int i = n - 1; i >= 0; i--) {
        if (i + k < n)
            dp[i] = energy[i] + dp[i + k];
        else
            dp[i] = energy[i];
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main()
{

    vector<int>energy = {5,2,-10,-5,1};
    cout<<maximumEnergy(energy,3)<<endl;
    return 0;

}