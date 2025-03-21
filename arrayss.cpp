#include<iostream>
using namespace std;
 
 
 void printArray(int arr[], int size)
 {
   cout<<"Printing the array"<<endl;
   for (int i = 0 ; i<size ; i++) 
   {
    cout<<arr[i]<<" ";
    
   }
   cout<<"Printing done"<<endl;

 }
 
 int main()
 {
    
    //Initialisinga an array
    int number[15];





  //Accessing an array 
    cout<< "Value at 14 index is " << number[14]<<endl;

    
    //Initialising an array
    int second[3] = {5 , 7 , 11};

   
   //Accessing an element
    cout<< "Value at 2 index is " << second[2]<<endl;


    int third[15] = {2 , 7};

    
    int n  = 15;
    printArray(third,15);


   
    int forth[10] = {0};
    n = 10;

   printArray(forth,10);


    int fifth[10] = {1};

    n = 10;
    printArray(fifth,10);


    int fifthSize = sizeof(fifth)/sizeof(int);
    cout<<"Size of fifth is "<<fifthSize<<endl;


    char ch[5] = {'a','b','c','d','e'};
    cout<<ch[2]<<endl;

    for(int i = 0;i<5;i++)
    {
      cout<<ch[i]<<endl;
    }
 cout<< endl<< "Everything is fine" <<endl<<endl;
 double firstDouble[5];
 float firstFLoat[6];
 bool firstBool[4];


    return 0;
 }