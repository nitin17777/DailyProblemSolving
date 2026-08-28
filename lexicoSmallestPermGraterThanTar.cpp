#include<bits/stdc++.h>
#define ll long long
using namespace std;

string lexGreaterPermutation(string s, string target)
{
    int n = s.size();


    //Return lexicographically smallest perm of s greater than target,esle return empty string

    vector<int>freq(26,0);

    for(char c:s)freq[c-'a']++;

    //Build s as close to target as possible while making it strictly greater than target


    for(int i = n-1;i>=0;i--)
    {

        //Trying to ma+1 ke i equal to target[i]
        int c = target[i]-'a';


        if(freq[c]>0)
        {
            freq[c]--;
            continue;
        }
        //We cannot


    }

    

}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<lexGreaterPermutation("abc","target")<<endl;


    return 0;
}