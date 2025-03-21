#include<iostream>
using namespace std;

int main()
{


    int arr[10] = {23,122,41,67};

    

    /*cout<<"Address of 1st memory block is "<< arr <<endl;

    cout<<arr[0]<<endl;

    cout<<"Address of 1st memory block is "<<&arr[0]<<endl;



    cout<<"4th "<< *arr <<endl ;

    cout<<"4th "<< *arr + 1 <<endl ;


    int i = 3;
    cout<< i[arr]<<endl;


    */

//Address of 0th index 
   cout<<&arr[0]<<endl;


//value at 0th index of arr
   cout<< *arr <<endl;


//value at 0th index + 1
   cout<< *(arr +1) << endl;

   cout<<(arr+1) <<endl;
    




    return 0;

}