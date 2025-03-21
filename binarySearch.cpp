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



int main()
{

    int even[6] = {2,4,6,8,12,16};
    int odd[5] = {3,5,6,7,8};

    int indexe = binarySearch(even,6,4);
    cout<<"Index of 12 is "<<indexe<<endl;
    int indexo = binarySearch(odd,5,6);
    cout<<"Index of 6 is "<<indexo<<endl;
    
    return 0;

}