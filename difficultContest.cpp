#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



bool isDifficult(string&s)
{
        
    //case when no FFT and NNT found in string
    return(s.find("FFT") != string::npos || s.find("NTT") != string::npos);
}



string notDifficultContest(string s)
{

     sort(s.begin(), s.end());
    do {
        if (!isDifficult(s))
            return s;
    } while (next_permutation(s.begin(), s.end()));
    
    return "-1"; // if no valid permutation foun



}

int main()
{

    int t;
    cin>>t;

    while(t--)
    {
        string s;

        cin>>s;

        string ans = notDifficultContest(s);

        cout<<ans<<endl;
    }

    return 0;
    
}
