#include<iostream>
using namespace std;

 double myPow(double x, int n) {

        //base case 

        if(n )

        if(n==1)
        {
            return x;
        }

        return x* myPow(x,n-1);
        
    }

int main()
{

    double num = 2.1;

    int power = 3;

    double ans = myPow(num,power);


    cout<<"Power is: "<<ans<<endl;




    return 0;

}