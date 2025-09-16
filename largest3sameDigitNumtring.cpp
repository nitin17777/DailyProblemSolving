#include<iostream>
#include<vector>
#include<string>
using namespace std;

string largestGoodInteger(string num)
{
    //a number is good if: it is a substring of length 3 consisting of only 1 unique digit


    string ans = "";
    int n = ans.size();
    char maxDigit = 0;



    for(int i =0; i <num.size()-2;i++)
    {
        if(maxDigit <num[i] && (num[i] == num[i+1] && num[i+1] == num[i+2]))
        { 
            ans = string(3,num[i]);
            maxDigit = num[i];
        }
    }
    return ans;
}


int main()
{


    string num = "6777133339";

    string ans = largestGoodInteger(num);

    cout<<ans<<endl;

    return 0;
    
}
