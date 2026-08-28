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
        int n,m;
        cin>>n>>m;

        vector<int>a(n),b(m);
        for(auto& x:a)cin>>x;
        for(auto& x:b)cin>>x;

        //Select 2 elements from 'a' : x,y and delete them
        //insert z: x<= z <= y

        //after performing these ops, arrange elements of a in order, determine if it is possible to make a equal to b


        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        //Each final element is basically a merge of earlier two elements

        //Since every element overall is unique -> So every element in b needs 2 elements in a  -> so n>=2m

        
    
        bool ok = (n>=2*m);
        for(int i =0;i<m && ok;i++)
        {
            if(b[i]<a[i] || b[i] > a[n-m+i])ok = false;
        }

        cout<<(ok?"YES":"NO")<<'\n';
    }
    return 0; 
}