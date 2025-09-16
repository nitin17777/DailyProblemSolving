#include<iostream>
#include<vector>
#include<string>
using namespace std;

string makeFancyString(string s) 
{
    string result;

   

    for(auto c:s)
    {
        int len = result.size();
        
        if(len >=2 && result[len-1] == c && result[len -2] == c)//already 2 sasme chars consecutively
        {
            continue; //in above situation skip doing anythinng and simply move forward
        }
        result.push_back(c);
        }
        return result;
}


        /* TIME LIMIT EXCEEDED

string makeFancyString(string s) 
{
    int count = 1;
    for(int i = 1;i<s.size();i++)
    {
        if(s[i] == s[i-1])
        {
            count++;  
        }
        else
        {
            count =1;
        }

        if(count == 3)
        {
            s.erase(i,1);
            i--;//because after deleting one index will be removed
            count = 2;
        }
    }
    return s;
}
    */


int main()
{
    string s = "aaabaaaa";
    string ans = makeFancyString(s);

    cout<<ans<<endl;
    return 0;
    
}
