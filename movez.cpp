#include<iostream>
#include<vector>
using namespace std;


void moveZ(vector<int>&nums)
{
    int nonz=0;

    for(int j = 0; j<nums.size(); j++)
    {
        if (nums[j] !=0)
        {
            swap (nums[j],nums[nonz]);
            nonz++;
        }
    }
}

int main()
{

    vector<int>jj = {0,4,3,0,0,8,0};


    moveZ(jj);

    for(int i = 0; i<jj.size();i++)
    {
        cout<<jj[i]<<" ";
    }
    cout<<endl;
}