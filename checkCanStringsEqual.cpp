#include<bits/stdc++.h>
using namespace std;

bool canBeEqual(string s1, string s2)
{

    //Determine if we can make s1 and s2 equal 


    if(s1 == s2)return true;

    for(int i = 0;i<2;i++)
    {
        if(s1[i] != s2[i])
        {
            if(s1[i] != s2[i+2])return false; 
        }
    }

    if(s1[2] != s2[2])return false;
    if(s1[3] != s2[3])return false;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1 = "jegy",s2 = "jeyg";
    cout<<(canBeEqual(s1,s2)?"True":"False")<<endl;
    return 0;
}