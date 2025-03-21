#include<iostream>
#include<vector>

using namespace std;

vector<int> wPrint(vector<vector<int>> arr,int nRows ,int mCols )
{

    vector<int>ans;

    for(int col = 0; col < mCols; col++)
    {
        if(col&1)
        {
                //odd index -> Bottom to top
                for(int row = nRows -1;  row >= 0; row--)
                {
                    cout<<arr[row][col]<<" ";

                    ans.push_back(arr[row][col]);

                }
        }
        else
        {
                //even -> top to bottom

                for(int row = 0; row < nRows; row++)
                {
                    cout<<arr[row][col]<<" ";

                    ans.push_back(arr[row][col]);

                }
        }
        
    }
    return ans;
}

int main()
{
    vector<vector<int>> arr ={

    {1,2,3},
    {4,5,6},
    {7,8,9}
    };


    int nRows = arr.size();
    int mCols = arr[0].size();


    vector<int>result = wPrint(arr,nRows,mCols);

    cout<<"Wave Print Result: ";

    for(int num : result)
    {
        cout<< num << " ";

    }
    cout << endl;

    return 0;

}