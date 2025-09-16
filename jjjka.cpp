//count and say problem
#include<iostream>
using namespace std;

string countS(int n)
{
    //base case: 
    if(n == 1)
    return "1";

    string prev = countS(n-1);

    string result = "";

    int count = 1;


    for(int i =0; i < prev.length(); i++)
    {
        
    }





}

int main()
{

    int n = 5;

    cout<<countS(n)<<endl;


    return 0;

}