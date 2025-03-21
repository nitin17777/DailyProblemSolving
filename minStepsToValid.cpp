#include<iostream>
#include<stack>
using namespace std;


int findMin(string str)
{
    if(str.length() % 2 == 1)
    {
        return -1;
    }

    stack<char>s;
    for(int i = 0; i<str.length(); i++)
    {
        char ch = str[i];

        if(ch == '(')
        {
            s.push(ch);
        }

        else
        {
            //ch is closed brace
            if(!s.empty() && s.top() == '(')
            {
                s.pop();
            }
            else
            {
                s.push(ch);  
            }
        }
    }
    
    int a = 0,b= 0;

    while(!s.empty())
    {
        if(s.top() == '(')
        {
            b++;
        }
        else
        {
            a++;
        }
        s.pop();
    }

    int ans = (a+1)/2 + (b+1)/2;

    return ans;

}


int main()
{
    string input = "((((";

    int result = findMin(input);

    if (result == -1)
    {
        cout << "Cannot be balanced!" << endl;
    }
    else
    {
        cout << "Minimum reversals needed: " << result << endl;
    }

    return 0;
}