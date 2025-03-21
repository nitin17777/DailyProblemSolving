#include<bits/stdc++.h>
using namespace std;

string convert(string s, int numRows)


{
    if(numRows == 1 || s.length() <= numRows)
    return s;


    vector<string>rows(min(numRows,int(s.length())));

    int row = 0; 
    bool goingDown = false; // to track direction


    for(char c:s)
    {

    }


}
  /* we have to start writing letters of given string in given number of lines and then will read it row wise
    //or just simply form a 2D array of given rows and start printing letters as row[i]col[j]
{

    vector<char>arr(s.begin(),s.end()); // converting given string to array first

    // now we have to write letters of that array columnwise

    int n; //row
    int m; //col


    //since we need a jagged array for this

    // creating a jagged array 

    char** arr2D = new char*[n];

    for(int i = 0; i<n; i++)
    {
        arr2D[i] = new char[m];

    }




    
}
*/

int main()
{
    return 0;

}