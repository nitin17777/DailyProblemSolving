#include <bits/stdc++.h>
using namespace std;

string longestDiverseString(int a, int b, int c)
{
    /*
    Happy string consists of:
    1-> Only letters a,b,c
    2-> No aaa,bbb,ccc
    3-> atmost a occurences of letter a
    4->atmost b occurences of letter b
    5- >atmost c occurences of letter c

    Return the largest possible happy string else an empty string

    */

    // if every count is less than 3 : simply form any answer

    // if count >= 3 => form pair of two of greater one and then other character and similarly
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << longestDiverseString(1, 1, 7) << endl;

    return 0;
}