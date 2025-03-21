#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

 // we have to merge two given sorted arrays and find their median

 
    double findMe(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());

        sort(nums1.begin(), nums1.end());

        int size = nums1.size();
        if (size % 2 == 0){
            return (double)(nums1[size / 2] + nums1[size / 2 - 1]) / 2;
        }else{
            return (double)nums1[size / 2];
        }
 
 
 //correct approach
/*double findMe(vector<int>& nums1, vector<int>& nums2)
{

    vector<int> merged = {};


    int  i =0, j=0;

    while(i<nums1.size() && j<nums2.size())
    {
        if(nums1[i] <= nums2[j])
        {

            merged.push_back(nums1[i]);
            i++;
        }

        else
        {
            merged.push_back(nums2[j]);
            j++;

        }

    }
    int sizeN = merged.size();


    int median= 0;

    if(sizeN == 0)
    return 0;


    if(merged.size() % 2 == 0)
    {
        median= (merged[sizeN/2.0] + merged[(sizeN/2.0) + 1])/2.0;

    }
    else
    {
        median = merged[sizeN/2.0];
        
    }

    return median;*/

}

int main()

{

    vector<int>arr1 = {1,2,3}; //sortedArray = {1,2,3,4}
    vector<int>arr2 = {2,3,4};//Median =(3+2)/2 = 2.5

    double ans = findMe(arr1,arr2);

    cout<<"Median is : "<<ans<<endl;



    return 0;

}

