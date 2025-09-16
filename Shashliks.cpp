#include<iostream>
using namespace std;

long long Shashliks(long long k,long long a,long long b,long long x,long long y)
{
    //we have 2 shashlik with required temperature a, b and temperature dop after cooking x,y and initial temperature k

    // ----//we have to determine the max total number of portions of shashlik that can be cooked

    //we will always look to cook one with less temperature drop first

    if(x>y)
    {
        swap(a,b);
        swap(x,y);
    }

    long long count =0;

    if(k >= a)//firstly trying to cook as many as more effecient type possible
    {
        long long cook1 = (k-a)/x+1;
        count += cook1; // add the number of shash of type 1 we can cook

        k -= cook1*x; //and decrease the temperature acccordingly to cook1
    }

    if(k>=b)
    {
        long long cook2 = (k-b) / y+1;
        count+=cook2;    
    }
    return count;
}

int main(){

   ios::sync_with_stdio(false);
   cin.tie(NULL);

   int t;
   cin>>t;

   while(t--)
   {
    long long k,a,b,x,y;
    cin>> k>> a>> b>> x>> y;

    cout<<Shashliks(k,a,b,x,y)<<endl;

   }


    return 0;

}