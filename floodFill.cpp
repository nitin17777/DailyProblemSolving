#include<bits/stdc++.h>
#define ll long long
using namespace std;

void dfs(vector<vector<int>>& image, int r, int c,int oldColor, int newColor) {

    int m = image.size();
    int n = image[0].size();

    if (r < 0 || c < 0 || r >= m || c >= n)return;

    if (image[r][c] != oldColor)return;

    image[r][c] = newColor;

    dfs(image, r + 1, c, oldColor, newColor);
    dfs(image, r - 1, c, oldColor, newColor);
    dfs(image, r, c + 1, oldColor, newColor);
    dfs(image, r, c - 1, oldColor, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
{
    int oldColor = image[sr][sc];
    if(oldColor==color)return image;

    dfs(image,sr,sc,oldColor,color);

    return image;
}


      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<int>>a = {{1,1,1},{1,1,0},{1,0,1}};

    vector<vector<int>>ans = floodFill(a,1,1,2);

    for(auto & x:ans)
    {
        for(auto&y:x)cout<<y<<" ";

        cout<<endl;
    }
    return 0;
}