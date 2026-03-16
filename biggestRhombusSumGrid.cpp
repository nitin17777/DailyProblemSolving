#include<bits/stdc++.h>
using namespace std;

vector<int> getBiggestThree(vector<vector<int>>& g)
{
    int m = g.size(),n = g[0].size();
    vector<int>ans;

    /*Return the 3 biggest rhombus sum in the gird in sorted form


    [3,4,5,1,3],
    [3,3,4,2,3],
    [20,30,200,40,10],
    [1,5,5,4,1],
    [4,3,2,2,5]

    */


    //Brute force: Try all the possible rhombuses
    
    //Left inclined rhombuses

    set<int>s;
    for(int r = 0;r<m;r++)
    {
        for(int c = 0;c<n;c++)
        {
            //Size 0 rhombus
            s.insert(g[r][c]);

            //Now trying larger rhombuses
            for(int k = 1; ;k++)
            {

                //Boundary checks
                if(r-k<0 || r+k>=m || c-k<0 || c+k>=n)break;

                int sum  = 0;

                //Top -> Right
                for(int i=0;i<k;i++)
                {
                    sum += g[r-k+i][c+i];
                }

                //Right->botttom
                for(int i =0;i<k;i++)
                {
                    sum += g[r+i][c+k-i];
                }

                //Bottom ->left
                for(int i=0;i<k;i++)
                {
                    sum+=g[r+k-i][c-i];
                }

                //Left ->top
                for(int i = 0;i<k;i++)
                {
                    sum+=g[r-i][c-k+i];
                }
                s.insert(sum);
            }
        }
    }
    for (auto it = s.rbegin(); it != s.rend() && ans.size() < 3; it++)ans.push_back(*it);

    return ans;
}

// //Optimised approach using prefix sum
// vector<int> getBiggestThree(vector<vector<int>>& g)
// {
//     int m = g.size(),n= g[0].size();

//     //Diagonal prefix sum
//     vector<vector<int>>d1(m,vector<int>(n,0)),d2(m,vector<int>(n,0));


//     //Building right going diagonal prefix
//     for(int r = 0;r<m;r++)
//     {
//         for(int col = 0;col <n;col++)
//         {
//             d1[r][c] = g[r][c];

//             if(r>0 && c>0)d1[r][c] += d1[r-1][c-1];
//         }
//     }

//     //Building left going diagonal prefix
//     for(int r = 0;r<m;r++)
//     {
//         for(int col = n-1;col >= 0;col--)
//         {
//             d2[r][c] = g[r][c];

//             if(r>0 && c>0)d2[r][c] += d1[r-1][c+1];
//         }
//     }

//     set<int>s;

//     for(int r= 0;r<m;r++)
//     {
//         for(int c = 0;c<n;c++)
//         {
//             s.insert(g[r][c]);//Rhombus of size zero


//             for(int k = 1;;k++)
//             {
//                 if(r-k < 0 || r+k >= m|| c<k || c+k >=n)break;


//                 int sum = 0;


//                 //Coordinates of 4 vertices
//                 int tr = r-k, tc = c; // Top
//                 int rr = r,rc = c+k; // right 
//                 int br = r+k,bc = c; //Bottom
//                 int lr = r,lc = c-k; //Left 


//                 sum+=d1[rr][rc]

//             }
//         }
//     }


// }


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>g = {{3,4,5,1,3},{3,3,4,2,3},{20,30,200,40,10},{1,5,5,4,1},{4,3,2,2,5}};

    vector<int>ans = getBiggestThree(g);
    
    for(auto & x:ans)cout<<x<<" ";

    cout<<endl;

    return 0;
}