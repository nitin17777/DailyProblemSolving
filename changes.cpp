#include<iostream>
using namespace std;

//in the given string S replace the charcters of S in S1 with s2 and return the string


/*
S  = "abcxyzxyzdef"
S1 = "xyz"
S2 = "123"


Modified string: abc123123def

*/

string replace(string S ,string S1,string S2)
{
    int i = 0;
    int N = S.length(), M = S1.length();


    string result = "";

    //first loacate the position of s1 in s 
    //then replace with s2

    while(i<N)
    {
        bool match = true;


        for(int j = 0; j<M; j++)
        {
            if((i+j >= N) || S[i+j] != S1[j])
            {
                match = false;
                break;
            }
        }

        if(match)
        {
            result += S2;
            i += M;
        }

        else
        {
            result += S[i];
            i++;
        }

    }
return result;
}


int main() {

    string s = "Bennett is good";

    string s1 = "Bennett";

    string s2 = "BU";

    string ans = replace(s,s1,s2);

    cout<<ans<<endl;

    return 0;
}