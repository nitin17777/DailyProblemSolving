#include<iostream>
#include<vector>
using namespace std;

int numberOfArrays(vector<int>differences, int upper,int lower)
{
    // therefore,the hidden sequence is of length = 4 and whose elements are in between 1 and 6


    //differenes[i] = hidden[i+1] - hidden[i];

    //differences[0] = hidden[1] - hidden[0];
         //     1 = x- y   -> now find all possible value of x and y

         //assuming x = 1 ->so y can be 0
}

int main()
{
    vector<int>differences = {1,-3,4};
    int lower = 1, upper = 6;

    int ans = numberOfArrays(differences,lower,upper);

    cout<<ans<<endl;

    return 0;
}