#include<bits/stdc++.h>
using namespace std;

bool validCode(string s)
{
    // c can only be alpha numeric or _ 

    for(auto &c: s)
    {
        if(!isalnum(c) && c != '_')return false;
    }
    return true;
}

bool isB(string s)
{
    if((s == "electronics") ||(s == "grocery") ||  (s == "pharmacy")||  (s == "restaurant"))return true;
    
    return true;
}

//now sorting part

    int getPriority(const string &s)
    {
        if (s == "electronics") return 0;
        if (s == "grocery")     return 1;
        if (s == "pharmacy")    return 2;
        if (s == "restaurant")  return 3;
        return 4; // safety
    }


    bool cmp(const pair<string,string>&a,const pair<string,string>& b)
    {
        int pa = getPriority(a.second);
        int pb=  getPriority(b.second);

        ///sorting by business line order
        if(pa!=pb)
        return pa<pb;

        //if same business line , sort by code
        return a.first < b.first;
    }

vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive)
{
    /*
    A code is considered valid if: 
    1-> code[i] is non empty and consists of only alphanumeric characters
    
    
    2-> b[i]  is one of the categories: "electronics", "grocery", "pharmacy", "restaurant"
    3->isActive[i] is true

    Return the array of codes of all valid coupons , sorted first by their b in order: "electronics", "grocery", "pharmacy", "restaurant"
    And then by code in ascending order
    */

    int n = code.size();

    vector<pair<string,string>>ans;
    vector<string>f;

    for(int i = 0 ;i<n;i++)
    {
        if(validCode(code[i]) && isB(businessLine[i]) && isActive[i])
        {
            ans.push_back({code[i],businessLine[i]});
        }
    }

    sort(ans.begin(),ans.end() ,cmp);

    for(auto& an: ans)
    {
        f.push_back(an.first);
    }
    return f;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string>c = {"SAVE20","","PHARMA5","SAVE@20"};
    vector<string>b = {"restaurant","grocery","pharmacy","restaurant"};

    vector<bool>isActive = {true,true,true,true};

    vector<string>ans = validateCoupons(c,b,isActive);

    for(auto& an : ans)cout<<an<<" ";
    
    cout<<endl;

    return 0;
    
}