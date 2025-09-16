#include<isotream>
using namespace std;

int countBalanced(string num)
{

    //a number is balanced if sum of digits at even positions = sum of digits at odd positions

    int n = num.length();
    
    int evenSum = 0,oddSum = 0;
    
    

}



int main()
{
    string num = "123"; 

    int ans = countBalanced(num);

    cout << ans << endl; // Output: 2

    return 0;

}