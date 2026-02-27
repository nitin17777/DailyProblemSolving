#include<bits/stdc++.h>
using namespace std;


vector<int> partitionLabels(string s)
{

    int n = s.size();
    vector<int>ans;

    //Each letter appears in atmost one part

    //Partitons are done so that we can get original string s after their concatenation

    //Return the size of each part 


    //store the last occurence of each char
    vector<int>lastOcc(26);
    for(int i = 0;i<n;i++)
    {
        lastOcc[s[i]-'a'] = i;
    }

    int start = 0;
    int farthest = 0;
    for(int i=0;i<n;i++)
    {
        int maxi = lastOcc[s[i]-'a'];

        farthest = max(farthest,maxi);

        if(farthest == i)
        {
            ans.push_back(i-start+1);
            start = i+1;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int>ans=partitionLabels("ababcbacadefegdehijhklij");
    for(auto& x:ans)cout<<x<<" ";

    cout<<endl;

    return 0;
}