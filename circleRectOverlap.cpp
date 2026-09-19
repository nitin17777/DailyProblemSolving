#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
{

    /*

    radius, xCenter and yCenter of circle is given

    x1,y1 -> Coordiantes of bottom left corner
    x2,y2 -> Coordinates of top right corner

    //min x,y and max x,y are availabale to us

    Determine if circle and rectangle are overlapping or not
    */
    // vector<int>dx = {1,-1,0,0};
    // vector<int>dy = {0,0,1,-1};

    // for(int i=0;i<4;i++)
    // {
    //     int nx = xCenter+dx[i];
    //     int ny = yCenter+dy[i];

    //     if(x1<=nx && x1>=xCenter)return true;//x Coordinate of rectangle is in between new and old coordinates of circle

    //     if(y1<=ny && y1>=yCenter)return true;
    // }
    // return false;


    //Point on rectangle closest to center of circle
    int closestX = max(x1,min(xCenter,x2));
    int closestY = max(y1,min(yCenter,y2));


    //Distance bw circle and closest rectangle point
    ll dx = xCenter-closestX;
    ll dy = yCenter-closestY;

    //By pythagoras theorem
    return dx*dx + dy*dy <= 1LL*radius*radius;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<(checkOverlap(1,0,0,1,-1,3,1)?"True":"False")<<endl;

    return 0;
}