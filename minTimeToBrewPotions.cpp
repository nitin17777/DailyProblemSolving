#include<bits/stdc++.h>
using namespace std;

        long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size();
        int m = mana.size();

        //answer [i] will represent the min total time for the first i+1 wizards to breq all potions processed so far
        vector<long long> answer(n, 0);

        //iterating through each potion
        for (int row = 0; row < m; row++) {

            //Step 1 : First wizard's time
            //first wizard proceses each potion in order
            //time will keep on increasing with each potion
            long long t = 1LL*skill[0] * mana[row];
            answer[0] += t;//add the answer for current potion


            //process for other wizards

            //each wizard col must wait until :
            //same wizard has finished previous potion

            for (int col = 1; col < n; ++col) {
                t = skill[col] * mana[row];
                answer[col] = max(answer[col], answer[col - 1]) + t;
            }

            for (int col = n - 1; col > 0; --col) {
                t = skill[col] * mana[row];
                answer[col - 1] = max(answer[col - 1], answer[col] - t);
            }
        }

        return answer.back();
    }


int main()
{
    vector<int>skills = {1,5,2,4};

    vector<int>mana= {5,1,4,2};

    cout<<minTime(skills,mana)<<endl;
    return 0;    
}

