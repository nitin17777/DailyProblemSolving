#include<iostream>
#include<vector>

using namespace std;


int numberOfPairs(vector<vector<int>>& points)
{
    //Pairs with A is on upper left side of B
    //No other points lie in the retangle or line they make

    //count such pairs(A,B)

    //so A(x1,y1) and B(x2,y2) 
    // x1 > x2 && y2> y1

    //Also no other point xi , yi should be there inside the range of A and B's coordinate
    int n = points.size();

    int count = 0;

    for(int i = 0;i<n;i++)
    {
        int Ax = points[i][0],Ay = points[i][1];
        for(int j=0;j<n;j++)
        {
            if(i == j)continue;//When a number is compare to itself

            int Bx = points[j][0],By = points[j][1];

            //Condition: A is on upper left side of B
            if(Ax <= Bx && Ay>= By)
            {
                bool valid = true;

            for(int k = 0;k<n;k++)
            {
                if(k == i || k == j)
                continue;

                int Px = points[k][0], Py =points[k][1];

                if(Px >= Ax && Px <= Bx && Py >= By && Py <= Ay)
                {
                    valid = false;
                    break;
                }
            }
            if(valid)
            count++;
        }
    }

    }
    return count;
}


int main()
{

    vector<vector<int>>points ={
        {3,1},{1,3},{1,1}
    };
    cout<<numberOfPairs(points)<<endl;

    return 0;
    
}
