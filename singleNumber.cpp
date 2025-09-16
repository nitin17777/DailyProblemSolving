#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>&nums)
{

    //we have to find the number which only appears once using bit manipulation
    //a ^ a = 0 ; a ^ 0 = a; 
    int result = 0;
    for(auto num : nums)
    {
        result ^= num;
    }
    return result;

}

int main()
{
    vector<int>nums = {2,2,1};
    int ans = singleNumber(nums);

    cout<<ans<<endl;

    return 0;
    
}
