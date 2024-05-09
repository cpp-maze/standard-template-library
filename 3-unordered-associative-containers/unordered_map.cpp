#include <iostream>
#include <unordered_map>

using namespace std;

void printContainer(string title, const auto &values)
{
    cout << title << endl;

    for (auto it = values.begin(); it != values.end(); it++)
    {
        cout << it->first << " --> " << it->second << endl;
    }

    cout << endl;
}

/*** Declarations ***/
int main()
{
    unordered_map<string, int> colorCodes1;

    unordered_map<int, string> colorCodes2{
        {10, "red"},
        {20, "green"},
        {20, "orange"},
        {30, "blue"}};

    printContainer("Unordered map values", colorCodes2);

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
     */
    unordered_map<int, string> colorCodes{
        {10, "red"},
        {20, "green"},
        {30, "blue"}};

    cout << "colorCodes[10] : " << colorCodes[10] << endl;
    cout << "colorCodes.at(10) : " << colorCodes.at(10) << endl;

    unordered_map<int, string>::iterator foundIt = colorCodes.find(10);

    cout << "find(10): " << endl;

    if (foundIt == colorCodes.end())
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "FoundIt : " << foundIt->first << " --> " << foundIt->second << endl;
    }

    // (C++20)
    // cout << "Contains 10: " << colorCodes.contains(10) << endl;

    cout << "begin() -> end() : " << endl;
    for (auto itr = colorCodes.begin(); itr != colorCodes.end(); ++itr)
    {
        cout << itr->first << " --> " << itr->second << endl;
    }
    cout << endl;

    // for (auto &colorCode : colorCodes)
    // {
    //     cout << colorCode.first << " --> " << colorCode.second << endl;
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
    unordered_map<int, string> colorCodes{
        {10, "red"},
        {20, "green"},
        {30, "blue"}};

    // colorCodes.insert(make_pair(40, "orange"));
    // colorCodes.insert(make_pair(40, "new orange"));
    // colorCodes.emplace(40, "orange");
    // colorCodes.emplace(40, "new orange");
    colorCodes[40] = "orange";
    colorCodes[40] = "new orange";

    printContainer("After insert", colorCodes);

    colorCodes.erase(20);
    printContainer("After erase(20)", colorCodes);

    cout << "Before clear, Size : " << colorCodes.size() << endl;
    colorCodes.clear();
    cout << "After clear, Size : " << colorCodes.size() << endl;
}

/*** User Defined objects ***/
class SuperHero
{
public:
    string name;
    int power;
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
    unordered_map<SuperHero, int, SuperHeroHash> heros{
        // {{"Batman", 100}, 10}
    };

    // heros.insert(make_pair(SuperHero("Batman", 100), 10));

    // heros.emplace(SuperHero("Batman", 100), 10);

    heros.emplace(std::piecewise_construct,
                  std::forward_as_tuple("Batman", 100),
                  std::forward_as_tuple(10));

    for (auto &hero : heros)
    {
        cout << "{" << hero.first.name << ", " << hero.first.power << "} --> ";
        cout << hero.second << endl;
    }

    return 0;
}