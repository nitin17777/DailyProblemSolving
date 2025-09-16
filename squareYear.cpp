#include<iostream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;


vector<int>dd(string s)
{

    vector<int>ans;
    
    int a  = stoi(s.substr(0,2));
    int b = stoi(s.substr(2,2));

    int sum = a+b;

    int original = stoi(s);

    int root = sqrt(original);
    if(root * root == original)
    {
        ans.push_back(0); //considering 2nd digit to be always 0
        
        ans.push_back(root);
    }

   // if(sum *sum == original)
 //   {
 //       ans.push_back(a);
        //ans.push_back(b);
//    }

    else
    {
        ans.push_back(-1);

    }
    return ans;

}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;

        vector<int>ans = dd(s);

        for(auto& an :ans)
        {
            cout<<an<<" ";
        }
        cout<<endl;


    }
    return 0;
}
