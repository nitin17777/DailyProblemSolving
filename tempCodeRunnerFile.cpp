#include<bits/stdc++.h>
using namespace std;

bool solve(string s)
{
    int n = s.size();
    /*

    We have 2 types of operations:

    1->We can appennd any letter to the end of the string 
    2->Copy continuous substring of already typed string and paste it at the end of the string 

    Determine if we can type the string s in strictly less than n operations

    */

    //IF the string has a repetitive substring of in length 2 , then yes, else no

   //Stores the first index where each length 2 substring appears
   unordered_map<string,int>fp;

   for(int i = 0;i<n-1;i++)
   {
        string sub = s.substr(i,2);

        if(fp.count(sub))
        {
            //checking non overlapping condition
            if(fp[sub]<i-1)return true;
        }
        else fp[sub] = i;
   }
   return false;;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

        cout<<(solve(s)?"Yes":"No")<<endl;
    }
    return 0;
}