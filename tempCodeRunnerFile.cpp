#include<bits/stdc++.h>
using namespace std;

double largestTriangleArea(vector<vector<int>>& points)
{
    //find the triangle with largest area possible using any 3 points


    //area = 0.5 * height * base
    //to maximise the area of triangle 
    double maxArea = 0.0;
    int n  = points.size();

    for(int i = 0;i<n;i++)
    {
        for(int j = i+1;j<n;j++)
        {
            for(int k = j+1;k<n;k++)
            {

                //Area= 0.5 * ∣x1(y2−y3)+x2(y3−y1)+x3(y1−y2)∣

                double area = 0.5 * fabs(
                    points[i][0] * ( points[j][1] - points[k][1])+
                    points[j][0] *(points[k][1] - points[i][1])+ 
                    points[k][0] *(points[i][1] - points[j][1])
                );

                maxArea = max(area,maxArea);

            }
        }

    }
    return maxArea;
}


int main()
{

    vector<vector<int>>points = {
        {0,0},{0,1},{1,0},{0,2},{2,0}
    };

    double ans = largestTriangleArea(points);
    cout<<ans<<endl;

    return 0;

}