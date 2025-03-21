#include<iostream>
using namespace std;

void reverse(string & str,int i ) //if the string is not passed as reference value then there will be copy of string which would be firstly reversed in the function and then again in the main function which means the string won't be reversed.
{
//can also be done by two pointer approach 
    int n =str.size();
    if(i>=n-i-1)
    {
        return;
    }

    swap(str[i],str[n-i-1]);
    i++;
    n--;

    reverse(str,i);
}

int main()
{

    string name = "Babbar";

    reverse(name,0);

    cout<<name<<endl;
    
    return 0;

}