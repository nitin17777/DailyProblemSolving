#include<bits/stdc++.h>
using namespace std;

string pushDominoes(string s)
{

    ///Return the string representing the final state
    int n = s.size();
    string result="";

    //
    s = 'L' + s + 'R';
    int i = 0;//Left Pointer

    for(int j=1;j<s.size();j++)
    {
        if(s[j] == '.')continue;

        int gap = j-i-1;

        //Adding left boudnary while skipping first L 
        if(i>0)result += s[i];

        // Case 1: Same Force
        if(s[i] == s[j])
        {
            result += string(gap,s[i]);
        }

        //L...R collision -> No effect
        else if(s[i] =='L' && s[j] == 'R')
        {
            result+=string(gap,'.');
        }

            // if(s[i] == 'R' && s[j] =='L')
        else 
        {
            result += string(gap/2,'R');

            if(gap%2 == 1)
            {
                result+='.';
            }

            result+=string(gap/2,'L');
        }
        i=j;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<pushDominoes("RR.L")<<endl;

    return 0;
}