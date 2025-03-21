#include<iostream>
#include<vector>

using namespace std;


void insort(int n,vector<int>&arr)
{
    for(int i = 1; i<n;i++)
    {

        int temp =arr[i];

        int j;



        for(int j = i-1 ; j>=0 ; j++)
        {
            if(arr[j] > temp)
            { 

                arr[j+1] = arr[j];
            }

            else{

               break;
     
        }

            arr[j+1] = temp;

    }

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