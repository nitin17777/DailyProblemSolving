#include<iostream>
#include<vector>
#include<unordered_set>
#include<sstream>
using namespace std;

int canBeTypedWords(string text, string brokenLetters)
{

    //we have to return the number of words which we can write fully instead of those malfunctioning keys

    //iterate through text given and if no brokenLette ris there just increase the count


    unordered_set<char>broken(brokenLetters.begin(),brokenLetters.end());

    stringstream ss(text);//for splitting words after space


    string word;


    int count = 0;//to store the final number of words that can be typed

    while(ss>>word) // to extract the word from ss until there is no word left
    {
        bool valid = true;


        for(char c: word)
        {
            if(broken.count(c))
            {
                valid = false;
                break;
            }
        }
        if(valid)count++;
    }
    return count;

}

int main()
{

    string text = "hello world", brokenLetters = "ad";

    cout<<canBeTypedWords(text, brokenLetters)<<endl;

    return 0;
    
}
