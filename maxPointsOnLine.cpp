#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int gcd(int a, int b) //Better to memorise this function
{
    if(b==0)
    return abs(a);
    else
    return gcd(b, a % b);
}

int maxPoints(vector<vector<int>>& points)
{
    //we are given cartesian points, we need to find the maximum number of points that lies on the same straight line
    int n = points.size();

    if(n <= 2)
    return n;

    int result = 0;

    for(int i =0; i<n;i++)
    {
        unordered_map<string,int>slopeCount; //to store count of each unique slope
        int maxPointsOnLine = 0;
        int samePoint = 1; // counts the point which are exactly same as point[i]


        for(int j =i+1; j<n; j++)
        {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            //checking for duplicate points
            if(dx == 0 && dy ==0)
            {
                samePoint++;
                continue;
            }

            //now reducing slope to it's simplest form
            int g = gcd(dx,dy);
            dx /= g;
            dy /= g;   
            
            if(dx < 0)
            {
                dx = -dx;
                dy = -dy;
            }
            if(dx == 0)//handling the case of vertical line where dy/dx = infinity
            {
                slopeCount["infinty"]++;
                maxPointsOnLine = max(maxPointsOnLine,slopeCount["infinity"]);
                continue;
            }

        string slopeKey = to_string(dy) + "/"+ to_string(dx);

        slopeCount[slopeKey]++;

        maxPointsOnLine = max(maxPointsOnLine, slopeCount[slopeKey]);

    }
    result = max(result,maxPointsOnLine + samePoint);
}
    return result;
}


int main()
{
    vector<vector<int>>points ={{0,1},{0,0},{0,4},{0,-2},{0,-1},{0,3},{0,-4}};

    // {{1,1},{2,2},{3,3},{4,4}};
    //{{1,1},{3,2},{5,3}{4,1},{2,3},{1,4}};

    int ans = maxPoints(points);

    cout<< ans <<endl;

    return 0;
}