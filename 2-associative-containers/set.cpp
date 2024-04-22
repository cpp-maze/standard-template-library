#include <iostream>
#include <vector>
#include <set>

using namespace std;

void printContainer(string title, const auto &values)
{
    cout << title << endl;

    for (auto value : values)
    {
        cout << value << " ";
    }

    cout << endl;
}

/*** Declarations ***/
int main()
{
    set<int> ranks1;
    set<int> ranks2 = {5, 2, 2, 1, 10, 5};
    set<int> ranks3{5, 2, 2, 1, 10, 5};

    vector<int> input{1, 2, 0, 10};
    set<int, std::greater<>> ranks4(input.begin(), input.end());

    printContainer("ranks3", ranks3);
    printContainer("ranks4", ranks4);

    return 0;
}

/*** AccessElements ***/
int AccessElements()
{
    /**
     * .count()
     * .find()
     * .begin() -> .end()
     * .rbegin() -> .rend()
    */
    set<int> ranks = {3, 3, 1, 20};
    cout << "Count of 3: " << ranks.count(3) << endl;

    set<int>::iterator foundIt = ranks.find(1);
    if (foundIt == ranks.end())
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "Fount " << *foundIt << endl;
    }

    // (C++20)
    // cout << "Contains 3: " << ranks.contains(3) << endl;

    cout << "begin() -> end() : ";
    for (set<int>::iterator itr = ranks.begin(); itr != ranks.end(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

    cout << "rbegin() -> rend() : ";
    for (set<int>::reverse_iterator itr = ranks.rbegin(); itr != ranks.rend(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

    // for (int rank : ranks)
    // {
    //     cout << rank << endl;
    // }

    return 0;
}

/*** Modifiers ***/
int Modifiers()
{
    /**
     * .insert(), .emplace()
     * .erase()
    */
    set<int> ranks = {3, 3, 1, 20};

    ranks.insert(4);
    // ranks.emplace(4);
    printContainer("After insert", ranks);

    cout << "Size : " << ranks.size() << endl;
    cout << "Empty : " << ranks.empty() << endl;

    cout << "4 Erase Count : " << ranks.erase(4) << endl;
    printContainer("After erase(4)", ranks);

    set<int>::iterator itr = ranks.erase(ranks.begin());
    printContainer("After erase(ranks.begin())", ranks);
    cout << "erase return value " << *itr << endl;

    cout << "Before clear, Size : " << ranks.size() << endl;
    ranks.clear();
    cout << "After clear, Size : " << ranks.size() << endl;

    return 0;
}

/*** User Defined Data Types ***/

class SuperHero
{
public:
    string name;
    int power;
    SuperHero(string nm, int pwr) : name(nm), power(pwr) {}
    SuperHero(const SuperHero &hero)
    {
        name = hero.name;
        power = hero.power;
    }
};

bool operator<(const SuperHero &hero1, const SuperHero &hero2)
{
    return hero1.power < hero2.power;
}

bool operator>(const SuperHero &hero1, const SuperHero &hero2)
{
    return hero1.power > hero2.power;
}

int UserDefinedDataTypes()
{
    set<SuperHero> ascendingRanks = {
        {"Superman", 120},
        {"Batman", 100},
        {"Flash 1", 110},
        {"Flash 2", 110},
        {"Flash 3", 110},
    };

    for (auto hero : ascendingRanks)
    {
        cout << "{" << hero.name << ", " << hero.power << "}, " << endl;
    }

    cout << endl;

    return 0;
}