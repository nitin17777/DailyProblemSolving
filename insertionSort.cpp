#include<iostream>
#include<vector>

using namespace std;


void insort(int n,vector<int>&arr)
{
   
    
    for(int i = 1;i<n;i++)
    {
        int key = arr[i];

        int j = i-1;

        while(j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;

    }
}

int main()
{


    vector<int> arr = {2,13,24,22,3,45,5};
    int n = arr.size();

    insort(n,arr);
    

    cout<<"Sorted Array: ";

    for(int i = 0;i<n;i++)
    {
        cout<< arr[i] <<" ";
    
    }
    cout<<endl;


    return 0;
}