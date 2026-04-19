#include<bits/stdc++.h>
#define ll long long
using namespace std;


int maxDistance(vector<int>& nums1, vector<int>& nums2)
{
    //We actually don't need to move further in nums2 as soon as we encounter nums1[i] > nums2[j]

    int i=0,j=0;

    int maxi = 0;

    //Note that i can temporarily be greater than j ,but it won't affect maxi

    while(i<nums1.size() && j < nums2.size())
    {
        if(nums1[i] <= nums2[j])
        {
            maxi = max(maxi,j-i);
            j++;
        }

        else 
        {
            //Look for smaller number in nums1
            i++;
        }
    }
    return maxi;
}


/* COMPLETE BRUTE FORCE APPROACH
int maxDistance(vector<int>& nums1, vector<int>& nums2)
{
    /*
    
    A pair of indices i valid iff : i<=j && nums1[i] <= nums2[j]

    //Return the max distance of any valid pair, else return 0;

    


    int maxi = 0;

    for(int i= 0;i<nums1.size();i++)
    {
        for(int j = i;j<nums2.size();j++)
        {
            if(nums1[i] <= nums2[j])
            {
                maxi = max(maxi,(j-i));
            }
        }
    }
    return maxi;
}

*/


      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>n1 = {55,30,5,4,2},n2 = {100,20,10,10,5};
    
   cout<<maxDistance(n1,n2)<<endl;
   

    return 0;
}
