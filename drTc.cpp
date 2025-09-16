#include<iostream>
#include<string>
#include<numeric>
using namespace std;

int sumOfDigits(const string& numStr) {
    int sum = 0;
    for (char ch : numStr) {
        if (isdigit(ch)) {
            sum += ch - '0';  // Convert char digit to int
        }
    }
    return sum;
}

int countOne(string&s, int n)
{
    //first he creates string s having n characters, then he creates n binary strings(a1, a2.....) and these ai are created by first copying s then flipping ith character. And after creating all n strings he arranges them into a grid where ith row is ai

    //and after doing all these, we need to count the number of '1's present all those new strings combinely

    int oneCount = 0;
    for(int i = 0; i < n;i++)
    {

        string temp = s;

        int add = 0;
        if(temp[i] == '1')
        {
            temp[i] = '0';
        }

        else if(temp[i] == '0')
        {
            temp[i] = '1';
        }

       oneCount += sumOfDigits(temp);
    }
    
    return oneCount;

}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        string s ;
        cin>>s;
        

        int ans = countOne(s,n);
        cout<<ans<<endl;
    }
    return 0;


}