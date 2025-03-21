#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<string>s;

    s.push("Nitin");
    s.push("GG");
    s.push("Punera");


    cout<<"Top element: " <<s.top()<<endl;

    cout<<"Size: "<<s.size()<<endl;
    
}