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
        int n,w;
        cin>>n>>w;


        vector<int>cnt(21,0);
        for(int i = 0;i<n;i++)
        {
            int x;
            cin>>x;

            int p = 0;

            while((1<<p)!= x)p++;
            cnt[p]++;
        }

        int height = 0;
        int rem = n;


        while(rem > 0)
        {
            int space = w;
            height++;

            for(int p=20; p>=0;p--)
            {
                int width = 1<<p;


                while(cnt[p] > 0 && width <= space)
                {
                    space-=width;
                    cnt[p]--;
                    rem--;
                }
            }
        }
        cout<<height<<'\n';
    }
}
      

/*  TLE WITH THIS APPROACH 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n,w;
        cin>>n>>w;

        vector<int>a(n);
        for(auto&x:a)cin>>x;
        

        /*
        
        Height of each rectangle is 1, and each rectangle's width is in power of 2

        w is atleast as large aas width of the largest rectangle, we have to find the smallest height of this box  such that it is able to fit all given rectangle

        
    
        sort(a.rbegin(),a.rend());
        vector<bool>taken(n,false);

        int h=0;
        int totalTaken = 0;

        while(totalTaken < n)
        {
            int currWindow=w;
            for(int i = 0;i<n;i++)
            {
                if(a[i] <= currWindow && !taken[i])
                {
                    currWindow -= a[i];
                    totalTaken++;
                    taken[i] = true;
                }
            }
            h++;
        }
        cout<<h<<'\n';
    }

    return 0;
}
*/