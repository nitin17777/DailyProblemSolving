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

        vector<int>a(n),b(n);

        for(auto & x:a)cin>>x;
        for(auto & x:b)cin>>x;


        for(int i = 0;i<n;i++)
        {
            if(a[i]>b[i])
            {
                int temp = a[i];
                a[i]=b[i];
                b[i]=temp;
            }
        }

        int maxiA = *max_element(a.begin(),a.end());

        int totalB = accumulate(b.begin(),b.end(),0);

        cout<<maxiA + totalB<<'\n';
        // 1 2 3 4 5 6 7 8
   }
    return 0;
} 

// 2+4+6+8+7