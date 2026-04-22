#include<bits/stdc++.h>
#define ll long long
using namespace std;


vector<string> twoEditWords(vector<string>& q, vector<string>& d)
{

    /*

    1 Edit : Take a word from q, change any letter in to any letter

    Return list of words from q that match with some word from dictionary

    
    */

    vector<string>ans;

    for(auto & qr:q)
    {
        for(auto & di : d)
        {

            //Move on to the next word of dictionary
            if(di.size()!= qr.size())continue;
            int cnt = 0;

            for(int i = 0;i<qr.size();i++)
            {
                if(qr[i]  != di[i])cnt++;
            }

            if(cnt<=2)
            {
                ans.push_back(qr);
                break;
            }
        }
    }
    return ans;
}

      
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string>q = {"word","note","ants","wood"}, d = {"wood","joke","moat"};

    vector<string>ans = twoEditWords(q,d);
    for(auto & x:ans)cout<<x<<" ";

    cout<<endl;


    return 0;
}




