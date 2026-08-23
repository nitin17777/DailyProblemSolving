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

        string a,b;
        cin>>a>>b;

        //Each cell is covered with either red or black
        //We want to repaint cells of this table so that there exists one way to partition all cells into n pairs : cells in each pair have same color
        // cells in each pairs such that 

        //Return minimum number of cells that needs to be painted
    
        //We want to make n pairs: with pairs having same color and they should be sharing same side

        
        //A cell should be painted if both of it's neighbour have other color


        int ans = 0;
        for(int i=0;i<n;)
        {
            if(a[i] == b[i])i++;

            else if(i+1< n && a[i] == a[i+1] && b[i] == b[i+1])i+=2;

            else 
            {
                ans++;
                i++;
            }


            // if((a[i] != a[i+1] ) && a[i]!=b[i])ans++;
            // if((b[i] != b[i+1] ) && a[i]!=b[i])ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
