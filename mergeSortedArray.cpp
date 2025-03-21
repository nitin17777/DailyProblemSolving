#include<iostream>
#include<vector>

using namespace std;


void merge(vector<int>& nums1,int m,vector<int>&nums2,int n)
{

    vector<int>merged(m+n); //creating a temporary array to hold the merged array elements

    int i = 0,j=0,k=0;


    while(i<m && j<n)
    {
        if(nums1[i]>nums2[j])
        {
            merged[k++] = nums1[i++];

        }
        else
        {
            merged[k++] = nums2[j++];

        }
    }

    //now for remaining elements

    while(i<m)
    {
        merged[k++] = nums1[i++];

    }
    
    while(j<n)
    {
        merged[k++] = nums2[j++];

    }

    nums1 = merged;
    

}

int main()
{

    vector<int>arr1 = {1,5,7};
    vector<int>arr2 = {2,3,6};

    int m =3 ,n = 3;


    merge(arr1,m,arr2,n);

    for(int num : arr1)
    {
        cout<<num<<" ";

    }
    cout<<endl;


    return 0;

}