#include<bits/stdc++.h>
using namespace std;


class Spreadsheet {

private:
    int rows;
    vector<vector<int>>grid; //2d grid to store cell values

    

    // helper: parse a cell string like "A12" -> (row, col)
    pair<int,int>parsCell(const string&cell)
    {
        char colChar = cell[0];
        int col = colChar -'A';
        int row = stoi(cell.substr(1))-1;
        return{row,col};
    }

    bool isNumber(const string&s)
    {
        for(char c: s)
        {
            if(!isdigit(c))
            return false;
        }
        return true;
    }


public:
    Spreadsheet(int r)
    {
        rows = r;
        grid.assign(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {

        auto[row,col] = parseCell(cell);//convert cell refernce into row and column indices
        if(row>=0 && row < rows && col >=0 && col < 26)
        {
            grid[row][col] = value;
        } 
    }
    
    void resetCell(string cell) {

        auto[row,col] = parseCell(cell);
        if(row>=0 && row< rows && col >= 0 && col < 26)
        {
            grid[row][col] = 0;
        }
    }
    
    int getValue(string formula) {

        formula = formula.substr(1);

        stringstream ss(formula);
        string token;
        int sum = 0;


        while(getline(ss,token,'+'))
        {
            if(isNumber(token))
            {
                sum+=stoi(token);
            }
            else
            {
                auto[row,col] = parseCell(token);
                if(row >=0 && row < rows && col >= 0 && col < 26)
                {
                    sum += grid[row][col];

                }
            }
        }
        return sum;
        
    }
};


int main() {
    Spreadsheet* obj = new Spreadsheet(10);
    obj->setCell("A1", 5);
    obj->setCell("B2", 10);

    cout << obj->getValue("=A1+B2") << endl; // 15
    cout << obj->getValue("=A1+20") << endl; // 25
    obj->resetCell("A1");
    cout << obj->getValue("=A1+B2") << endl; // 10
}