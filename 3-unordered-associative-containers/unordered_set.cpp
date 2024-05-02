#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void printContainer(string title, const auto &values)
{
    cout << title << endl;

    for (auto it = values.begin(); it != values.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
}

/*** Declarations ***/
int main()
{
    unordered_set<int> ranks1;
    unordered_set<int> ranks2{10, 5, 5, 4, 2, 2, 1, 20};

    vector<int> input{10, 5, 5, 4, 2, 2, 1, 20};
    unordered_set<int> ranks3(input.begin(), input.end());

    printContainer("unordered set values", ranks3);
}

/*** Access Element ***/
int AccessElement()
{
    /**
     * .count()
     * .find()
     * .begin() -> .end()
     */
    unordered_set<int> ranks{3, 3, 1, 20};
    cout << "Count of 3: " << ranks.count(3) << endl;

    unordered_set<int>::iterator foundIt = ranks.find(1);
    if (foundIt != ranks.end())
    {

        cout << "Fount 1" << endl;
    }
    else
    {

        cout << "Not Found 1" << endl;
    }

    // cout << "Contains 3: " << ranks.contains(3) << endl;

    cout << "begin() -> end() : ";
    for (unordered_set<int>::iterator itr = ranks.begin(); itr != ranks.end(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

    // for (auto rank : ranks)
    // {
    //     cout << rank << " ";
    // }

    return 0;
}

/*** Modifiers ***/
int Modifiers()
{
    /**
     * .insert(), .emplace()
     * .erase()
     * .clear()
     */
    unordered_set<int> ranks{3, 3, 1, 20};

    ranks.insert(4);
    // ranks.emplace(4);
    printContainer("After insert", ranks);

    cout << "10 Erase Count : " << ranks.erase(10) << endl;
    printContainer("After erase(10)", ranks);

    cout << "Before clear, Size : " << ranks.size() << endl;
    ranks.clear();
    cout << "After clear, Size : " << ranks.size() << endl;

    return 0;
}

/*** User Defined objects ***/
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
    bool operator==(const SuperHero &rhs) const noexcept
    {
        return name == rhs.name;
    }
};

struct SuperHeroHash
{
    std::hash<string> stringHash;

    size_t operator()(const SuperHero &hero) const noexcept
    {
        size_t nameValue = stringHash(hero.name);
        return nameValue;
    }
};

int UserDefinedObjects()
{
    unordered_set<SuperHero, SuperHeroHash> heros;
    heros.emplace("Batman", 100);
    heros.emplace("Superman", 120);

    for (auto &hero : heros)
    {
        cout << "{" << hero.name << ", " << hero.power << "}" << endl;
    }

    return 0;
}