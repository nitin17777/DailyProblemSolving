#include<bits/stdc++.h>
#define ll long long
using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
        
    int count = 0;
    int maxi = 0;

    for(int i = 0; i < nums.size(); i++) {

        if(nums[i] == 1) {
            count++;
            maxi = max(maxi, count);
        }
        else {
            count = 0;
        }
    }
    return maxi;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>nums = {1,1,0,1,1,1};
    cout<<findMaxConsecutiveOnes(nums)<<endl;


    return 0;
}
