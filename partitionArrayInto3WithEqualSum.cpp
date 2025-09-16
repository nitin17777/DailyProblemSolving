#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

bool canThreePartsEqualSum(vector<int>& arr)
{
    //we have to check if we sum of array is divisible by 3

    int total = accumulate(arr.begin(),arr.end(),0);



    int target = total/3;
    int sum = 0;
    int count = 0;

    for(int i = 0;i<arr.size();i++)
    {
        sum += arr[i];

        if(sum==target)
        {
            count++;

            sum = 0;

        }

        if(count == 2 && i< arr.size() -1)
        return true;


    }
    return false;


}

int main()
{

    vector<int>arr = {0,2,1,-6,6,-7,9,1,2,0,1};

    if(canThreePartsEqualSum(arr)) 
    cout<<"True"<<endl;

    else
    {
        cout<<"False"<<endl;

    }
    return 0;
    
}
