#include<bits/stdc++.h>
using namespace std;

string reverseVowels(string s)
{
    //Reverse only the vowels present in the string 

    unordered_set<char>vowels = {'a','e','i', 'o' ,'u','A','E','I', 'O' ,'U'};


    int l = 0,r= s.size()-1;

    while(l<r)
    {
        //Moving left until we find a vowel
        while(l<r && vowels.find(s[l]) == vowels.end())l++;


        while(l<r && vowels.find(s[r]) == vowels.end())r--;

        if(l<r)
        {
            swap(s[l],s[r]);
            l++;
            r--;
        }
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<reverseVowels("IceCreAm")<<endl;
    return 0;
    
}