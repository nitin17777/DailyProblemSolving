#include<bits/stdc++.h>
#define ll long long
using namespace std;

double dist(int ax,int ay,int bx,int by)
{
    return sqrt((ax-bx) *(ax-bx) + (ay-by)*(ay-by));
}

double solve(int px,int py,int ax,int ay,int bx,int by)
{
    /*

    if lantern's power is set to w, it illuminates a circle of radius w 

    Choose min w for power of lanterns such that there is path from point O to P which is completely illuminated 
    
    */
    double oa = dist(0,0,ax,ay);
    double ob = dist(0,0,bx,by);

    double pa = dist(px,py,ax,ay);
    double pb = dist(px,py,bx,by);

    double ab = dist(ax,ay,bx,by);
    
    double case1 = max(oa,pa);
    double case2 = max(ob,pb);

    double case3 = max({oa,pb,ab/2.0});
    double case4 = max({ob,pa,ab/2.0});

    return min({case1,case2,case3,case4});
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int px,py,ax,ay,bx,by;
        cin>>px>>py>>ax>>ay>>bx>>by;
    

        cout << fixed << setprecision(10) << solve(px,py,ax,ay,bx,by) << endl;
    }

    return 0;
}