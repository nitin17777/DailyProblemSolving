#include<iostream>
using namespace std;

class Human
{

    public:
    int height;
    int weight;
    int age;

    public:
    int getAge()
    {
        return this->age;
    }

    void setWeight(int w)
    {
        this->weight = w;
    }
};


class Male:public Human
{

    public:
    string color;

    void sleep()
    {
        cout<<"Male Sleeping"<<endl;
    }
};

int main()
{

    Male m1;
    cout<<m1.height<<endl;  // 
    /*
    Male object1;
    cout<<object1.age<<endl;
    */
    

}