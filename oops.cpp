#include<iostream>
using namespace std;

class Hero
{

    private:
    int health;

    public :
    char*name;
    char level;

    Hero()
    {
    cout<<" Simple Construtor Called!!"<<endl;
    name = new char[100];

    }

    //Parameterised Constructor
    Hero(int health)
    {
       this->health=health;

    }
    Hero(int health,char level)
    {
       

        this->health=health;

        this->level =level;
    }

    Hero(Hero& temp)
    {
        this->health = temp.health;
        this->level = temp.level;

    }



    void print()
    {
    cout<<"level"<<this->level<<endl;
    cout<<"health"<<this->health<<endl;


    }

    int getHealth()
    {
        return health;

    }

    char getLevel()
    {
        return level;

    }

    void setHealth (int h)
    {
        health= h;
    }

    void setLevel(char ch)
    {
        level =ch;

    }
    void setName(char name[])
    {
        strcpy(this->name,name);

    }
};

int main()
{

    Hero hero1;
    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[7] = "Babbar";
    hero1.setName(name);
    

    Hero s(70,'C');
    s.print();

//copy cosn
    Hero r(s);
    r.print();


    /*


//static allocation
   Hero a;
   cout<<"Level is  "<<a.level<<endl;
   cout<<"Health is "<<a.getHealth<<endl;


   //dynamically
   Hero *b = new Hero;
   *b->setLevel('A');
   b->setHealth(70);

   cout<<"Level is  "<<(*b).level<<endl;
   cout<<"Health is "<<(*b).getHealth()<<endl;

   cout<<"Level is  "<<b->level<<endl;
   cout<<"Health is "<<b->getHealth<<endl;

   */

    return 0;

}


