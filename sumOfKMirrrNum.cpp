#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isMirror(string number)
{
    int start = 0, end = number.length()-1;

    while(start <= end)
    {
        if(number[start] != number[end])
        {
            return false;
        }
        start++;
        end--;  
    }
    return true;
}

//base conversion
string baseConversion(int number, int base)
{
    if(number == 0)
    return "0";
    string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string result = "";

    bool isNegative = (number<0);
    
    number = abs(number);

    while(number>0)
    {
        int remainder = number %base;

        result = digits[remainder] + result;
        number /= base;
    }


    if(number<0)
    {
        result = "-" + result;
    }
    

    return result;
}


void generatePalindromes(int length,vector<long long>&pals)
{

}

long long KMirror(int base, int number)
{
    // a base mirror number is a positive integer without leading zeroes that that reads same both forward and backward in base 10 as well as in base base 

    // we are given a base 'base' and an integer 'number' we have to check if numbers upto number read same from back and forward and find their sum

    
    //so first convert given number into the required base and do simple mirror and if it is a mirror number simply add

    string result = "";
    long long sum = 0;
    int count =0;
    int i = 1;
    while(count <= number)
    {
        if(isMirror(baseConversion(i,base)))
        {
            sum+=i;
            count++;
        }
        i++;
    }

    return sum;
    
}

int main()
{
    int base = 2;
    int number = 5; 

    long long ans = KMirror(base ,number);

    cout<<ans<<endl;


    return 0;
    
}
