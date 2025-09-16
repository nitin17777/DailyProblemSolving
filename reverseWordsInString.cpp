#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string reverseWords(string S)
{
    string ans = "";
    string temp = ""; 

    for(int i = S.length()-1; i>=0; i--)
    {
        if(S[i] == ' ')
        {
            reverse(temp.begin(),temp.end());
            ans += temp;
            ans.push_back(' ');
            temp = "";
        }
        else
        {
            temp.push_back(S[i]);
        }
    }
    reverse(temp.begin(),temp.end());
    ans += temp; 
    return ans;
}


int main()
{


    string S = "i like this program very much";
    string ans = reverseWords(S);
    cout<<ans<<endl;


    return 0;

}