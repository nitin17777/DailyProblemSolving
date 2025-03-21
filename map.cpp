#include<iostream>
#include<map>

using namespace std;

int main()
{

    map<int,string>m;

    m[1]= "Babbar";
    m[2]= "Love";
    m[3] ="kumar";


    m.insert({5,"Bheem"});



    for(auto i:m)
    {
        cout<<i.first<<" "<<i.second<<endl;

    }

    cout<<"Finding 5 : " <<m.count(5)<<endl;

    auto it = m.find(5);

    }