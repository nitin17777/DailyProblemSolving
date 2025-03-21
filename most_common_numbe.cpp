#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//most frequent even number.


int mostFrequentNum(vector<int>& nums)
{

    sort(nums.begin(),nums.end());


    int maxCount = 0;
    int count = 1;
    int mostFrequent = -1;

    int prev = 1;



    for(int num:nums)
    {if(num % 2 == 0)
    {
        if (num == prev)

        {
            count++;

        }

        else
        {
            count = 1;

        }

        if(count>maxCount)
        {
            maxCount = count;
            mostFrequent = num;

        }

        prev = num;

    }
    }

    return mostFrequent;


    }

int main()
{

    vector<int>arr = {1,2,2,3,3,3,3,3,3,3};

    cout<< mostFrequentNum(arr)<<endl;


    return 0;

}