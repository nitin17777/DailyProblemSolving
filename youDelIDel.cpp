#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;

        int n = s.size();


        //Alice wants final string should be lexicographically large as possible 
    
        //Bob wants final string to be lexico. small as possible

        //Determine final string if they play optimally

        //Alice-> Chooses 0 and deletes it
        //Bob choose an occurence of 1 and deletes it


        //Remove 1st occurence of 1 and 0 from left

        int pos0 = s.find('0');
        s.erase(pos0,1);

        int pos1 = s.find('1');
        s.erase(pos1,1);

        cout<<s<<'\n';
    }

    return 0;
}