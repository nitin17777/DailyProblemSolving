#include<iostream>
#include<stack>
using namespace std;

bool matches(char s,char e)
{

    return(s == '{' && e == '}') ||

    (s == '[' && e == ']') ||

    (s == '(' && e == ')');

    // since || is connecting them so it will be true if any one statement comes out to be true

    


/*

    if(s == '{' && e == '}')
    {
    return true;
    }
    else
    return false;

    if(s == '[' && e == ']')
    {
    return true;
    }
    else
    return false;

    if(s == '(' && e == ')')
    {
    return true;
    }
    else
    return false;

    */


}


bool isValidPar(string exp)
{

    stack<char>s;

    for(int i = 0; i < exp.length(); i++)
    {

        char ch = exp[i];

        //if opening bracket, push in stack
        //if closing bracket,stacktop check and pop

        if(ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }
        else
        { // for closing brackets

            if(s.empty())
            return false;
            

              char top = s.top();
                if(matches(top,ch))
                {
                    s.pop();

                }
                else
                {
                    return false;

                }                
        }
    }

    return s.empty();

}



int main()
{

    string para ="(]" ;

    if(isValidPar(para))
    {
        cout<<"Valid Paranthesis."<<endl;


    }

    else
    {
        cout<<"Invalid Paranthesis"<<endl;

    }

    return 0;

}