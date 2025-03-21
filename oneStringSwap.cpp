#include<iostream>
#include<vector>
using namespace std;
 

bool areAlmostEqual(string s1, string s2)
{

vector<int>diff;

if(s1 == s2)
{
    return true;
}

if(s1.size() != s2.size())
{
    return false;

}

for(int i = 0 ;i<s1.size();i++)
{
    if(s1[i] != s2[i]) //this is because if two strings need one swap to become equal then they must differ in exactly two positions
    {
        diff.push_back(i);
    }
}
    if(diff.size()!=2)
    {
        return false;
    }

    swap(s1[diff[0]],s1[diff[1]]);

    return s1 == s2;


}

int main()
{
    string qu = "nitin";
    string qe = "ntiin";

    bool ans = areAlmostEqual(qu,qe);

    if(ans)
    {
        cout<<"True"<<endl;

    }
    else
    {
        cout<<"False"<<endl;

    }
    return 0;


}