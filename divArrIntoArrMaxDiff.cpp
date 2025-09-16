#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

 vector<vector<int>> divideArray(vector<int>& nums, int k)
 {

    //we are givne arr of dize of n such that n is multiple of 3 and k 
    //Nnow we need to divide nums into n/3 array which follows: diffference bw any 2 elements in one array is less thann equal to k
    //if impossible to return such array , just return an empty array

    int n = nums.size();
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;

   for(int i = 0; i<n; i+=3)
   {
    if(nums[i+2] - nums[i] > k)
    return {};
    
    else
    {
        ans.push_back({nums[i], nums[i+1], nums[i+2]});
    }
   }
   return ans;
}

int main()
{
    vector<int>nums = {1,3,4,8,7,9,3,5,1};
    int k = 2;

    vector<vector<int>>ans = divideArray(nums,k);

    for(auto& an :ans)
    {
        cout<<"{";
        for(auto& a :an)
        {
            cout<<a<<" ";
        }
        cout<<"},";
    }
    
    cout<<endl;
    return 0;

}