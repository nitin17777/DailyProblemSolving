#include<bits/stdc++.h>
using namespace std;

int minOps(vector<int>& nums)
{

    int ops = 0;
    int i =0;

    while(true)
    {

    unordered_map<int,int>seen;
    

    bool duplicate = false;


    for(int j =i; j < nums.size(); j++)
    {
        if(seen.count(nums[j]))
        {
        duplicate = true;
        break;
        }

        seen.insert(nums[j]);
    }
        
        if(!duplicate)
        break;

        i += 3;//just simulate removing 3 elements
        ops++;

        if(i >= nums.size())
        break;
    }
    return ops;
}


int main()
{
    vector<int>arr = {1,2,3,4,2,3,3,5,7};

    int ans = minOps(arr);

    cout<<ans<<endl;


    return 0;

}


