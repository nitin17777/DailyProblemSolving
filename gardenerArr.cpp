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
        
        /*
            Check if for two different subseq a and b : f(a) = f(b)

            f(x) = bitwise OR of all the numbers in sequence x

            ki = number of set bits in ci


            Determine if we can have 2 different subsequences such that tey same OR 

            If every element has a unique bit, two different subsequences cannot have same Or



        */

        int n;
        cin>>n;


        //c[i] will store positions of all set bits in c[i]
        vector<vector<int>>c(n);

        //count[p] = number of array elements in which bit p occurs
        //And bit whose count is 1 will be unique bit 

        vector<int>count(200001,0);

        for(int i = 0;i<n;i++)
        {
            int k; 
            cin>>k;

            c[i].resize(k);

            for(int j =0;j<k;j++)
            {
                int p;
                cin>>p;

                c[i][j] = p;

                count[p]++;
            }
        }

        //We just need to find if there exists any element having no unique bit

        bool possible = false;

        for(int i = 0;i<n;i++)
        {
            bool hasUB = false;

            
            //checking all bits belonging to c[i]
            for(int p : c[i])
            {
                if(count[p] == 1)
                {
                    hasUB = true;
                    break;
                }
            }

            if(!hasUB)
            {
                possible = true;
                break;
            }
        }
        cout<<(possible?"Yes":"No")<<'\n'; 
    }
    return 0;
}