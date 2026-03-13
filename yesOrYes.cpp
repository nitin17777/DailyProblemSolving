#include<bits/stdc++.h>
using namespace std;

bool solve(string&s)
{

    //We can: relace two adjacent chars 
    //Return if it is possible to make convert this string into size of 1 without ever dealing with YY

    /*Y + N = Y
    // N + N = N

    So I both these cases, there is no effect on number of Y

    So if we initially have more than 2 Y -> No 
    else Yes
    */

    int cnt = count(s.begin(),s.end(),'Y');

    return cnt <=1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        string n;
        cin>>n;
        cout<<(solve(n)?"Yes":"No")<<endl;
        
    }
    return 0;
}