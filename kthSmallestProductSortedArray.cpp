#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


ll countLessEqual(const vector<int>&nums1, const vector<int>&num2,llx)
{

    ll count = 0;
    int n = nums2.size();

    for(int a : nums)
    {
        
    }

}

long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k)
{


}



//brute force approach
long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k)
{
    //we are given 2 sorted arrays
    //we have to return the kth smallest product
    int product = 0;
    vector<int>products;

    for(int i=0; i<nums1.size();i++)
    {
        for(int j = 0; j <nums2.size();j++)
        {
            product = nums1[i] * nums2[j];
            products.push_back(product);
            
        }
    }
    sort(products.begin(),products.end());

    return products[k-1];
}

int main()
{

    vector<int>nums1 = {2,5};
    vector<int>nums2 = {3,4};

    int k = 2;

    long long ans = kthSmallestProduct(nums1, nums2,k);


    cout<<ans<<endl;



    return 0;

}