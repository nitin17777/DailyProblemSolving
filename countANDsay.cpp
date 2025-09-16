#include<iostream> ////////
using namespace std;


string countS(int n)
{
    //base case
    
        if(n == 1)
        {
        return "1";
        }


       //getting previous term using recursion
        string prev = countS(n-1);


        string result = ""; //intiallises an empty string result
        int count = 1;


        for(int i = 0; i<prev.length(); i++)

        {
            if(i +1 < prev.length() && prev[i] == prev[i+1])
            {
                count++;
            }

            else
            {
                result += to_string(count) + prev[i];
                count=1;
            }
        }

        return result;
    }



int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    cout << "Count and Say Sequence for n = " << n << ": " << countS(n) << endl;
    return 0;
}