#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool solve(string a,string b,int n)
{
    //We can swap ai and bi any number of times, determine if we can make regular bracket sequence

    // avails can never be negative 
    
    //We have to check at every index if we need a swap or not

    //This condition must be satisfied for valid sequence
//    if(a[0] != '(' && b[0] != '(' )return false;
   
//    if(a[n-1] != ')' && b[n-1] != ')')return false;

//    int cnt1 = 1,cnt2 = 1;

//    for(int i =1;i<n;i++)
//    {
//         //if it gets negative and another one is also same, so no exchange possible
//         if(a[i] == b[i])
//         {
//             if(a[i] == '(')
//             {
//                 cnt1++;
//                 cnt2++;
//             }

//             else cnt1--,cnt2--;
//         }


//         else
//         {
//             cnt1++;
//             cnt2--;

//             if(cnt2 < 0)
//             {
//                 cnt1-=2;
//                 cnt2+=2;
//             }
//         }

//         if(cnt1<0 || cnt2 <0)return false;
//    }
//    return cnt1==0 && cnt2 == 0;

 return (
        a[0] == '(' &&
        b[0] == '(' &&
        a[n-1] == ')' &&
        b[n-1] == ')'
    );
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

        string a,b;
        cin>>a>>b;

        cout<<(solve(a,b,n)?"Yes":"No")<<endl;
    }

    return 0;
}