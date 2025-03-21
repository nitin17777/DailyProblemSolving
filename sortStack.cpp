#include<iostream>
#include<stack>

using namespace std;


void sortedInsert(stack<int>&stack ,int num)
{
    //base case

    if(stack.empty() || (!stack.empty() && stack.top() <num))
    {
        stack.push(num);
        return;
    }


    int n = stack.top();

    stack.pop();

    sortedInsert(stack,num);
    stack.push(n);
     
}

void sortStack(stack<int>&stack)
{

    //base case
    if(stack.empty())
    {
        return;
    }


    int num = stack.top();

    stack.pop();

    //recursive call

    sortStack(stack);

    sortedInsert(stack,num);

}

void printStack(stack<int>s)
{
    stack<int>temp;

    while(!s.empty())
    {

        temp.push(s.top());
        s.pop();
    }

    while(!temp.empty())
    {
        cout<<temp.top()<<" ";
        temp.pop();

    }
    cout<<endl;
    
    
}

int main()

{

    stack<int> s1;

    s1.push(8);
    s1.push(2);
    s1.push(1);
    s1.push(4);
    s1.push(5);

    sortStack(s1);


    cout << "Stack after sorting: ";
    printStack(s1);

    return 0;

}
