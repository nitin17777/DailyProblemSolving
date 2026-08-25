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


        /*

        Different houses cnan be located in the same point 

        Summary distance from all the houses to exhibition is minimal

        distance between two points (x1,y1),(x2,y2) is |x1−x2|+|y1−y2|
        */

        vector<int>x(n),y(n);

        for(int i=0;i<n;i++)cin>>x[i]>>y[i];
        
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());

        ll goodX = x[n/2]-x[(n-1)/2]+1;
        ll goodY = y[n/2]-y[(n-1)/2]+1;

        cout<<goodX*goodY<<'\n';
    }

    return 0;
}