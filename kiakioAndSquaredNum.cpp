#include<bits/stdc++.h>
#define ll long long
using namespace std;

int next(int x)
{
    int ans=0;
    while(x)
    {
        int d = x%10;
        ans+=d*d;
        x/=10;
    }
    return ans;
}

ll nCr(ll n, ll r)
{
    r = min(r, n - r);

    ll ans = 1;

    for (ll i = 1; i <= r; i++)
        ans = ans * (n - i + 1) / i;

    return ans;
}

bool isHappy(int x)
{
    while(x!=1 && x!=4)x=next(x);
    
    return x==1;
}


      
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
        for(auto &x:a)cin>>x;

        /*

        n lighthouses stand on cliffs facing the sea

        Rule : if lighthouse shows x tonight -> tomorrow it will show sum of squares fo decimal digit of x


        Night 0 -> lighthouse i shows ai number ai and from that night law is applied on every night  forever

        Tune if: i and j shows exactly same number on every single night

        Determine how many such pairs exist


        1-> If two elements are same -> Then they will form a pair
        2-> Proces each number and determine if it can go to 1 ever or not

        
        */

        // unordered_map<int,int>freq;
        // for(auto&x:a)freq[x]++;

        // vector<bool>available(*max_element(a.begin(),a.end()),true);

        // for(auto[num,f]:freq)
        // {
        //     if(f>=2)
        //     {
        //         ans+= nCr(f,2);
        //         available[num]=false;
        //     }
        // }

        // //Sum of squares either reaches 1 or go on in that fixed cycle 

        // set<int>st = {2,4, 16, 37, 58, 89, 145, 42, 20};

        // ll cnt=0;

        // for(auto &x:a)if((st.find(x)==st.end() )&& available[x])cnt++;

        // if(cnt>1)ans+=nCr(cnt,2);

        // cout<<ans<<'\n';

        //Count happy ones,
        //If unhappy check it's (frequency>1) and do : ans+=nCr(thatFreq,2)


        //IF they are unhappy but happy frequency greater than 1 and add nCr(unhappy,2)to ans;

        unordered_map<int,int>freq;
        for(auto &x:a)freq[x]++;

        int ans = 0;
        int happy=0;
        for(auto&x:a)
        {
            if(isHappy(x))happy++;

            else
            {
                if(freq[x] > 1)ans+=nCr(freq[x],2);
            }
        }

        if(happy>=2)ans+=nCr(happy,2);
        cout<<ans<<'\n';
    }

    return 0;
}