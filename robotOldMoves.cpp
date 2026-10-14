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
        int a,b;
        cin>>a>>b;

        /*


        We can move one unit up or down and then move unit right

    
        Determine the number of steps after which robot has visited (a,b) 
        */
        
        //in one step it can cover root 2 distance 
        if(b>a+1)
        {
            cout<<-1<<'\n';
            continue;
        }

        if((a+b)%2 == 0)
        {
            cout<<a<<'\n';
            continue;
        }

        if((a+b)%2 == 1)
        {
            cout<<a+1<<"\n";
        }
    }

    return 0;
}