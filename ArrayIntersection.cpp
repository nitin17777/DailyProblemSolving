#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

//we are given two arrays, now we have to find the elements of array which are common in both given arrays
vector<int>intersect(vector<int>nums1 , vector<int>nums2)
{
    unordered_set<int>set1(nums1.begin() ,nums1.end());

    unordered_set<int>ans;

    for(int num : nums2)
    {
        if(set1.count(num))
        {
        ans.insert(num);
        }
    }
    return vector<int>(ans.begin(),ans.end());  // for converting the ans SET into ans ARRAY
}

int main()
{
    vector<int>nums1 = {4,9,5};
    vector<int>nums2 = {9,4,9,8,4};

    vector<int>ans = intersect(nums1 ,nums2);

    for(auto an : ans)
    {
        cout<<an << " ";
    }

    cout<<endl;


    return 0;

}