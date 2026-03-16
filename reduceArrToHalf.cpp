#include<bits/stdc++.h>
using namespace std;

int minSetSize(vector<int>& arr)
{
    int n = a.size();

    //We can choose a set of integers and remove all the occurences

    //Return the min size of the set so that at least half of the integers of the array aar eremoved

   vector<int>freq;
    for(auto & x:arr)freq[x]++;

    sort(freq.begin(),freq.end(),auto& )


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>a = {3,3,3,3,5,5,5,2,2,7};
    cout<<minSetSize(a)<<endl;

    return 0;
}