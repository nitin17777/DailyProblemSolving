#include<iostream>
#include<vector>

using namespace std;
//int Rsum(int *arr,int size)
int Rsum(vector<int>& arr,int size)
{
    //base case
    if(size <= 0){
    return 0;
    }

    if(size = 1)
    {
        return arr[0];


    }

    /*
ALTERNATE

    int remainingPart = Rsum(arr+1,size - 1) ;

    int sum = arr[0] + remainingPart;
    return sum;




    */

    else
    {
    return arr[size-1] +Rsum(arr,size-1);
    }




}

int main()
{

    vector<int> nums = {1,2,3,4};

    int sizee = nums.size();

    int sum = Rsum(nums,sizee);

    cout<<"Sum is "<<sum<<endl;

    return 0;

}