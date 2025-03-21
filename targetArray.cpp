#include<iostream>
#include<vector>

using namespace std;

vector<int>target(vector<int>& nums, vector<int>& index){
    
//starting from an empty array, just start inserting elements of nums[i] at index defined by index[i] continue this until all the elements of nums and index are finished
vector<int>result; 
  // creating an empty array to store the elements

for(size_t i = 0; i<nums.size(); i++)
{
result.insert(result.begin()+ index[i],nums[i]);
}

return result;

}

int main()
{

    vector<int>inde = {0,1,2,3,0};
    vector<int>num = {1,2,3,4,0};


    vector<int>targt = target(num,inde);

    cout<<"Target: "<<endl;

    for(int val:targt )
    {                                                                          
        cout<<val<<" ";
}

cout<<endl;


    return 0;

}