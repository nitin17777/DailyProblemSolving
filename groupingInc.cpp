#include<bits/stdc++.h>
#define ll long long
using namespace std;

int score(vector<int>&a)
{
    int n = a.size();
    
    int cnt = 0;
    for(int i = 1;i<n-2;i++)
    {
        if(a[i] < a[i+1])cnt++;

    }
    return cnt;

}

int solve(vector<int>&a,int n)
{
    /*

    Split a into s and t : everhy element is present in one of them
    
    p(b) = number of indices : bi < bi+1 between 1 and b.size()-1

    Total penalty = p(s) + p(t)

    find the penalty is the above process is optimally done
        
    */
   if(n<=1)return 0;

    vector<int>b,c;

    b.push_back(a[0]);
    c.push_back(INT_MAX);
    int ans = 0;

    //b should have smaller back firstly
    for(int i = 1;i<n;i++)
    {
        //To ensure b is smaller always
        if(b.back() > c.back())swap(b,c);

        if(a[i] <= b.back())b.push_back(a[i]); 

        else if(a[i] <= c.back())c.push_back(a[i]);

        else
        {
            b.push_back(a[i]);
            ans++;  
        }
    }
    return ans;
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

        for(auto & x:a)cin>>x;

        cout<<solve(a,n)<<endl;
    
    }

    return 0;
}