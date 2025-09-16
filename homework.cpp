#include<iostream>
#include<string>
#include<deque>
using namespace std;


string homework(string a,string b,string c)// O(n) time compelxity
{
    //append all characters from b to a in any order

    //vlad can only add characters to beginning of the word 
    //dima can add them to end

    //they add characters in the order they appear in string b
    //find the final string 

    //if ci = V,then ith letter is added by Vlad
    //if ci = D,then ith letter is added by Dima

    deque<char>dq(a.begin(),a.end()); // making a deque with string a first

    for(int i=0;i<c.size();i++)
    {
        if(c[i] == 'V')
        {
            dq.push_front(b[i]);
        }
        else
        {
            dq.push_back(b[i]);
        }
    }

    return string(dq.begin(),dq.end());
}

/*  O(n^2)time complexity

string homework(string a,string b,string c)
{
    //append all characters from b to a in any order

    //vlad can only add characters to beginning of the word 
    //dima can add them to end

    //they add characters in the order they appear in string b
    //find the final string 

    //if ci = V,then ith letter is added by Vlad
    //if ci = D,then ith letter is added by Dima

    for(int i =0;i<c.size();i++)
    {
        if(c[i] == 'V')
        {
             a = b[i] + a;
        }
        else
        {
            a= a + b[i];
        }
    }
    return a;
}
    */

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        string a;
        cin>>a;

        int m;
        cin>>m;
        string b;
        cin>>b;

        string c;
        cin>>c;

        cout<<homework(a,b,c)<<endl;
    }

    

    return 0;
    
}
