#include<bits/stdc++.h>
#define ll long long
using namespace std;

int mySqrt(int x) {

        if(x == 0)
            return 0;

        int s = 1;
        int e = x;

        int ans = 0;

        while(s <= e) {

            long long mid = s + (e - s) / 2;

            if(mid <= x / mid) {
                ans = mid;
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        return ans;
    }

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<mySqrt(4)<<endl;

    return 0;
}