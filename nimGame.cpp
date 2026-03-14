#include<bits/stdc++.h>
using namespace std;

bool canWinNim(int n)
{
    return n%4 !=0;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<canWinNim(4)<<endl;
    return 0;
}