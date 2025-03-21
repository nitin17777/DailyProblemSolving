#include<iostream>
#include<vector>
using namespace std;


void rotate(vector<int>&nums,int k)


{
    vector<int>temp(nums.size());

    for(int i = 0; i<nums.size(); i++)
    {

        temp[(i+k) % nums.size()] = nums[i];
    }

    nums = temp;

}

int main()
{
    vector<int> kk = {1,2,3,4,5};


    rotate(kk,1);

    for(int i = 0;i<kk.size();i++)
    {
        cout<<kk[i]<<" ";

    }
    cout<<endl;

    return 0;

}