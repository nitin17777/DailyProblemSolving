#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n, h, l;
    cin >> n >> h >> l;
    if (h > l) {
        swap(h, l);
    }
    int x;
    int cnth = 0, cntl = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x <= h) {
            cnth++;
        }
        if (x <= l){
            cntl++;
        }
    }
    cout << min(cnth, cntl / 2)<< '\n';
    
    }

    return 0;
}




