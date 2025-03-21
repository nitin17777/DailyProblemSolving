#include<iostream>
using namespace std;


int findu(int arr[], int size)
{
    int ans = 0;
    for(int i = 0; i<size ; i++) 
    {
        ans = ans^arr[i];

    }

    return ans;

     
}


int main(){

int crr[] = {4,5,2,1,2,1 };

int jj= findu(crr,6);
cout<< jj <<endl;

return 0;
}