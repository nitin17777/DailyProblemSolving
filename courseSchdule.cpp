#include<iostream>
#include<vector>
using namespace std;
#define ll long long


bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{


    //pre: you have to take course bi first if you want to take course ai
    

    //creating adjacency list first

    vector<vector<int>>adj(numCourses);

    vector<int>indegree(numCourses,0);
    //Indegree = number of prerequisites that must be completed before this course

    for(auto&pre:prerequisites)
    {
        int courses = pre[0];
        int prereq = pre[1];

        adj[prereq].push_back(course);
        indegree[course]++;

    }

    queue<int>q;

    for(int i = 0; i < numCourses;i++)
    {
        while(!q.empty())
        {
            int course = q.front();
            q.pop();
            takenCourses++;
        }
    }
    
            // Reduce indegree of neighbors
            for (int neighbor : adj[course]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // Step 4: If we could take all courses → no cycle
        return takenCourses == numCourses;

}

int main()
{

    int numCourses = 2;

    vector<vector<int>> pre = {
        {1,0}
    };

    cout<<(canFinish(numCourses,pre)?"True" : "False") << endl;
    return 0;

}