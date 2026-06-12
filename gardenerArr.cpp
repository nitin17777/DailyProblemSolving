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

        //We have to determine if there are two subsequences : f(a) == f(b) -> f(x) = bitwise OR of all the numbers in subsequence


        vector<vector<int>>nums(n);//nums[i] Stores all set bit positions of ith number 

        vector<int>freq(200001,0);//Stores the frequency of set bit positions


        for(int i = 0;i<n;i++)
        {
            int k;
            cin>>k;

            nums[i].resize(k);


            for(int j = 0;j<k;j++)
            {
                cin>>nums[i][j];

                freq[nums[i][j]]++;
            }
        }



        bool possible = false;

        for(int i = 0;i<n;i++)
        {
            bool hasUniqueBit = false;

            for(int bit : nums[i])
            {
                //If a bit is present in only one of the number ->then impossible
                if(freq[bit] == 1)
                {
                    hasUniqueBit = true;
                    break;
                }
            }

            if(!hasUniqueBit)
            {
                possible = true;
                break;
            }
        }

        if(possible)cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}