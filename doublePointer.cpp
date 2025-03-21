#include<iostream>
using namespace std;

void update(int **p2)
{
   // p = p +1 ;   ->No change


   // *p = *p+1;
    **p2 = **p2+1;



}

int main(){

   /* int i = 5;
    int *p = &i;
    int **p2 = &p;

    cout<< "Printing p"<< p<<endl;


    cout<<"Address of p" <<&p<<endl;

    cout<< "Printing p2 "<< **p2<< endl;
    cout<<"Printing p2 "<< *p<<endl;
    

   cout<<"Before: "<<i<<endl;
   cout<<"Before: "<<p<<endl;
   cout<<"Before: "<<p2<<endl;

   update(p2);
    cout<<"After: "<<i<<endl;
   cout<<"After: "<<p<<endl;
   cout<<"After: "<<p2<<endl;

   */


 /* int *p = 0;
  int first = 110;
  *p = first;

  cout<<*p<<endl;
*/


char arr[] = "abcde";

char *p = &arr[0];
cout<<p<<endl;

    
    return 0;

}