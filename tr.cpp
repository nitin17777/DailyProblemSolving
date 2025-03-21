#include<iostream>
#include<vector>

using namespace std;
//In a given array checking if largest number there is greater or equal to other elements and returning its index and if not found return -1


int dominant(int arr[],int n)
{


        int largest = -1;
        int index = 0;

    
    //Go through all the elements of array to find the largest number there 

    for(int i = 0; i<n; i++)
    {

         //assigning largest value as -1 as reference to check
        if(arr[i]>largest)
        {
            largest = arr[i];
            index = i;

        }
    }

    for(int i = 0; i<n; i++)
    {
        if(arr[i] != largest && largest < 2 * arr[i])
        {
            return -1;
        }

    }
    return index;

    //Then check if twice of all other number is <= to that number

    //If yes ,return the index of that number and if not return -1

}

int main()
{

int array[4] = {1,2,3,7};


int index = dominant(array,4);


if(index != -1){
    cout<<"Index with greatest element is : "<< index <<endl;

}
else{
    cout<<"Not Valid."<<endl;

}
    return 0;

}