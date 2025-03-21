#include<bits/stdc++.h>
using namespace std;

string firstNonRep(string A)
{

    unordered_map<char,int>m; // stores frequency of characters

    queue<char>q;// stores characters in order of occurence

    string ans ="";


    for(int i=0; i<A.length(); i++) {
		        char ch = A[i];
		        
		        q.push(ch);
		        m[ch]++;
		        
		        while(!q.empty()) {
		            if(m[q.front()] > 1){
		                q.pop();
		            }
		            else
		            {
		                ans.push_back(q.front());
		                break;
		            }
		        }
		        if(q.empty()){
		            ans.push_back('#');
        }
    }
    return ans;
}


int main()
{
    string s = "jjkklm";

    string ans = firstNonRep(s);

    cout<<ans<<endl;

    return 0;
}