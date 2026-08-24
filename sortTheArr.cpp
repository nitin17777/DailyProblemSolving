#include<bits/stdc++.h>
#define ll long long
using namespace std;

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int>a(n);
    for(auto & x:a)cin>>x;

    //Determine if we can sort the array by just rversing one segment of it

    //Find the longest unsorted part of the string

    //Just check if 

    if(is_sorted(a.begin(),a.end()))
    {
        cout<<"yes"<<endl;
        cout<<'1'<<" "<<'1'<<endl;
        return 0;
    }

    //find the unsorted segment -> Sort it ->then check if the array is sorted or not

    int i =0;
    while(i<n-1)
    {
        if(a[i+1]<a[i])
        {
            break;
        }
        i++;
    }

    int left = i;
    
    while(i < n-1 && a[i]>a[i+1])i++;

    int right = i;

    //now sort the a[l]....a[r]
    reverse(a.begin()+left,a.begin()+right+1);

    if(is_sorted(a.begin(),a.end()))
    {
        cout<<"yes"<<endl;
        cout<<left+1<<" "<<right+1<<endl;
    } 
    else cout<<"no"<<endl;

    return 0;
}