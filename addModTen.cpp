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
        bool special = false;

        for(auto &x:a)
        {
            cin>>x;
            if(x%10 == 0 || x%5 == 0)special = true;
        }

        if(special)
        {
            for(auto&x:a)x+=x%10;

            bool same = true;
            for(int i=1;i<n;i++)
            {
                if(a[i] != a[0])
                {
                    same=false;
                    break;
                }
            }
            cout<<(same?"Yes" : "No")<<'\n';
        }

        //If a number is not in the special case (its last digit is neither 0 nor 5), it will eventually enter the cycle:
        else
        {
            for(auto&x:a)
            {
                while(x%10 != 2)x+=x%10;
            }

            bool same = true;
            for(int i = 1;i<n;i++)
            {
                if(a[i] %20 != a[0]%20)
                {
                    same = false;
                    break;
                }
            }
            cout<<(same?"Yes":"No")<<'\n';
        }
        /*

        We can do this operation any number of times : ai = ai + (ai mod 10)
        
        Determine if we can make all elements equal by applying multiple op
        */


        //the final same element would be greater than equal to the maximum element 


        //an element with remainder 5 can be replaced just once     
    }

    return 0;
}