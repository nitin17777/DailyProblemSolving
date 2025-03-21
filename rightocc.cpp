//find the rightmost or last occurence of any given number

#include<iostream>
using namespace std;

int rightOcc(int arr[],int n,int key)
{

    
    int e = n-1 , s = 0;
    
    int ans= -1;

    while(s <= e)
    {
        int mid = s +(e - s)/2;
        if(arr[mid] == key)
        {
            ans = mid;
            s = mid+1;
        }

        else if (arr[mid]<key)
        {
            s =mid+1;

        }

        else
        {
            e = mid -1;

        }
        }
        return ans;
}

int main()
{

    int even[]= {1,2,3,3,3,4,5}; //7

     cout<<"Last occurence of 3 is at index: "<<rightOcc(even,7,3)<<endl;

     return 0;

}