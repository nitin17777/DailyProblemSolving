#include<iostream>
#include<vector>

using namespace std;

void bubblesort(vector<int>&arr,int n)
{

    for(int i = 0; i<n;i++)
    {

        bool swapped = false;

        for(int j = 0 ; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swapped = true;


            }
        }
        if (swapped =false)
        break;
    }

}

int main()
{


vector<int> arr = {2,1,5,6,4,90,7};

bubblesort(arr,arr.size());

cout<<"Sorted array: ";


for (int i = 0;i<arr.size();i++)
{
    cout<<arr[i]<< " ";


}
cout<<endl;
    return 0;

}