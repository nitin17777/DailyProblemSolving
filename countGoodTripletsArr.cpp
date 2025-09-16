#include<iostream>
#include<vector>
using namespace std;

int goodTriplets(vector<int>&arr, int a, int b , int c)
{
    int count = 0;

    int n = arr.size();

    // a triplet is good if :
    //abs(arr[i] - arr[j] <= a)
    //abs(arr[j] - arr[k] <= b)
    //abs(arr[k] - arr[i] <= c)

    for(int i= 0; i<n-2; i++)
    {
        for(int j = i + 1; j <n-1;j++)
        {
           for(int k = j+1; k < n; k++)
           {
            if((abs(arr[i] - arr[j]) <= a) && (abs(arr[j] - arr[k]) <= b) && abs(arr[i] - arr[k]) <=c)
            {
                count++;
            }
           }
        }
    }
    return count;
}

int main()
{

    vector<int>arr = {3,0,1,1,9,7};
    int a = 7,b= 2,c=3;


    int ans = goodTriplets(arr, a,b,c);

    cout<<ans<<endl;

    return 0;

}