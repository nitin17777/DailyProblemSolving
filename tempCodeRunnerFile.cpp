#include<bits/stdc++.h>
using namespace std;

/*
bool isPalindrome(string s)
{
    int n =s.size();
    int i =0;j=n-1;
    while(i<=j)
    {
        if(s[i] != s[j])return false;
        
        else i++;
        j--;

    }
    return true;

}
    */

vector<int>subSeq(string s)
{
    int n = s.size();

    //find subsequence of p such that : 
    //It is increasing

    //Let x be string obtained by removing all characters of p from s with order of remaining characters, then x must be a palindrome

    //just return any subsequence that follows it else return -1


     
    //Removed substring must be non increasing , still successive elements can be greater

    //and now remaining string should be palindrome

    //return the indices of chars removed
    // if(isPalindrome(s))
    // return {};

    vector<int>ans;
    for(int i = 0; i <n;i++)
    {
        if(s[i] =='0')
        ans.push_back(i);
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

    vector<int>ans = subSeq(s);

    cout<<ans.size()<<endl;

    for(auto&an:ans)
    {
        cout<<an<<" ";
    }
    cout<<endl;
    }
    return 0;
}
