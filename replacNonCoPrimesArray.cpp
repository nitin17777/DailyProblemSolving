#include<iostream>
#include<vector>
#include<stack>
using namespace std;


int gcd(int a,int b)
{
    while(b!=0)
    {
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;   
}

int lcm(int a, int b)
{
    //LCM(a,b)= a *b / GCD(a,b)
    return (a/gcd(a,b)) *b;
}


vector<int> replaceNonCoprimes(vector<int>& nums)
{
    vector<int>st;
    for(auto num: nums)
    {
        int current = num;

        while(!st.empty() && gcd(st.back(),current) != 1)
        {
            current = lcm(st.back(), current);
            st.pop_back(); 
        }
        st.push_back(current);
    }
    return st;
}

/*

//      Kind of Brute force => TLE
vector<int> replaceNonCoprimes(vector<int>& nums)
{
    //find any two adj numbers that are non co primes otherwise stop the process

    //otherwise delete both nums and replace them wirth theri lcm

    //repeat until we don't stop getting non co primes

    //return the final array

  bool changed = true;

  while(changed)
  {
    changed = false;

    for(int i = 0 ; i < nums.size()-1;i++)
    {
        if(!areCoPrime(nums[i], nums[i+1]))
        {
            int l = lcm(nums[i],nums[i+1]);
            nums[i] = l;


            nums.erase(nums.begin()+i+1);
            changed =true;
            break;
        }
    }
  }

return nums;
}
*/

int main()
{
    vector<int>nums = {6,4,3,2,7,6,2};

    vector<int>ans = replaceNonCoprimes(nums);
    
    for(auto&an :ans)
    {
        cout<<an<<" ";
    }
    cout<<endl;

    return 0;
    
}
