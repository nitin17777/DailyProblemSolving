#include<iostream>
#include<stack>
using namespace std;


//go and pop elements until the stack is empty
//and when the stack is empty place the required element and then again put the removed elements again

void printStack(stack<int>s)
{
    stack<int>temp;
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }

/*    while (!temp.empty()) 
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;
*/
}

 void solve(stack<int>& s,int x)
 {

    if(s.empty())
    {
        s.push(x);
        return;
    }


    int num = s.top();
    s.pop();

    //recursive call
    solve(s,x);
    s.push(num);


 }

 stack<int> pushb(stack<int> & myStack,int x )
{
    solve(myStack,x);
    return myStack;

}


int main()
{

    stack<int> s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);

    int num = 8;

    pushb(s1, num);


    cout << "Stack after inserting " << num << " at the bottom: ";
    printStack(s1);


    return 0 ;

}
