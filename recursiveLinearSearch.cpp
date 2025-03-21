#include<iostream>
using namespace std;



bool linearSearch(int arr[], int size,int k)
{

    //base case
    if(size == 0)
    return false;

    if(arr[0] == k)

    return true;


    else
    {
        bool remainingP = linearSearch(arr+1,size- 1,k);
        return remainingP;

    }

}

int main()
{


    int arr[5] = {3,5,1,2,6};
    int size = 5;

    int key = 7;


    bool ans = linearSearch(arr,size,key);

    if(ans)
    {
        cout<<"Present"<<endl;


    }

    else
    {
        cout<<"Absent"<<endl;

    }





    return 0;

}
