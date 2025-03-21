#include<iostream>

using namespace std;

bool bs(int *arr,int s,int e ,int k)
{

    //base case

    //element not found
    if(s > e)
    return false;

    int mid = s+(e-s)/2;

    // element found
    if(arr[mid] == k )
    {
        return true;
    }

    if(arr[mid]<k)
    {
        return bs(arr, mid+1, e, k);

    }
    else
    {
        return bs(arr, s, mid-1, k);
    }
}

int main()
{


    int arr[6] = {2,4,6,10,15,16};
    int size = 6;
    int key = 10;

    bool ans = bs(arr,0,size-1,key);

    if(ans)
    {
        cout<<"Found."<<endl;

    }

    else
    {
        cout<<"Not Found."<<endl;

    }


    return 0;

}