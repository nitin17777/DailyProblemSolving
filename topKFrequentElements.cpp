#include<bits/stdc++.h>
using namespace std;


vector<int> topKFrequent(vector<int>& nums, int k)
{

    unordered_map<int,int>freq;
    int n = nums.size();

    for(int i = 0;i<n;i++)
    {
        freq[nums[i]]++;
    }


    //Min heap
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>minHeap;


    for(auto&p:freq)
    {
        minHeap.push({p.second,p.first});
        if((int)minHeap.size()>k)
        {
            minHeap.pop();
        }
    }

    vector<int>ans;
    while(!minHeap.empty())
    {
        ans.push_back(minHeap.top().second);
    }
    reverse(ans.begin(),ans.end());

    return ans;
}

/* Kind of BRUTE FORCE
vector<int> topKFrequent(vector<int>& nums, int k)
{
    //we have to return the top k elements in array of which occured most frequently
    unordered_map<int,int>freq;
    int n = nums.size();

    for(int i = 0;i<n;i++)
    {
        freq[nums[i]]++;
    }

    //Now we have frequency of all elements in the given array

    //Now sort this freq map according to their frequency

    vector<pair<int,int>>vec(freq.begin(),freq.end());
    
    sort(vec.begin(),vec.end(),[](auto&a,auto&b)
    {
        return a.second > b.second;
    });

    vector<int>ans;

    for(int i = 0;i<k;i++)
    {
        ans.push_back(vec[i].first);

    } 
return ans;

}
*/

int main()
{

    vector<int>nums = {1,1,1,2,2,3};
    vector<int>ans = topKFrequent(nums,2);

    for(auto&an:ans)
    {
        cout<<an<<" ";
    }
    cout<<endl;

    return 0;
    
}
