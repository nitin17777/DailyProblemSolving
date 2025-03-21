//Checking the character with highest number of occurecne in a given string



#include<iostream>
#include<vector>

using namespace std;

void maxOcc(string s)
{

    for(int i =0; i<s.length(); i++)
    {

    
    int arr[26] ={0};

    char ch = s[i];

    int number = 0;

    if(ch>'a' && ch<'z')
    {
        number = ch - 'a';

    }
    else
    {
        number = ch-'A';
    }

    arr[number]++;

    }

    int maxi = -1 , ans = 0;

    for(int i =0; i<26; i++)
    {
        if maxi
    }
}

int main()
{


    return 0;


}