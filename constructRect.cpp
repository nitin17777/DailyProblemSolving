#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> constructRectangle(int area)
{
    
    int w = sqrt(area);

    while (area % w != 0)w--;

    return {area / w, w};
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>ans = constructRectangle(4);

    for(auto&x:ans)cout<<x<<" ";

    cout<<'\n';

    return 0;
}