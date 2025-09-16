#include<iostream>
#include<string>

using namespace std;

int maxRepeating(string sequence, string word)
{
    int count = 0;
    string repeated = word;

    while(sequence.find(repeated) != string :: npos)
    {
        count++;
        repeated += word;
    }
return count;
}


int main()
{
    string seq = "ababc";

    string word = "ab";

    int ans = maxRepeating(seq,word);

    cout<<ans<<endl;

    return 0;
    
}
