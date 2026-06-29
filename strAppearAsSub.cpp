#include<bits/stdc++.h>
#define ll long long
using namespace std;

int numOfStrings(vector<string>& p, string word)
{
    //For each string in p -> check if they appear as substirng in "word"
    int ans = 0;
    for(auto & x:p)ans+=word.find(x)!= string::npos;
    
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string>p = {"a","abc","bc","d"};
    cout<<numOfStrings(p,"abc")<<'\n';


    return 0;
}