#include<iostream>
using namespace std;

class Animal
{
    public:
    int age = 5;
    int weight;

    public :
    void speak()
    {
        cout<<"Speaking"<<endl;

    }

};

class Dog:public Animal
{

};

class GermanShephered: 
public Dog
{

};



int main()
{

    GermanShephered g;
    g.speak();

    return 0;

}