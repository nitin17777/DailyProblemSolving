#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;


//recursive approach
void rev(queue<int>&q)
{
    
//base case
if(q.empty())
{
    return;
}

//removing the fir
int element = q.front();
q.pop();

rev(q);

q.push(element);


}



/*

using stack and queue


queue<int> rev(queue<int>q)
{
    //remove and put elements from queue to stack and again from stack to queue

    stack<int> s;

    while(!q.empty())
    {
        int element  = q.front();
        q.pop();
        s.push(element);
    }

    while(!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    return q;   

}
    */

int main()
{
    queue<int>q;

    q.push(3);
    q.push(5);
    q.push(7);
    q.push(8);

    rev(q);

    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }


    //queue<int>ans =  rev(q);

    /*
    
    cout<<"Reverse Queue is: ";
    while(!ans.empty())
    {
        cout<<ans.front()<<" ";
        ans.pop();
    }
        
    cout<<endl;*/
    return 0;

}