#include<bits/stdc++.h>
#define ll long long
using namespace std;


int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d)
{
    int ans = 0;

    for(int x:arr1)
    {
        bool valid = true;

        for(int y :arr2)
        {
            if(abs(x-y)<=d)
            {
                valid = false;
                break;
            }
        }

        if(valid)ans++;
    }
    return ans;
}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a1 = {4,5,8},a2= {10,9,1,8};
    cout<<findTheDistanceValue(a1,a2,2)<<endl;

    return 0;
}