#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>nums , vector<int>output,int index,vector<vector<int>>&ans
)
{

    //base case ->  if index exceeds the array size, we store the current subse(output) in ans and return it
    
    if(index >= nums.size())
    {
        ans.push_back(output);
        return;
    }

    //exclude
    solve(nums,output,index +1,ans);

    //include

    int element = nums[index];
    output.push_back(element);

    solve(nums,output,index+1,ans);
    
}

vector<vector<int>>subsets(vector<int>& nums)  //vector inside of vector
{
    //we have to find all possible subsets of a given array including null set

    //means we have to find every posiible combination of elements present in a set


    vector<vector<int>>ans;

    vector<int> output;
    int index = 0;

    solve(nums,output,index,ans);
    return ans;

}

int main()
{

    vector<int>arr = {1,2,5};

    vector<vector<int>> result = subsets(arr);

    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}, ";
    }
    cout << endl;

}