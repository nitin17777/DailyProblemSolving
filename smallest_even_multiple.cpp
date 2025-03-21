#include<iostream>
using namespace std;


int sm(int n) {
        //Need the smallest number which is multiple of both 2 and 'n'

          while(n>0)
        {
            if(n%2 == 0)
            {
                return n;
            }
            else
            {
                return n*2;
            }

        }
    }


int main()
{

    int n = 6;

    cout<<sm(n)<<endl;
    


    return 0;

}