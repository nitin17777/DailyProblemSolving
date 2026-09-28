#include<bits/stdc++.h>
#define ll long long
using namespace std;

  
//Have to revise it fully , but thoda thoda kam samajh aya optimisation ka tareeka
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;


    ////  COMPLETE BRUTRE FORCE APPROACH //////

    while(t--)
    {
        int n;
        cin>>n;

        vector<ll>a(n+1);
        for(int i = 1;i<=n;i++)cin>>a[i];

        string s;
        cin>>s;
        s='0'+s;//Making it 1 indexed

        int q;
        cin>>q;


        //ans[0] = XOR of elements with current bit = 0
        //ans[1] = XOR of elements with current bit = 
        ll ans[2] = {0,0};

        // prefix xor of a
        vector<ll>pref(n+1,0);

        for(int i = 1;i<=n;i++)
        {
            //XOR of all elements belonging to group 0 and 1

            ans[s[i]-'0'] ^= a[i];
            pref[i] = pref[i-1]^a[i];
        }

        //xor of all elements whose bit has been flipped odd number of times by type 1 queries
        ll massxor=0;

        while(q--)
        {
            int op;
            cin>>op;

            if(op==1)
            {
                int l,r;
                cin>>l>>r;

                //XOR of a[l...r]
                ll rangeXor = pref[r]^pref[l-1];


                //Optimal way to find current xor group very compactly -------***NEW
                massxor^=rangeXor;
            }

            else
            {
                int g;
                cin>>g;

                cout<<(massxor ^ ans[g])<<" ";
            }
        }
        cout<<'\n';
    }

    // while(t--)
    // {
    //     // X0 = XOR of all numbers from group 0
    //     // X1 = XOR of all numbers from group 1

    //     //So when answering the query of type 2 -> simply output X0 or X1


    // }
    return 0;
}