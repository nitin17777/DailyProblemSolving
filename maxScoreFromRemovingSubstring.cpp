#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<stack>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

    int maximumGain(string s, int x, int y) 
    {
        //remove ab and get x points
        //remove ba and get y points


        //we can check if ab are consecutive while pushing in stack if they will be consecutive, 
        //checking for ab
        stack<int>ss;
        for(int i = 0;i <s.size();i++)
        {
            if(ss.top() == 'a' && s[i] =='b')
            {
                ss.pop();
            }

            else
            {
                ss.push(s[i]);
            }
        }

    }






int32_t main()
{

    string s = "cdbcbbaaabab";
    int x = 2;
    int y = 1;

    int ans = maximumGain(s,x,y);


    return 0;

}