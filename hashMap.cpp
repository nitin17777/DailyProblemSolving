#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;



int main()
{
    //creation
    unordered_map<string,int>m;

    //insertion

    //1
    pair<string,int> p = make_pair("Babbar", 3);
    m.insert(p);

    //2
    pair<string,int>pair2("Love", 2);
    m.insert(pair2);

    //3
    m["Mera"] = 1;
    m["mera"] = 2;


    //search
    cout<< m["mera"] << endl;
    cout<<m.at("Babbar") <<endl;

    //iterator
    unordered_map<string,int> :: iterator it = m.begin();

    while(it != m.end());

    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;

    }





    return 0;

}