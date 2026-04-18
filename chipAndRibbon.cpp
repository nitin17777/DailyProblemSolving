#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<int>&a,int n)
{
    /*

    First turn -> Places chip in 1st cell of ribbon

    in other turns : Move the chip to next cell , and this action would be impossible if chip is already in last cell
    OR 
    choose any cell x and teleport chip into that cell
    
    
    */

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

        cout<<solve(a,n)<<endl;    
    }

    return 0;
}