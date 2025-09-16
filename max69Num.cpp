#include<iostream>
#include<string>
using namespace std;

int maxNum(int num)
{
    //we have to return the max num by switching at most one siz
    string str = to_string(num);

    for(int i = 0;i < str.size();i++)
    {
        if(str[i] == '6')
        {
            str[i] = '9';
            break;
        }
    }
    
    return stoi(str);
}

int main()
{
    int num = 9669;
    int ans = maxNum(num);

    cout<<ans<<endl;

    return 0;
    
}
