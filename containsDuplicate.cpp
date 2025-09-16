#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

bool contains(vector<int>&nums)
{
    unordered_set<int>seen;

    for(int num : nums)
    {
        if(seen.count(num))
        {
        return true;
        }

        else
        {
            seen.insert(num);
        }
    }
    return false;


    /*
    unordered_map<int,int>freq;

    for(int num : nums)
    {
        freq[num]++;
    }
    for(auto it: freq)
    {
        if(it.second > 1)
        return true;
    }
    return false;
    */

}


int main()
{
    vector<int>nums = {1,2,3,4};
    if(contains(nums))
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"False"<<endl;
    }

    return 0;
}