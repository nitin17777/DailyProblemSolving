#include<iostream>
using namespace std;

inline int geMax(int & a,int b)
{
    return(a>b) ? a:b;
    //replaces a function call with actual code of function
    
}



int main()
{


    int a = 1,b = 2;

    int ans = 0;

    if(a>b)
    {
        ans = a;

    }
    else
    {
        ans =b;
    }


        //Alternate and effecient way:

        ans = (a>b)?a:b;


    return 0;


}