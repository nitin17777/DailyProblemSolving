#include<iostream>
#include<vector>
using namespace std;




//More optimised

int findEven(vector<int>nums)
{
    int count = 0;

    for(int num : nums)
    {
        int digits = 0;

        while(num != 0)
        {
            num /=10;
            digits++;
        }

        if(digits % 2 == 0)
        count++;

    }
    return count ;

}

/*
int findEven(vector<int>nums)
{
    int count = 0;
    
    for(int i = 0; i<nums.size() ;i++)
    {
        
        string str = to_string(nums[i]);
        int size = str.length();
        if(size %2 == 0)
        {
            count++;

        }
    }
    return count;
}
    */

int main()
{
    vector<int>nums = {12,345,2,6,7896};

    int ans =findEven(nums);

    cout<<ans<<endl;

    return 0;

}