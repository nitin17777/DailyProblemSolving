#include<iostream>
#include<vector>
using namespace std;

int numRabbits(vector<int>& answers) 
{

    //we have to return the min no. of rabbits that could be in forest
    unordered_map<int,int>countMap;
    int totalRabbits = 0;

    for(int answer :answers)
    {
        countMap[answer]++;
    }

    for(const auto& entry : countMap) // const makes sure that variable value can't be modified
    {
        int k = entry.first;
        int count = entry.second;

        int groupSize = k +1;

        totalRabbits += ceil((double)count / groupSize) * groupSize;


    }

}


int main()
{
    vector<int>nums = {1,1,2};

    int ans = numRabbits(nums);

    cout<<ans<<endl;

    return 0;
}