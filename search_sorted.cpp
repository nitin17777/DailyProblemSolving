#include<iostream>
using namespace std;

int binarySearch(int arr[],int size, int key)
{
    int start = 0;
    int end = size - 1;


    int mid = start + (end - start)/2;


    while(start <= end)
    {
        if(arr[mid] == key)
        {
            return mid;  
        }
        //go to right part when key>mid
        if(key> arr[mid])
        {
         start = mid+1;

        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}



int getPivot(int arr[],int n)
{
    int s = 0;
    int e = n-1;            
    int mid = s+(e-s)/2;


    while(s<e)
    {
        if(arr[mid]>=arr[0])
        {
            s = mid+1;
        }
        else
        {
            e = mid;
        }
        mid =s+(e-s)/2;

    }
    return s;
}

int findPosi(int arr, int n, int k)
{
    int pivot = getPivot(arr,n);
    if(k >= arr[pivot] && k <= arr[n-1])

    {
        return binarySearch(arr,pivot,n-1,k);
    }
}


int main()
{
 int arr = {5,6,7,1,2,3} ;//6


 int sorted = 
}




//incomplete



 