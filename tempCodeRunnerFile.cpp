#include<bits/stdc++.h>
using namespace std;

long long minTime(vector<int>& skills, vector<int>& mana)
{
    int n = skills.size();
    int m = mana.size();
    
    // start[j] = start time for potion j at wizard 0
    vector<long long> start(m, 0);
    
    // done[i] = time when wizard i finishes their current potion
    vector<long long> done(n, 0);
    
    start[0] = 0;
    
    for(int j = 0; j < m; j++)
    {
        if(j > 0)
        {
            // Find minimum start time for potion j
            // such that no wizard conflicts
            start[j] = 0;
            
            for(int i = 0; i < n; i++)
            {
                // Time when potion j would arrive at wizard i
                long long arrival = start[j];
                for(int k = 0; k < i; k++)
                {
                    arrival += 1LL * skills[k] * mana[j];
                }
                
                // Wizard i must be free (done with potion j-1)
                long long must_start_after = done[i];
                
                if(arrival < must_start_after)
                {
                    // Delay start of potion j
                    start[j] += (must_start_after - arrival);
                    arrival = must_start_after;
                }
            }
        }
        
        // Process potion j through all wizards
        long long current_time = start[j];
        for(int i = 0; i < n; i++)
        {
            current_time += 1LL * skills[i] * mana[j];
            done[i] = current_time;
        }
    }
    
    return done[n-1];
}

int main()
{
    vector<int>skills = {1,5,2,4};

    vector<int>mana= {5,1,4,2};

    cout<<minTime(skills,mana)<<endl;
    return 0;    
}
