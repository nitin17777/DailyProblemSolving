#include <iostream>
#include <vector>
using namespace std;

string optimalDivision(vector<int> &nums)
{
    // you can place the paranthesis anywhere to maximize the result

    int n = nums.size();

    if (n == 1)
        return to_string(nums[0]);
    if (n == 2)
        return to_string(nums[0]) + "/" + to_string(nums[1]);

    string res = to_string(nums[0]) + "/(";

    for (int i = 1; i < n; i++)
    {
        res += to_string(nums[i]);
        if (i != n - 1)
            res += "/";
    }
    res += ")";
    return res;
}

int main()
{

    vector<int> nums = {1000, 100, 10, 2};
    string output = optimalDivision(nums);

    cout << output << endl;
    return 0;
}