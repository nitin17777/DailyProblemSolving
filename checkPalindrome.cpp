//check palindrome
#include<iostream>
#include<vector>

using namespace std;

bool check(vector<char>&s)
{
    int start = 0;
    int end = s.size()-1;

    while(start<end)
    {
        if(tolower(s[start]) != tolower(s[end]))
        //if need to treat upper and lowercase in same manner,either convert  them into lowercase or upercase first

        {
            return false;
        }
        start++;
        end--;
}

return true;

}

int main()
{
    vector<char> n;
    char ch;
    cout<<"Enter the string: "<<endl;
    

    while(cin>>ch)
    {
        n.push_back(ch);
    }

    if(check(n))
    {
        cout<<"The string is palindrome."<<endl;

    }
    else
    {
        cout<<"The string is not palindrome."<<endl;
    }
    return 0;
}