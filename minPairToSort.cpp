#include <bits/stdc++.h>
using namespace std;

int minimumPairRemoval(vector<int> &nums)
{
    int cnt = 0;

    while (nums.size() > 1)
    {
        bool isAsc = true;

        int minSum = INT_MAX;
        int targetIdx = -1;

        for (int i = 0; i + 1 < nums.size(); i++)
        {
            int sum = nums[i] + nums[i + 1];

            if (nums[i] > nums[i + 1])
                isAsc = false;

            if (sum < minSum)
            {
                minSum = sum;
                targetIdx = i;
            }
        }

        if (isAsc)
            break;

        cnt++;
        nums[targetIdx] = minSum;
        nums.erase(nums.begin() + targetIdx + 1);
    }
    return cnt;
}

/*
int minimumPairRemoval(vector<int>& nums)
{
    /*Remove the pair with minimum sum in arr => and repalce the pair their sum

    Return the min number of pairs to make the array non decreasing


    int n = nums.size();
    if(n<=1)return 0;

    vector<ll>arr(nums.begin(),nums.end());

    //find sum of adjacent elements and store them with their respective pairs => find the min sum
    priority_queue<pair<ll,int>,
                  vector<pair<ll,int>>,
                  greater<pair<ll,int>>>pq;

    int ops = 0;


    for(int i = 0;i+1<n;i++)
    {
        pq.push({arr[i]+arr[i+1],i});
    }

    //Now replace that pair with sum value and priority queue will rearrange


    while(true)
    {
        bool sorted = true;

        for(int i = 0;i+1< arr.size();i++)
        {
            if(arr[i] > arr[i+1])
            {
                sorted = false;
                break;
            }
        }

        if(sorted)break; //get out if array is sorted

        auto[sum,idx] = pq.top();
        pq.pop();

        //checking bound cases
        if(idx + 1 >= arr.size())continue;
        if(arr[idx]  + arr[idx +1] != sum)continue;

        //Merging and erasing
        arr[idx] += arr[idx+1];
        arr.erase(arr.begin()+idx+1);
        ops++;

        //pushing this affected new pair back to heap
        if(idx-1 >= 0)
        pq.push({arr[idx - 1]+arr[idx],idx-1});

        if(idx + 1<arr.size())
        {
            pq.push({arr[idx] + arr[idx+1],idx});
        }
    }
    return ops;
}*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {5, 2, 3, 1};
    cout << minimumPairRemoval(nums) << endl;
    return 0;
}