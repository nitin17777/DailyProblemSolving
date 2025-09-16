#include<iostream>
#include<vector>

using namespace std;

vector<string> divideString(string s, int k, char fill)
{

    //we need to divide the given string into k groups and if in last group any place is left, add "fill" there

    //addding required "fill" in the given string
    vector<string>ans;
   if(s.size()%k != 0)
   {
    s+=string(k-s.size()%k,fill);
   }

   for(int i = 0 ; i <s.size(); i+=k)
   {
    ans.push_back(s.substr(i,k));
   }
   return ans;


}


int main()
{
    string s = "abcdefghij";
    int k = 3; 
    char fill = 'x';

    vector<string>ans = divideString(s,k,fill);

    for(auto cha : ans)
    {
        cout<<cha<<" ";

    }

    cout<<endl;

    return 0;
    
}
