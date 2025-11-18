#include<iostream>
#include<vector>

using namespace std;

int monotoneIncreasingDigits(int n)
{

    //return the largest number less than or equal to n with monotone increasing digits

    
    string s = to_string(n);
    int mark =s.size();


    for(int i =n-2;i >=0 ;i--)
    {
        if(s[i] > s[i+1])
        {
            s[i]--;
            mark = i+1;
        }
    }

    for(int i = mark;i<s.size();i++)
    {
        s[i] = '9';
    }    

    return stoi(s);
}


int main()
{

    cout<<monotoneIncreasingDigits(10)<<endl;

    return 0;
    
}
