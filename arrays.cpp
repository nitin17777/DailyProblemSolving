#include<iostream>
using namespace std;
 
 
 void printArrray()

 {

 }
 int main()
 {
    
    //Initialising an array
    int number[15];





  //Accessing an array 
    cout<< "Value at 14 index is " << number[14]<<endl;

    
    //Initialising an array
    int second[3] = {5 , 7 , 11};

   
   //Accessing an element
    cout<< "Value at 2 index is " << second[2]<<endl;


    int third[15] = {2 , 7};

    
    int n  = 15;


    for(int i = 0; i<=n ; i++)
    {
        cout<< third[i]<< " ";
    }
    cout<< endl<< "Everything is fine" <<endl<<endl;



    int forth[10] = {0};
    n = 10;

    cout<<"Printing the array" << endl;
    for(int i = 0; i<=n ; i++)
    {
      cout<<forth[i]<<" ";
    }


    int fifth[10] = {1};

    n = 10;
    cout<<"Printing the array"<<endl;

    for(int i = 0; i<=n; i++)

 {
  cout<< fifth[i]<< " ";

 }

 cout<< endl<< "Everything is fine" <<endl<<endl;


    return 0;
 }