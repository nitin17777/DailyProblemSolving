#include<bits/stdc++.h>
using namespace std;

long long goodTriplets(vector<int>& nums1, vector<int>& nums2)
{

    //we have two arrays which are permutations of 0-n

    //a good triplet is a set of 3 distinct values which are present in increasing order by position both in nums1 and nums2


    //return the number of good triplets 
    
    //find all the pair of triplets from 1st array and then check which of the triplet is there in 2nd array too and return the numebr fo such triplets



    struct Fenwick
    {
        vector<int>bit;

        int n;

        Fenwick(int n) : n(n)
        {
            bit.assign(n+1,0);
        }


        void update(int i,int val)
        {
            for()
        }
    }


};


int main()
{

    vector<int>nums1 = {2,0,1,3};
    vector<int>nums2 = {0,1,2,3};

    cout<<goodTriplets(nums1, nums2);

    return 0;

}