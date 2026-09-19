#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int n;
    cin>>n;

    int total=0;
    vector<int>a(n);
    for(auto& x:a)
    {

        cin>>x;
        total+=abs(x);
    }

    //We may partition this sequence into sequences b and c such that every element belongs to exactly one of the sequences

    //Max value of B-C

    cout<<total<<'\n';

    return 0;
}