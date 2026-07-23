#include<bits/stdc++.h>
#define ll long long
using namespace std;

int uniqueXorTriplets(vector<int>& a)
{
    int n = a.size();

    //Return the number of XOR triplets
    if(n<=2)return n;

    int msb = __lg(n);

    return pow(2,msb+1);
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a = {3,1,2};
    cout<<uniqueXorTriplets(a)<<endl;
    
    return 0;
}