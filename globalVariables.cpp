#include<iostream>
using namespace std;


void a(int& i )
{
    cout<<i<<endl;

    b(i);
    

}

int main()
{

    int i = 5;
    a(i);





    return 0;

}