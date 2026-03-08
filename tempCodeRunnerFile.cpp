#include<bits/stdc++.h>
using namespace std;


pair<int,int> solve(string &s)
{

    int n = s.size();

    int ones=count(s.begin(),s.end(),'1');
    if(ones ==0)return{0,0};

    int first = -1, last = -1;
    for(int i = 0;i<n;i++)
    {
        if(s[i] == '1')
        {
            if(first == -1)first=i;
            last = i;
        }
    }

    int mini = ones;
    int maxi = last-first+1;



    // for(auto&x:s)
    // {
    //     if(x=='1')ones++;
    // }

    // //Counting the number of places between two 1s 
    // int freeOnes=0,freeZeros=0;

    // for(int i = 1;i<n-1;i++)
    // {
    //     if(s[i-1] == '1' && s[i+1] == '1'&& s[i] =='1')freeOnes++;

    //      if(s[i-1] == '1' && s[i+1] == '1' && s[i] == '0')freeZeros++;
    // }


    // int mini = ones-freeOnes;
    // int maxi = ones+freeZeros;
     return {mini,maxi};

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
        string s;
        cin>>s;

        pair<int,int>ans = solve(s);
        cout<<ans.first<<" "<<ans.second<<endl;
        
        
    }
    return 0;
}