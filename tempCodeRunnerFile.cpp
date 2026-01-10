#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int>&a)
{
    int n = a.size();
    if(n<=1)return true;

    /*
    In each step we can: decrease a[i-1] by 1 then increase a[i+1] by 1
                         decrease a[i+1] by 1 then increase a[i-1] by 1


    Return true if we can make all elements equal after any number of operations
    */
   vector<int>od,ev;
   for(int i =0;i<a.size();i+=2)ev.push_back(a[i]);

   for(int i =1;i<a.size();i+=2)od.push_back(a[i]);

   int odSum = accumulate(od.begin(),od.end(),0);
   int evSum = accumulate(ev.begin(),ev.end(),0);

   if((odSum % od.size() == 0 ) && evSum %ev.size() == 0 && (odSum/od.size()) == (evSum/ev.size()))return true;

   return false;
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
        for(auto&x: a)cin>>x;

        cout<<(solve(a)? "Yes" :"No")<<endl;
    }
    return 0;
}