#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

bool canJump(vector<int>& nums)
{
    //each element represents the max jump length , return true if you can jump the entire array , else return false
    int n = nums.size();

    int reachable = 0; //  farthest point we can reach

    for(int i = 0; i<n; i++)
    {
        if(i > reachable) // if the index we are standing at is greater than the reachable jump which is inherited from previous step
        {
            return false;// if current index is beyond the reachable range
        }
        reachable = max(reachable, i + nums[i]); // greedy step
    }
    return true; // if we can reach the last index return true
}


int main()
{
    vector<int>nums ={2,3,1,1,4};

    if(canJump(nums))
    {
        cout<<"Can Reach."<<endl;    
    }
    else
    {
        cout<<"Cannot Reach."<<endl;
    }
    return 0;

}