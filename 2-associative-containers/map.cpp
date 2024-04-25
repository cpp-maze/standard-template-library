#include <iostream>
#include <map>

using namespace std;

void printContainer(string title, const auto &values)
{
    cout << title << endl;

    for (auto it : values)
    {
        cout << it.first << " --> " << it.second << endl;
    }

    cout << endl;
}

/*** Declarations ***/
int main()
{
    map<string, int> charCode1;

    map<string, int> charCode2{{"c", 99}, {"a", 97}, {"b", 98}};
    map<string, int, greater<>> charCode3{{"c", 99}, {"a", 97}, {"b", 98}};

    printContainer("Asc Map values", charCode2);
    printContainer("Desc Map values", charCode3);

    return 0;
}

/*** Element access ***/
int ElementAccess()
{
    /**
     * []
     * .at()
     * .find()
     * .begin() -> .end()
     * .rbegin() -> .rend()
     */
    map<string, int> charCode{{"c", 99}, {"a", 97}, {"b", 98}};

    cout << "charCode['a'] : " << charCode["a"] << endl;
    cout << "charCode.at('a') : " << charCode.at("a") << endl;

    map<string, int>::iterator foundIt = charCode.find("b");
    if (foundIt == charCode.end())
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "Fount: " << foundIt->first << " --> " << foundIt->second << endl;
    }

    // (C++20)
    // cout << "Contains 'a': " << charCode.contains("a") << endl;

    cout << "begin() -> end(): " << endl;
    for (map<string, int>::iterator itr = charCode.begin(); itr != charCode.end(); ++itr)
    {
        cout << itr->first << " --> " << itr->second << endl;
    }
    cout << endl;

    cout << "rbegin() -> rend(): " << endl;
    for (map<string, int>::reverse_iterator itr = charCode.rbegin(); itr != charCode.rend(); ++itr)
    {
        cout << itr->first << " --> " << itr->second << endl;
    }
    cout << endl;

    // for (pair<string, int> p : charCode)
    // {
    //     cout << p.first << " --> " << p.second << endl;
    // }

    return 0;
}

/*** Modifiers ***/
int Modifiers()
{
    /**
     * .insert(), .emplace()
     * []
     * .erase()
     * .clear()
     */

    map<string, int> charCode{
        {"c", 99},
        {"a", 97},
        {"d", 100},
        {"b", 98}};

    charCode.emplace("e", 101);
    charCode.emplace("e", 201);
    // charCode.insert(make_pair("e", 101));
    // charCode.insert(make_pair("e", 201));
    // charCode["e"] = 101;
    // charCode["e"] = 201;

    printContainer("After insert", charCode);
    cout << "Size : " << charCode.size() << endl;
    cout << "Empty : " << charCode.empty() << endl;

    cout << "Erase a : " << charCode.erase("a") << endl;
    printContainer("After erase('a')", charCode);

    cout << "Before clear, Size : " << charCode.size() << endl;
    charCode.clear();
    cout << "After clear, Size : " << charCode.size() << endl;

    return 0;
}

/*** User Defined Data Types ***/

class SuperHero
{
public:
    int power;
    string name;
    SuperHero(string nm, int pwr) : name(nm), power(pwr)
    {
        cout << "Constructor" << endl;
    }
    SuperHero(const SuperHero &hero)
    {
        cout << "Copy Constructor" << endl;
        name = hero.name;
        power = hero.power;
    }
};

bool operator<(const SuperHero &hero1, const SuperHero &hero2)
{
    return hero1.power < hero2.power;
}

int UserDefinedDataTypes()
{
    map<int, SuperHero> heros;

    // heros.insert(make_pair(1234, SuperHero("Superman", 150)));

    // heros.emplace(1234, SuperHero("Superman", 150));

    heros.emplace(
        std::piecewise_construct,
        std::forward_as_tuple(1234),
        std::forward_as_tuple("Superman", 150));

    for (auto &heroPair : heros)
    {
        cout << "{" << heroPair.second.name << ", " << heroPair.second.power << "} --> ";
        cout << heroPair.first << endl;
    }

    cout << endl;

    return 0;
}