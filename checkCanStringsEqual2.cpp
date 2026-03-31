#include<bits/stdc++.h>
using namespace std;

bool checkStrings(string s1, string s2)
{
    int n = s1.size();

    //Choose indices : j-i is even, then swap them

    //Determine if we can make both the strings same

    //Is size of both sets same


    vector<int>odd1(26,0),even1(26,0);

    for(int i = 0;i<n;i++)
    {
        if(i%2 == 0)even1[s1[i]-'a']++;
        else odd1[s1[i]-'a']++;
    }

    vector<int>odd2(26,0),even2(26,0);

    for(int i = 0;i<n;i++)
    {
        if(i%2 == 0)even2[s2[i] -'a']++;
        else odd2[s2[i] - 'a']++;
    }
    return (odd1 == odd2) && (even1 == even2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1 = "abcdba", s2 = "cabdab";
    cout<<(checkStrings(s1,s2)?"True":"False")<<endl;
    return 0;
}