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
        string s,t;
        cin>>s>>t;

        //Swap ith digit of x and y  any number of times

        // And maximise the product of x and y

        //we need to move numbers much closer and this would be main idea ig

    
        //We can do so by decreasing the bigger number and increasing the smaller number
        int n = s.size();

        int k=0;
        while(k<n && s[k]==t[k])k++;

        if(k<n)
        {
            if(s[k] < t[k])swap(s,t);
        }

        for(int i = k+1;i<n;i++)if(s[i] > t[i])swap(s[i],t[i]);
    
        //previous value big -> smaller value now 
        //Smaller value now -> bigger value next

        cout<<s<<'\n';
        cout<<t<<'\n';
    }

    return 0;
}