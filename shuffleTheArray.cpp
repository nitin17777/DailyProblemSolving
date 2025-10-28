#include <iostream>
#include <vector>

using namespace std;

vector<int> shuffle(vector<int> &nums, int n)
{
    vector<int> ans;

    for (int i = 0; i < nums.size() / 2; i++)
    {
        ans.push_back(nums[i]);
        ans.push_back(nums[n + i]);
    }
    return ans;
}

/*
vector<int> shuffle(vector<int>& nums, int n)
{
    int m = nums.size();
    vector<int>left;

    vector<int>right;

    for(int i = 0;i<n;i++)
    {
        left.push_back(nums[i]);
    }//left = {2,5,1}

    for(int i = n;i<m;i++)
    {
        right.push_back(nums[i]);
    }//right = {3,4,7}



    vector<int>ans;
    for(int i = 0;i < m/2;i++)
    {
        ans.push_back(left[i]);
        ans.push_back(right[i]);
    }
    return ans;
}
*/

int main()
{
    vector<int> nums = {2, 5, 1, 3, 4, 7};
    vector<int> ans = shuffle(nums, 3);

    for (auto &an : ans)
        cout << an << " ";

    cout << endl;
    return 0;
}
