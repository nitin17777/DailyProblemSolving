#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int areaOfMaxDiagonal(vector<vector<int>>& arr)
{
    double maxDiagonal = 0.0;
    int maxArea = 0;
    for(auto&rect : arr)
    {
        int l = rect[0];
        int w = rect[1];

        double diagonal = l*l + w*w;

        int area = l*w;

        if(diagonal > maxDiagonal)
        {
            maxDiagonal = diagonal;
            maxArea = area;
        }

        else if(fabs(diagonal -maxDiagonal) < 1e-9)
        {
            maxArea = max(maxArea,area);
        }
    }
    return maxArea;

}

/*
int areaOfMaxDiagonal(vector<vector<int>>& arr)
{
    int m = arr.size();
    int n = arr[0].size();


    //Given two rectangles side,just give the area of rectangle with max diagonal length

    //access both the elements , find and compute square root, return the area of rectangle with greater diagonal
   int r1 = arr[0][0];
   int c1 = arr[0][1];

   int r2 = arr[1][0];
   int c2 = arr[1][1];

   int d1 = sqrt(r1*r1 + c1*c1);

   int d2 = sqrt(r2*r2 + c2 *c2);


   if(d1 > d2)
   {
    return r1 * c1;
   }
   else
   {
    return r2*c2;
   }
   
}
*/


int main()
{

    vector<vector<int>> arr = 
    {
        {9,3},{8,6}
    };

    cout<<areaOfMaxDiagonal(arr)<<endl;

    return 0;
    
}
