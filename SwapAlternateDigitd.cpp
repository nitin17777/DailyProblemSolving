#include<iostream>
using namespace std;

void swap(int arr[], int n)

{
    for(int i = 1 ; i < n ; i += 2)
    {

    int temp = arr[i];
    arr[i] = arr[i-1];
    arr[i-1] = temp;

}
}

void printArray(int arr[] , int n )

{
    for (int i = 0 ;i<n ; i++)
    {
        cout<< arr[i] << " ";

    }
    cout<<endl;

}

void swapAlter(int arr[], int size)
{
    for (int i = 0 ; i<size; i+=2)
    if (i+1<size)
    {
        swap(arr [i],arr[i+1]);
    }
}

int main()
{
   int odd[5] = {2,4,7,44,2};
   int even[4] = {8,4,3,2};

   swapAlter(odd,5);
   printArray(odd,5);
 
    swapAlter(even,4);
    printArray(even,4);

return 0;
}