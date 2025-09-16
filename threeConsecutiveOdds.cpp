#include<iostream>
#include<vector>
using namespace std;



    //we will use sliding window method here to check if three consecutive elements are odd
    
bool odd(vector<int>&arr)
{
    int count = 0;
    for(int i =0 ; i<arr.size();i++)
    {
        if(arr[i] && 1)
        coo
    }

   
}


//Brute force method
/*
bool odd(vector<int>&arr)
{
    for(int i = 0; i < arr.size()- 2;i++)
    {
        if(arr[i] % 2 != 0 && arr[i+1] % 2 != 0 && arr[i+2] % 2 != 0)
        {
            return true;
        }
    }

    return false;


}
    */



int main()
{
    vector<int>arr = {1,2,34,3,4,5,7,23,12};

    if(odd(arr))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }

    return 0;

}