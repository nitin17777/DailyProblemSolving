#include<bits/stdc++.h>
using namespace std;

int minNum(string s)
{
    //choose 3 indices, 1<i<j<k<n, right shift or left shift the values cyclically

    //we have to determine number of operations required to sort the given binary string
    int count =0 ;
    for(auto ch : s)
    {
        if(ch == '0')count++;
    }
    return count-1;

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
    cout<<minNum(s)<<endl;

    }    
    return 0; 
}
