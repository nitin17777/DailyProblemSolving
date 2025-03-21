#include<iostream>
#include<vector>
#include<algorithm>



using namespace std;

void selectionSort(vector<int> &arr,int n)

{


    for(int i = 0; i <= n-1; i++)
    {
        int minIndex = i;
        for(int j = i+1 ; j<n ; j++)
        {
            if (arr[j]<arr[minIndex])
            minIndex = j;

        }
        swap(arr[minIndex],arr[i]); //now indicates the new assumed min value.
    }
}

int main()
{

    vector<int> arr = {12,14,11,5,44,7};


    int n = arr.size();


    selectionSort(arr,n);

    for (int num :arr)
    {
        cout<<num<<" ";

    }

    cout<<endl;
    
    return 0;
}