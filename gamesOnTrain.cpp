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
        int n;
        cin>>n;

        vector<int>a(n);
        for(auto& x:a)cin>>x;

        int maxi = *max_element(a.begin(),a.end());
        int mini = *min_element(a.begin(),a.end());

        cout<<maxi - mini +1<<'\n';



        /*


        ith tower has hi height 

        Find k such that we can make all the elements same

        
        */
    
    }

    return 0;
}