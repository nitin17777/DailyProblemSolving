#include<iostream>
#include<queue>
using namespace std;

class Queue
{
    int * arr ;
    int front;
    int rear;
    int size;


    public:
    Queue()
    {
        size = 10001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

     bool isEmpty()
     {
        if(rear == front)
        {
            return true;

        }
        else
        {
            return false;

        }
     }

    void enqueue(int data)
    {
        if(rear == size)
        {
            cout<<"Queue is Full" <<endl;

        }

        else
        {
            arr[rear] = data;
            rear ++;

        }
    }

    int dequeue()
    {
        if(front == rear)
        {
            return -1;

        }

        else
        {
            int ans = arr[front];
            arr[front] = -1;

            front++;

            if(front == rear)
            {
                front = 0;
                rear = 0;

            }
            return ans;
        }
    }

    int getfront()
    {
        if(front == rear)

        {
            return -1;
        }

            else
            {
                return arr[front];
            }
    }
};
