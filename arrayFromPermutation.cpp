#include<iostream>
#include<vector>
using namespace std;

/* with O(n) space complexity

vector<int> buildArray(vector<int>& nums)
{
    vector<int>ans;

    for(int i=0; i<nums.size(); i++)
    {
        int num = nums[nums[i]];
        ans.push_back(num);
    }
    return ans;
}
*/

    //with O(1) space complexity
vector<int> buildArray(vector<int>& nums)
{
   int n= nums.size();

    for(int i=0; i<nums.size(); i++)
    {
        //nums[i] = nums[i] + n * (new_value)
        //storing both ond and new value in one place
        nums[i] = nums[i] + n*(nums[nums[i]] % n); //IMPORTANT
        //                         %n here to extract the original value in case it was changed
    }

    for(int i = 0; i<nums.size(); i++)
    {
        nums[i] = nums[i] / n; //extracting new value
    }
    return nums;
}

int main()
{
    vector<int>nums = {0,2,1,5,3,4};
    vector<int>ans = buildArray(nums);

    for(auto & an :ans)
    {
        cout<< an <<" ";
    }
    cout<<endl;  
}