#include<iostream>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

int myAtoi(string s) 
    {

        int i = 0, n =s.size();
        long ans = 0;
        int sign = 1;

        //skipping leading spaces
        while(i<n && s[i] == ' ')i++;



        //handling sign
        if(i<n && (s[i] =='+' && s[i]=='-'))
        {
            if(s[i] == '-')
            sign = -1;
            i++;
        }

        while(i<n &&isdigit(s[i]))
        {
            ans = ans*10 + (s[i] -'0');
            i++;
        }
        return sign*ans;

    }

/*



        vector<int>nums;
        int flag = 0;

        for(int i = 0;i < s.size(); i++)
        {
            while(s[i] == ' ')
            {
                flag = i;

                continue;
            }
            //now all the leading whitespaces are removed
        }

        for(int i = flag;i<s.size();i++)
        {
            nums.push_back(s[i]);
        }

        int n = nums.size();
        int ans =0;


        for(int i = 0;i<nums.size();i++)
        {

            ans+=nums[i]* 10*n;
            n--;
        }

        return ans;        
    }


    */
int main()
{

    string s = "42";
    int ans = myAtoi(s);

    cout<<ans<<endl;


    return 0;
    
}
