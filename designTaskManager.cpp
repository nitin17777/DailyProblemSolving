#include<iostream>
#include<vector>

using namespace std;



class TaskManager {

    priority_queue<tuple<int ,int ,int>>pq;
    unordered_map<int,int>taskToUser;
    unordered_map<int,int>taskToPriority;


public:
    TaskManager(vector<vector<int>>& tasks) {

        for(auto&t : tasks)
        {
            int userId = t[0],taskId = t[1],priority = t[2];
            add(userId,taskId,priority);
        }
        
    }
    
    void add(int userId, int taskId, int priority) {

        taskToUser[taskId] = userId;

        taskToPriority[priority] = priority;

        pq.push({priority,taskId,taskId});        
    }
    
    void edit(int taskId, int newPriority) {

        taskToPriority[taskId] = newPriority;
        pq.push({newPriority,taskId,taskId});
        
    }
    
    void rmv(int taskId) {

        taskToUser.erase(taskId);
        taskToPriority(taskId);   
    }
    
    int execTop() {

        while(!pq.empty())
        {
            auto[priority,tid,realId] = pq.top();
            pq.pop();


            if(taskToPriority.find(realTid) == taskToPriority.end())
            continue;

            if(taskToPriority[realTid] != priority)continue;


            int userId = taskToUser[realTid];

            taskToUser.erase(realTid);

            taskToPriority.erase(realTid);

            return userId;
        }
        return -1;  
    }
};

int main()
{


    return 0;
    
}
