#include<iostream>
#include<vector>


using namespace std;

 //with recursion

bool checkSorted(int arr[],int size)
{
    //base case

    if(size == 0 || size == 1)
    return true;

    if(arr[0]>arr[1]){
        return false;

    }

    else
    {
        bool remaining = checkSorted(arr+1,size-1);

        return remaining;
    }

}

int main()
{


    int arr[5] = {2,4,5,3,1};
    int size = 5;

    bool ans = checkSorted(arr,size);

    if (ans)
    {
        cout<<"Array is Sorted."<<endl;
    }
    else
    {
        cout<<"Array is not sorted."<<endl;
    }



    return 0;
}