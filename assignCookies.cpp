#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int findContentChildren(vector<int>& greed, vector<int>& sizee) 
{
    // we can assign cookie only if size[j] >= greed[i]

    //we have to maximise and output the maximum number

    sort(greed.begin(), greed.end());
    sort(sizee.begin(), sizee.end());

    int count=0, i= 0, j = 0;

    while(i < greed.size() && j < sizee.size())
    {
        if(greed[j] <= sizee[i])
        {
            count++;
            j++;
        }
        i++;
    }
    return count;


}

int main()
{

    vector<int>greed = {10,9,8,7};
    vector<int>sizee = {5,6,7,8};

    int ans = findContentChildren(greed,sizee);

    cout<<ans<<endl;

    return 0;


}

