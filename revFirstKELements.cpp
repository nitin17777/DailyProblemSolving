#include<bits/stdc++.h>
using namespace std;

// reversing first k elements of a queue
queue<int> revk(queue<int>q,int k)
{

//1-> popping first k elements from queue and putting them in stack
stack<int>s;

for(int i = 0; i<k; i++)
{
    int val= q.front();
    q.pop();
    s.push(val);
}

//2-> fetch from stack and push into q
 
while(!s.empty())
{
    int val = s.top();
    s.pop();
    q.push(val);
    
}

//3-> fetch first n-k(unreversed) elements from queue and pushback
{
    int t= q.size()- k;
    while(t--) // untill all unreversed elements are removed and added back to queue
    {
        int val = q.front();
        q.pop();
        q.push(val);

    }
}


return q;

}



int main()
{

    queue<int>q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int k = 2;

    queue<int>ans = revk(q,k);

    while(!ans.empty())
    {
        cout<<ans.front()<<" ";
        ans.pop();
    }

    cout<<endl;
    


    return 0;

}