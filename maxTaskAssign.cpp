#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//every task has requirement of tasks[i] strength and can only be done by worker with that strength, additionally we can give pill sot improve their strength

int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength)
{


    //we need to sort both tasks and workers first so that weakest worker can be assigned the weakest work

    sort(tasks.begin(), tasks.end()); // 1,2,3
    sort(workers.begin(), workers.end()); //0,3,3

    int tasksIndex = 0;
    int workerIndex =0;

    int completedTask = 0;


    //First trying to complete tasks without any pill
    while(tasksIndex < tasks.size() && workerIndex < workers.size())
    {
        if(workers[workerIndex] >= tasks[tasksIndex])
        {
            completedTask++;
            tasksIndex ++;
        }
        workerIndex++;
    }

    //Now using pills to boost workers strength and complete remaining tasks

    workerIndex = 0;

    while(tasksIndex < tasks.size() && workerIndex < workers.size() && pills >0)
    {
        if(workers[workerIndex] + strength >= tasks[tasksIndex])
        {
            completedTask++;
            pills--;

            tasksIndex++;

        }
        workerIndex++;
    }
    return completedTask;
}

int main()
{
    vector<int>tasks = {33,58,22,87,38};
    vector<int>workers = {84,46,17,58,98,30,56,78,48};
    int pills = 0;
    int strength = 74;

    int ans = maxTaskAssign(tasks,workers,pills,strength);

    cout<<ans<<endl;


    return 0;

}