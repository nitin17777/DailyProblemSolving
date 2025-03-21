#include<iostream>
using namespace std;

void bubbleSort(int * arr ,int n) //bubble sort compares adjacent elements and swaps them if they are not in their right place

{

    //base case->Already Sorted

    if(n == 0 || n== 1)
    {
        return;

    }


    for(int i = 0;i<n;i++)
    {
        if(arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);

        }
    }

    bubbleSort(arr,n-1);
    
}

int main()
{

    int grr[] = {2,1,4,7,6,5,0};

    bubbleSort(grr,7);

cout<<"Sorted Array: ";
    for(int i = 0;i<7;i++)
    {
        cout<< grr[i]<<" ";
    }

    return 0;

}