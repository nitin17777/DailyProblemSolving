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

        int c = 0;

        //Find such perm: cfinal will not be 1

        //either add: i*pi or subtract i*pi or do nothing
    
        //Putting even at odd places and odd numbers at even places, so 1 won't ever come
        for(int i = 1;i<=n;i+=2)
        {
            cout<<i+1<<" "<<i <<" ";
        }
        cout<<endl;
    }

    return 0;
}