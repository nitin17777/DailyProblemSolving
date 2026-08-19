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
        int n;
        cin>>n;

        string s;
        cin>>s;

        //alternating if no two adjacent chars are same
        //Transform s into alternating string by these ops:Delete any present char
        //But the characters we delete must be alternating

        //Determine min ops to make s alternating , return -1 if impossible

        int prev = 2;

        //since deletions must alternate -> Difference bw deleted 0s and 1s should be at max 1 :
        // |c0 - c1| <= 1
        // n0, n1 -> 0s and 1s in intial string 
        // k0 ,k1 -> 0s and 1s in final string 

        //If we want to make the string alternating, we have to use just one char from each group

        //We deleted: originalLen - compressedLen
        

        
    
    }

    return 0;
}