#include<bits/stdc++.h>
using namespace std;
#define ll long long 

bool solve(int a,int b,int x1,int y1,int x2,int y2)
{
    //To sheets has already been placed such that they don't overlap and each of them partially covers the roof

    //Determine if we can still the full roof without removing the already placed sheets
    //We have the coordinates of bottom left corners of already placed sheets

    if((x1 != x2 && (x2-x1)%a == 0) || y1 != y2 && (y2-y1)%b == 0)return true;

    return false;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--)
    {
        int w,h,a,b;
        cin>>w>>h>>a>>b;

        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        
        cout<<(solve(a,b,x1,y1,x2,y2)?"Yes":"NO")<<endl;

    }
    return 0;
}