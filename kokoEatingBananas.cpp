#include<bits/stdc++.h>
#define ll long long
using namespace std;


int hours(vector<int>&a,int num)
{


    int sum = 0;

    for(int i =0;i<a.size();i++)
    {

        sum+= (a[i]/num);
    }
    return sum;

}


int minEatingSpeed(vector<int>& a, int h)
{
    int n=a.size();

    /*

    ith pile has p[i] bananas

    Gaurds will come back in 'h' hours
    Eating speed = k

    Return the min integer k such that she can eat all bananas within h hours

    
    */



    sort(a.begin(),a.end());

    int left = 0,right = n-1;

    int mid = (right-left)/2;
    while(left<=right)
    {
        
        int num = hours(a,a[mid]);

        if(num>h)left = mid+1;
        else right = mid-1;

    }

    return mid;

}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>p = {3,6,7,11};
    cout<<minEatingSpeed(p,8)<<endl;

    return 0;
}