#include<iostream>
#include<vector>
using namespace std;


 vector<int> plusOne(vector<int>& digits) {///just add '1' to given integer in array and return it in the form of integer.


    int n = digits.size();

    for(int i = n-1; i>0; i--)
    {
        digits[i] += 1;

        if(digits[i]+1 < 10)
        {
            return digits;


        }
        if(digits[i]= 10)
        {
            digits[i] = 0;           
        }
        
        digits.insert(digits.begin(),1);

        return digits;

    }
    }

int main()
{

    vector<int> arr = {1,3,4};

    vector<int> gg = plusOne(arr);

    for(int val:gg)
    {
        cout<< val <<" ";
    }

    return 0;

}