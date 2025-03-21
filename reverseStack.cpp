#include<iostream>
#include<stack>

using namespace std;

void printStack(stack<int>s)
{
    stack<int>temp;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}



void reverse(stack<int>&s)
{
    stack<int>temp;

    while(!s.empty())
    {
        temp.push(s.top());
        s.pop();

    }
}



//another approach using recursion

void insertAtBottom(stack<int>&s, int x)

{
    if(s.empty())
    {
        s.push(x);
        return;

    }

    int topElement = s.top();
    s.pop();


    insertAtBottom(s,x);
    s.push(topElement);

}

/*
void reverse(stack<int>&s)
    {
    if(s.empty())
    {
        return;

    }

    int topElement = s.top();
    s.pop();

    reverse(s);

    insertAtBottom(topElement);
}

*/

int main()
{
    stack<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    reverse(s1);


    cout << "Stack after reversing: ";
    printStack(s1);

    return 0;

}