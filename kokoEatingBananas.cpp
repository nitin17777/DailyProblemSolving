#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll hours(vector<int>&a,int speed)
{
    ll sum = 0;

    for(int i =0;i<a.size();i++)
    {

        sum+= a[i]/speed;

        if(a[i]%speed != 0)sum++;
    }
    return sum;
}


int minEatingSpeed(vector<int>& a, int h)
{

    /*

    ith pile has p[i] bananas

    Gaurds will come back in 'h' hours
    Eating speed = k

    Return the min integer k such that she can eat all bananas within h hours

    
    */
    int left = 1;
    int right = *max_element(a.begin(),a.end());

    while(left<=right)
    {
        
        int mid = left+(right-left)/2;

        ll reqHrs = hours(a,mid);

        if(reqHrs>h)left=mid+1;

        else right = mid-1;
    }

    return left;

}
      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>p = {3,6,7,11};
    cout<<minEatingSpeed(p,8)<<endl;

    return 0;
}