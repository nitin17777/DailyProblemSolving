#include<iostream>
using namespace std;

int main()
{

//pointer is created, and pointing to some garbage address
    //int *p = 0;

   // cout<< *p <<endl;
/*
   int i = 5;
   int *p = 0;  
   p = &i;

   cout<< *p <<endl;
   cout<< p <<endl;


   int *q = 0;  
   q = &i;

   cout<< *q <<endl;
   cout<< q <<endl;

   */ 

  int num = 5;

  int a = num; 
  a++;


  cout<<num<<endl;
  int*p = &num;
  cout<<"Before: "<<num<<endl;

  (*p)++;
  cout<<"After: "<<num<<endl;


//copying pointers

  int *q = p;

  cout<<p<<"-"<<q<<endl;
  cout<<*p<<"-"<<*q<<endl;

  int i = 3;

  int *t = &i;

  cout<<(*t)++<<endl; 






    return 0; 

}