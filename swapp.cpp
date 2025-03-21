#include<iostream>
using namespace std;


void alter(int arr[], int n)

{
    int start = 0;
    while(start < n-1)
    {
        swap(arr[start], arr[start +1]);
        start += 2;

    }
}

void printArray(int arr[], int n )

{
    for (int i = 0; i<n ; i++)

    {
        cout<<arr[i]<<" ";

    }

    cout<<endl;
}

    int main()
    {
        int arr[6] = {2 , 4, 5 , 6 , 9 ,3};
        alter(arr , 6);

        printArray(arr,6);


return 0 ;

    }

