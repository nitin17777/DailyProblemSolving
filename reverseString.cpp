#include<iostream>
#include<vector>
using namespace std;



//reversing a string
void reverse(vector<char>&s)

{
    int start = 0;
    int end = s.size()-1;
    while(start<end)
    {
        swap(s[start++],s[end--]);

    }
}

int main()
{

    vector<char>gg = {'j','k','l'};

   reverse(gg);

   for(char c : gg)
{
    cout<<c;

}
cout<<endl;

    return 0;
}