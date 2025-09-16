#include<iostream>
using namespace std;

bool canTile(long long w,long long h,long long a,long long b,long long x1,long long y1,long long x2,long long y2)
{
    // Remove the check on w % a and h % b

    // Safe mod function to handle negative coordinates
    auto mod = [](long long x, long long m) {
        return (x % m + m) % m;
    };

    // Check if both existing tiles align with the grid
    if(mod(x1, a) != 0 || mod(y1, b) != 0) return false;
    if(mod(x2, a) != 0 || mod(y2, b) != 0) return false;

    return true;
}


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--)
    {
        long long w,h,a,b;

        long long x1,y1,x2,y2;
        cin>>w >> h>> a>>b;
        cin>>x1 >> y1>>x2>>y2;

        if (canTile(w, h, a, b, x1, y1, x2, y2)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
return 0;
}