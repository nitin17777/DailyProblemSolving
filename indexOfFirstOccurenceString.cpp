#include<iostream>
#include<vector>
#include<string>
using namespace std;

int strstr(string haystack,string needle)
{
    //we have to find the index of first occurence of needle
    int n = haystack.size();
    int m = needle.size();
    
    if(m == 0)return 0;

    for(int i = 0; i <= n-m; i++)
    {
        if(haystack.substr(i,m) == needle)
        {
            return i;

        }
    }

    return -1; //when no such needle is found

}

int main()
{
    string haystack = "a";
    string needle = "a";

    int ans = strstr(haystack,needle);

    cout<<ans<<endl;

    return 0;
    
}
