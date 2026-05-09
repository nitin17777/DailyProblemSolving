#include<bits/stdc++.h>
#define ll long long
using namespace std;

 int minimumSwap(string s1, string s2) {
        
        int xy = 0;
        int yx = 0;

        for(int i = 0; i < s1.size(); i++) {

            if(s1[i] == 'x' && s2[i] == 'y')
                xy++;

            else if(s1[i] == 'y' && s2[i] == 'x')
                yx++;
        }

        // Impossible case
        if((xy + yx) % 2 == 1)
            return -1;

        return (xy / 2) + (yx / 2) + (xy % 2) * 2;
    }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout<<minimumSwap("xx","yy")<<endl;


    return 0;
}