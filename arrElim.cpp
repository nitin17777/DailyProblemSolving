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


        //Choose k distinct indices -> Calculate x = AND Of all k elements
        // Subtract x from each : ai .... ak
        
        //Find all such possible k indices : All elements of array a is equal to 0 

        //When we subtract x, that one bit disappears from all k elements

    
        //If bit i occurs in cnt[i] elements every option cna decrease this count by 0 or k

        //cnt[b] = no. of elements currently having bit b set
        vector<int>cnt(30,0);

        for(int i =0;i<n;i++)
        {
            cin>>a[i];

            //Counting how many elements contain each bit
            for(int b = 0;b<30;b++)
             {
                if(a[i] &&(1<<b))cnt[b]++;

                //In one elimination, we choose k elements and calculate their AND
            }
        }
    }
    return 0;
}