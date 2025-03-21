//compressing the given string

#include<iostream>
#include<vector>

using namespace std;


int compress(vector<char>& chars)
{
    int i = 0, ansIndex = 0;  //initiallising i ansIndex and n firstly
    int n = chars.size();

    while(i<n)
    {

        int j = i+1;
        
        while(j<n && chars[j] == chars[i])
        {
            j++;
            //when characters at i and j are same increase j 

        }

        chars[ansIndex++] = chars[i];
        int count = j-i; //finding the frequency 


        if(count>1)
        {
            string cnt = to_string(count); //converting number to string
            for(char ch:cnt)
            {
                chars[ansIndex++] = ch; //store count as individual

            }
        }
        i = j; //moving i to the next character

    }

    return ansIndex;
    

}

int main()
{
    vector<char> word = {'a','a','a','b','b','c','d'};



int newsize = compress(word);


for(int i = 0;i<newsize;i++)
{
    cout<<word[i];

}

cout<<endl;



}