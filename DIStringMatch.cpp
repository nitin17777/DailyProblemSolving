#include<iostream>
#include<vector>
#include<string>
using namespace std;

    vector<int> diStringMatch(string s)
    {
        //s[i] == 'I' if result[i] < result[i + 1], and
        //s[i] == 'D' if result[i] > result[i + 1]

        vector<int>result;
        int n = s.size();
        int low = 0, high = n;


        for(int i = 0; i<s.size(); i++)
        {
            if(s[i] == 'I')
            {
                result.push_back(low++);
            }

            else
            {
                result.push_back(high--);

            }
        }
        result.push_back(low);///***** */


        return result;

    }


int main()
{

    string s = "IDID";

    vector<int>ans =diStringMatch(s);

    for(auto &an :ans)
    {

         cout<< an <<" ";

    }

    cout<<endl;
   

    return 0;
    
}
