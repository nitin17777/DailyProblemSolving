#include<iostream>
#include<vector>

using namespace std;

vector<int>shrink(int n)
{
    //choose an index i such that ai > ai-1&& ai >ai+1
    //then ai form array

    //we have to make a permuatation such that we can perform our shrink operation the maximum times

    


}

int main()
{

    int n = 3; 
    vector<int>ans = shrink(n);

    for(auto& an : ans)
    {
        cout<<an<<endl;

    }
    return 0;
    
}
