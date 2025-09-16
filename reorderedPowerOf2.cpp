#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


string countDigits(int n)
{
    //string of length 10 , each index is filled with '0'
    string count(10,'0');

    while(n>0)
    {
        count[n%10]++;
        n/=10;
    }
    return count;
}

bool reorderedPowerOf2(int n)
{
    string targetCount = countDigits(n);


    int power = i<<1; //com[puting 2^i using bit shifting






}





/*

Time Complexity : O(n!)

vector<vector<int>>result;

void backtrack(vector<int>&nums,vector<int>&path,vector<bool>&used)
{
    if(path.size() == nums.size())
    {
        result.push_back(path);
    }

    for(int i = 0;i <nums.size();i++)
    {

        if(used[i])continue;
        if(i > 0 && nums[i] == nums[i-1] && !used[i-1])
        continue;

        used[i] = true;
        path.push_back(nums[i]);

        backtrack(nums,path,used);

        //going back now

        used[i] = false; //so that other paths can use it too

        path.pop_back();
    }
}

vector<vector<int>>permute(vector<int>&nums)
{

    sort(nums.begin(), nums.end());

    vector<int>path;
    vector<bool>used(nums.size(),false);

    result.clear();

    backtrack(nums,path,used);

    return result;
}

bool powerOf2(vector<int>arr)
{
    long long num = 0;

    for(int d : arr)
    {
        num = num * 10 + d;
    }

    return num > 0 && (num & (num-1)) == 0;
}



bool hasNonZeroLeadingDigit(vector<int>&arr)
{
    return !arr.empty() && arr[0] != 0;

}

bool reorderedPowerOf2(int n)
{
    string str = to_string(n);
    vector<int>nums;

    for(int i = 0; i < str.size(); i++)
    {
        nums.push_back(str[i] -'0');
    }
        //Got all the required permutations
    vector<vector<int>>permuted = permute(nums);


//now need to access all permutations and check our conditions
    for(auto&num : permuted)
    {
        //checking our conditions
        if(hasNonZeroLeadingDigit(num) && powerOf2(num))
        return true;   
    }

    return false;
}
*/


int main()
{

    int n = 10;

    cout<<(reorderedPowerOf2(n) ? "true" : "false") <<endl;
    
    return 0;
    
}
