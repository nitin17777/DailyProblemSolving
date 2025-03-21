#include<iostream>
using namespace std;

bool checkP(string str,int i ,int j)
{
    if(i>j)
    
    return true;

    if(str[i] !=str[j])
    {
        return false;

    }
    else
    {
        return checkP(str,i+1,j-1);

    }
}


int main()
{
    string name = "Abba";
    
    cout<<endl;

    bool isP = checkP(name,0,name.length()-1);

    if(isP)
    {
        cout<<"It is a Palindrome."<<endl;

    }

    else
    {
        cout<<"It is not a Palindrome."<<endl;

    }

    return 0;


}