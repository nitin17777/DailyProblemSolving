#include<iostream>
#include<vector>
using namespace std;

vector<int>reverse(vector<int>v)
{
    int s = 0,e = v.size()-1;

    while(s<e)
    {
        swap(v[s++],v[e--]);

    }
    return v;
}

vector<int>sum(vector<int>&a , int n, vector<int>&b,int m)
{ 
    int i = n-1;
    int j = m-1;
    int carry = 0;
    vector<int> ans;


    while(i>=0 && j>=0)
    {

        int val1 = a[i];
        int val2 = b[j];


        int sum = val1+val2+carry;

        carry = sum/10;
        sum = sum%10;

        ans.push_back(sum);
        i--;
        j--;

    }



    while (i>=0)
    {
        int sum = a[i] + carry;
        carry = sum/10;
        sum = sum%10;

        ans.push_back(sum);
        i--;

    }

        while (j>=0)
    {
        int sum = b[j] +carry;
        carry = sum/10;
        sum = sum%10;

        ans.push_back(sum);
        j--;

    }

            while (i>=0)
    {
        int sum = a[i] +carry;
        carry = sum/10;
        sum = sum%10;

        ans.push_back(sum);
        i--;

    }

            while (carry!=0)
    {
        int sum = carry;
        carry = sum/10;
        sum = sum%10;

        ans.push_back(sum);
        
    }

    return reverse(ans);

}


int main()
{

    vector<int>arr1 = {1,2,3,4};

    vector<int>arr2 = {6,7,8};

    arr1 = sum(arr1,arr1.size(),arr2,arr2.size());

    for(int i = 0;i<arr1.size();i++)
    {
        cout<<arr1[i];
    }


    return 0;

}