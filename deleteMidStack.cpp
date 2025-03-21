#include<iostream>
#include<stack>

using namespace std;


void solve(stack<int>& inputStack,int count , int size)
{


    //base case
    if(count == size/2)

    {
        inputStack.pop();
        return;

    }


    //storing the numbers until we reach mid
    int num = inputStack.top();
    inputStack.pop();

    //recursive call
    solve(inputStack,count+1,size);

    inputStack.push(num);




}

void deleteMid(stack<int>&inputStack,int N)
{
    int count = 0;
    solve(inputStack,count ,N);

}


int main()
{
    
    stack<int>ts;
    ts.push(10);
    ts.push(20);
    ts.push(43);
    ts.push(91);

    cout<<"Stack before deleting mid: ";

    stack<int>temp = ts;

    while(!temp.empty())
    {
        cout<<temp.top()<<" ";
        temp.pop();

    }
    cout<<endl;


    deleteMid(ts,ts.size());
    

    cout<<"Stack after deleting: ";
    temp =ts;


    while(!temp.empty())
    {
        cout<<temp.top()<<" ";
        temp.pop();

    }

    cout<<endl;





    return 0;

}