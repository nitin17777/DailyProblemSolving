#include<bits/stdc++.h>
using namespace std;

double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
{
    //class i = pass i , total i
    //Assign extra Students such that average pass ratio is max

    //Avg pass ratio = sum of all ratios / total number of classes

    //iterarte over every class and find the one with least differnce in pass and number of students and add those extra students there

    auto gain = [](int pass, int total)
    {
        return(double)(pass+1)/(total+1) - (double)pass / total;
    };


    //max heap to store gain, pass and total
    priority_queue<pair<double,pair<int,int>>>pq;

    for(auto & c : classes)
    {
        //pushing all classes into priority queue with theie gain value
        int pass = c[0], total = c[1];

        pq.push({gain(pass,total), {pass,total}});
    }

    while(extraStudents--)
    {
        auto top = pq.top();
        pq.pop();
        int pass = top.second.first;
        int total = top.second.second;
        //Add students in both pass and total
        pass++;
        total++;

        //now push back the update priority queue
        pq.push({gain(pass,total), {pass,total}});

    }

    //Calculating final average
    double sum = 0.0;
    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int pass = top.second.first;
        int total = top.second.second;

        sum += (double)pass/total;
    }
    return sum / classes.size();
}

int main()
{
    vector<vector<int>>classes = {
        {1,2},{3,5},{2,2}
    };

    double ans = maxAverageRatio(classes,2);

    cout<<ans<<endl;

    return 0;
    
}
