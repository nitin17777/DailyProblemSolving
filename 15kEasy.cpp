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

        //In one operation -> coordinate of point changes by 1 exactly
        //Perform n ops of this type : Chooose any point and increase it's coordinate by 1


        //find max doubled area of triangle ABC

        int a = n/2;
        int b = n-a;
        cout<<a*b<<'\n';
    }

    return 0;
}