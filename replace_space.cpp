#include<iostream>
#include<vector>
using namespace std;

string repspace(string str)
{
      string temp = "";

      for(int i=0;i<str.length();i++)
      {
        if (str[i] == ' ')
        { 
        temp += "@";
        }
        else
      {
        temp.push_back(str[i]);
      }
      }
      return temp;
      
}


int main()
{
    string hg = "My name is this.";

    cout<<repspace(hg)<<endl;


    return 0;


}