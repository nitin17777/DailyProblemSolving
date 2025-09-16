#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;

long minimumDifference(vector<int>& nums)
{

    //we are given and array contianing 3*n elements

    //we can remove subsequence of size exactly n from nums and remaining 2n elements will be divided into equal parts

    //we have to return the min diff possible bw sum of two parts after removal of that subsequence made of n elements 

    //#difference : firstPart - secondPart and to minimise difference, we need to minimise the first part and maxamise the 2nd part

    //1->find the size i.e n -> To remove the subsequence
    int n = nums.size()/3;
    int size = nums.size();//given array size

    //maxHeap for left side

    priority_queue<int>maxHeap; ///to keep track of n smallest elements

    vector<long long>prefixSum(size,0); //stores min sum of n elements from left
    
    long long sum = 0;

    //Calculating minimum sum of n elements from 0 to 2n-1
    for(int i = 0;i < 2*n; i++)
    {
    sum +=nums[i]; // adding number to the running sum
    maxHeap.push(nums[i]); // Adding number to maxheap


    if(maxHeap.size() >n)
    {
        sum -= maxHeap.top();// remove the largest element from sum
        maxHeap.pop(); // removed largest element from here as well

    }
        if(maxHeap.size() == n)
        {
            prefixSum[i] = sum;
        }
    
    }

    vector<long long> suffixSum(size , 0); //To store max sum of n largest elements from right

    priority_queue<int,vector<int>,greater<int>>minHeap;

    sum=0;
    for(int i =size-1; i >=n; i--)
    {
        sum+=nums[i];
        minHeap.push(nums[i]);


        if(minHeap.size() > n)
        {
            sum -= minHeap.top();

            minHeap.pop();

        }

        if(minHeap.size() == n)
        {
            suffixSum[i] = sum;

        }

    }


    long long res = LLONG_MAX;

    for(int i = n-1; i<2*n; i++)
    {
        res = min(res,prefixSum[i]-suffixSum[i+1]);
    }

    return res;
}

int main()
{

    vector<int>nums = {7,9,5,8,1,3};

    cout<<minimumDifference(nums)<<endl;

    return 0;
    
}


