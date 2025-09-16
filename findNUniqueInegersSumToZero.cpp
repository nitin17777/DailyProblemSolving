#include<iostream>
#include<vector>

using namespace std;


vector<int> sumZero(int n)
{
    //return an array of size n such that they add upto 0 and each element must be unique
    vector<int>arr;

    int toPush = n/2;

    if((n%2) != 0)
    {
        arr.push_back(0);         
    }

    for(int i= 1; i <= toPush;i++)
    {
        arr.push_back(i);
        arr.push_back(-i);  
    }
    return arr;
}


int main()
{

    int n = 5;
    vector<int>ans = sumZero(n);

    for(auto&an : ans)
    {
        cout<<an<<" ";

    }
    cout<<endl;

    return 0;
    
}
