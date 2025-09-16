#include<iostream>
using namespace std;

    int minMaxDifference(int num) 
  {
    string s = to_string(num);

    //MAximising first
    string maxS = s; //assigning maxS as s

    for(char d :s)
    {
        if(d != '9')
        {
            char target = d;
            for(char & c:maxS)
            {
                if(c == target)
                c='9';
            }
            break;
        }
    }

    //Minimise
    string minS = s;
   if(s[0] != '1')
   {
   char target = s[0];

   for(char &c : minS)
   {
    if(c== target)
    c = '1';//////////
   }
}


    else
    {
        for(int i =1; i<s.size(); i++)
        {
            if(s[i] != '1' && s[i] != '0')
            {
                char target = s[i];

                for(char& c : minS)
                {
                    if(c == target)
                    c = '0';
                }
                break;
            }
        }
    }
   
    return stoi(maxS) - stoi(minS);


  }


int main()
{

    int num = 11891; // max can be obtained by replacing 9 with 1(99899)and for min value 0 can be place in place of 1(89) :Diff = 99009

    int ans = minMaxDifference(num);

    cout<<ans<<endl;
    
    return 0;

}