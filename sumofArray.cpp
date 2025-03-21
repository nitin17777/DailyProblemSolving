#include<iostream>
using namespace std;




//we need to find the sum of all elements in an array in which elements are given as input by user.

int main()
{
    int size;

    cout<<"Enter the size of array: ";
    cin >> size;


//declaring an array of  given size
    int arr[size];
    int sum = 0; //variable to store sum of elements


//Asking the user for elements in the array and finding their sum in same loop
    cout<<"Enter "<< size <<" elements:"<<endl;
    for(int i = 0; i<size; i++)
    {
        cin>>arr[i];
    }
    {

    for(int i = 0; i<size; i++)
    sum +=arr[i];
}



cout<<"Sum is "<<sum<<endl;

return 0;

}