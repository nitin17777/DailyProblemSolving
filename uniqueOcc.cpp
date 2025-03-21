#include<iostream>
using namespace std;


//return true if number of occurence of each value is unique

// check the number of occurence of each value and then compare them and if any occurence is  same print false otherwise true.
bool checkO(int arr[],int size )
{
    int freq[size] = {0};
    int values[size] = {0};
    int uniquec[size] = {0};

for (int i = 0; i<size; i++)
{
    bool found = false;

    for(int j = 0; j<uniquec; j++)

    {
        if( values[j] == arr[i])
        {
            freq[j++];
            found = true;
            break;
            
        }

    }
}

}

int main()
{
int arr1 ={3,2,3,2,4,5,9,5,100};


}