#include<bits/stdc++.h>
#define ll long long
using namespace std;


int numberOfSpecialChars(string word)
{

    int n = word.size();

    //Special if : It appears in both lowercase and uppercase  + every lowercase occurence of that char is before first uppercase 
    vector<int>lastLow(26,-1);
    vector<int>firstUp(26,-1);

    for(int i = 0;i<n;i++)
    {
        char ch = word[i];
        if(islower(ch))lastLow[ch-'a'] = i;
        
        else 
        {
            if(firstUp[ch-'A'] == -1)
            {
                firstUp[ch-'A'] = i;
            }
        }
    }

    int ans = 0;

    for(int i = 0;i<26;i++)
    {
        if(firstUp[i] != -1 && lastLow[i] != -1)
        {
            if(lastLow[i] < firstUp[i])ans++;
        }
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<numberOfSpecialChars("aaAbcBC")<<endl;

    return 0;
}