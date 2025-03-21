#include<iostream>
using namespace std;

        string clearDigits(string s) {
            int n = s.length();
            string result = "";
            for (int i = 0; i < n; ++i)
            {
                if(isdigit(s[i]))
                {
                    if(!result.empty())
                    {
                        result.pop_back();

                    }
                    else
                    {
                        result += s[i];
                    }
                }
                return result;

    }
}
int main()
{

    string new = "ab2jj3";

    
    return 0;

}