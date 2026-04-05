#include<bits/stdc++.h>
using namespace std;

bool judgeCircle(string moves) 
{
    int n = moves.size();

    // u = 0, d=1, r= 2, l =3
    vector<int>a(4);

    for(auto & x:moves)
    {
        if(x=='U')a[0]++;
        if(x=='D')a[1]++;
        if(x=='R')a[2]++;
        if(x=='L')a[3]++;
    }
    return (a[0] == a[1]) && (a[2] == a[3]);
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<(judgeCircle("UD")?"True" :"False")<<endl;
    
    return 0;
}