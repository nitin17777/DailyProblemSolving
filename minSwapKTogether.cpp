#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minSwap(vector<int>& arr, int k) 
{
    //choose any 2 indices i, j: i<j  and swap arr[i] , arr[j]. Then find number of swaps required tot bring all the numbers less than or equal to 'k' together, then return the number of such swaps that took place

    //iterate throughh the given array until you find any element greater than 'k',if found , swap it with the element less than equal to 'k'

    int n = arr.size();


    int windowSize = 0;
    for(int i = 0;i <n; i++)
    {
        if(arr[i] <= k)
        windowSize++;
        
    }













    int count = 0;

    
    for(int i = 0; i < n;i++)
    {
        if(arr[i] > k)
        {

            for(int j = i+1; j <n; j++)
        {
            if(arr[j] < k)
            {
            swap(arr[i], arr[j]);
            count++;
            }
        }            
        }
    }
    return count;
}

int main()
{

    vector<int>arr = {2, 1, 5, 6, 3};
    int k = 3;

    int ans = minSwap(arr,k);

    cout<<ans<<endl;
    return 0;

}