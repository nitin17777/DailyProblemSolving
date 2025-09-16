#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string sortVowels(string s)
{
    //we have to sort vowels according to ascii values and vowels can only rearrange in vowel position only

    string vowels = "aeiouAEIOU";

    vector<char>v;

    for(char ch : s)
    {
        if(vowels.find(ch) != string::npos)
        {
            v.push_back(ch);
        }
    }

    sort(v.begin(),v.end());

    int idx= 0;

    for(char&ch :s)
    {
        if(vowels.find(ch) != string::npos)
        {
            ch = v[idx++];
        }
    }
    return s;
   
}


int main()
{
    string s ="lEetcOde";

    string ans = sortVowels(s);

    cout<<ans<<endl;

    return 0;

}

