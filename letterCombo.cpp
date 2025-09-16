#include<iostream>
#include<vector>
using namespace std;


void solve(string digit/*(string named digit)*/,string output/*(string named output)*/,int index,vector<string>&ans,string mapping[])
{

    //base case:when we have processed all digits
    if(index >= digit.length())
    {
        ans.push_back(output);
        return;
    }

    int number = digit[index] - '0'; //converting char to int
    
    string value = mapping[number];

    for(int i = 0; i<value.length(); i++)
    {
    output.push_back(value[i]);
    solve(digit,output,index+1,ans,mapping);
    output.pop_back();
    }

}


vector<string>letterC(string digits)
{
    vector<string>ans;

    if(digits.length() == 0)
    {
        return ans;
    }
    string output = ""; //currently empty string to hold

    int index = 0;

    string mapping[10] = {"", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"}; //made mapping of all number to their respective letters

    solve(digits,output,index,ans,mapping);
    return ans;
}

//we have to give all possible combinations when a number or some digits are pressed on a phone keypad starting from 2 as 0 and 1 dont have any mapping


/*string [i]string[j] 
j++ and then i++ after j = maximum index

*/

int main()

{
    string digits;

    cout<<"Enter digits: ";
    cin>>digits;

    vector<string>combo = letterC(digits);

    for(string s:combo)
    {
        cout<< s<< " ";
    }
    cout<<endl;

    return 0;
}