#include<bits/stdc++.h>
using namespace std;

//convert given roman numbers to integers
int rti(string s)
{
    unordered_map<char,int>roman = 
    {
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
    };
    int n = s.size();
    int result = 0;
/*

more optimised because we are iterating from right 

                for (int i = s.length() - 1; i >= 0; i--) {
                    int currentValue = romanValues[s[i]];  
        
                    if (currentValue < prevValue) {
                        integer -= currentValue;
                    }
                    else {
                        integer += currentValue;
                    }
                    prevValue = currentValue;
                }
                return integer;
            }
        };
*/        

    for(int i = 0; i< n-1; i++)
    {
        if((roman[s[i]]) < roman[s[i+1]])
        {
            result -= roman[s[i]];
        }
        else
        {
            result += roman[s[i]];
        }

    }
    return result;
}

int main()
{
    string s = "MC";

    int ans = rti(s);

    cout<<ans<<endl;

    return 0;

}