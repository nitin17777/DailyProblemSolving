#include<bits/stdc++.h>
using namespace std;

string decodeCiphertext(string et, int rows)
{
    //Return the original string 

    //Fill the given string in the marix and then read the matrix diagoanlly

    if(rows == 0)return "";
    int n = et.size();

    int cols = n/rows;

    vector<vector<char>>mat(rows,vector<char>(cols));

    int idx = 0;

    for(int i =0;i<rows;i++)
    {
        for(int j = 0;j<cols;j++)
        {
            mat[i][j] = et[idx++];
        }
    }

    //Now reading the matrix diagonally

    string res = "";

    for(int start = 0;start<cols;start++)
    {
        int i = 0,j = start;
        while(i<rows && j <cols)
        {
            res += mat[i][j];
            i++;
            j++;
        }
    }

    //to remove trailing space
    while(!res.empty() && res.back() == ' ')res.pop_back();

    return res;
}


int main()
{
    cout<<decodeCiphertext("ch   ie   pr",3)<<endl;
}