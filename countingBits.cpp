#include<iostream>
#include<vector>
using namespace std;


//function to count 1 in any binary digit
int countone(string num)
{
    int count=0;
    for(int i =0;i<num.size();i++)
    {
        if(num[i] == '1')
        count++;
    }
    return count;
}

//for binary conversion
string toBinary(int n)
{
    string binary = "";
    for(int i = 31; i>=0; i--)
    {
        binary+=(n & (1<<i)) ? '1' : '0';
    }
    return binary;
}

vector<int>countBits(int n)
{
    vector<int>ans;
    //for each i , ans[i] is the number of 1's in binary representation of i

    //for each i we have to find how many '1' are there in it's bit form
    for(int i=0; i<=n; i++)
    {
        string str = toBinary(i); // converted to binary form first

        int counted = countone(str); //counted 1 in binary form

        ans.push_back(counted);
    }
    return ans;
}

int main()
{
    int n = 2;

    vector<int>ans = countBits(n);

    for(auto&an : ans)
    {
        cout<<an<<" ";
    }
    cout<<endl;

    return 0;
}