#include<bits/stdc++.h>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n)
{
    int m = flowerbed.size();

    //Determine if we can place n more flowers into that flowerbed without violating the ruele

    //Count the valid places and compare with n
    int cnt = 0;

    for(int i = 0;i<m;i++)
    {
        if(flowerbed[i] == 0)
        {
            bool left = (i==0 || flowerbed[i-1] == 0);
            bool right = (i==m-1 || flowerbed[i+1] == 0);


            if(left && right)
            {
                flowerbed[i] = 1;
                cnt++;

                if(cnt>=n)return true;
            }
        }
    }
    return cnt>=n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>fl = {1,0,0,0,1};
    cout<<(canPlaceFlowers(fl,1)?"True":"False")<<endl;

    return 0;
}