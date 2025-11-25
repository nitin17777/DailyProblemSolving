#include <bits/stdc++.h>
using namespace std;

vector<bool> prefixesDivBy5(vector<int> &nums)
{
    vector<bool> ans;

    int num = 0;

    for (int bit : nums)
    {
        num = (num * 2 + bit) % 5;
        ans.push_back(num == 0);
    }
    return ans;
}

/*
vector<bool> prefixesDivBy5(vector<int>& nums)
{
    int n = nums.size();
    vector<bool>ans;


    //Start a window from start and check if found number's AND = 0 with 5

    string str ="";

    for(int right = 0;right<n;right++)
    {
        string nu = to_string(nums[right]);
        str+=nu;

        if((stoi(str)) % 5 == 0)ans.push_back(true);
        else ans.push_back(false);
    }
    return ans;
}
*/

int main()
{

    vector<int> nums = {0, 1, 1};
    vector<bool> ans = prefixesDivBy5(nums);
    for (bool an : ans)
        cout << an << " ";

    cout << endl;

    return 0;
}
