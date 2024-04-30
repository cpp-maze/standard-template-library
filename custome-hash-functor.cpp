#include <iostream>
#include <vector>

using namespace std;

int main()
{
    hash<int> intHash;
    cout << "intHash(1) = " << intHash(1) << endl;

    // hash<pair<int, int>> pairHash; // this will throw error

    hash<long> longHash;
    cout << "longHash(1) = " << longHash(1) << endl;

    hash<double> doubleHash;
    cout << "doubleHash(1) = " << doubleHash(1) << endl;

    cout << "hash('1234') = " << hash<string>()("1234") << endl;
    cout << "hash('4321') = " << hash<string>{}("4321") << endl;
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
};

struct SuperHeroHash
{
    hash<string> stringHash;
    hash<int> intHash;

    size_t operator()(const SuperHero &hero)
    {
        size_t nameValue = stringHash(hero.name);
        size_t powerValue = intHash(hero.power);
        return nameValue ^ (powerValue << 1);
    }
};

int UserDefinedObjects()
{
    SuperHero batman("Batman", 100);
    SuperHero superman("Superman", 120);

    SuperHeroHash heroHash;

    cout << "heroHash(batman) = " << heroHash(batman) << endl;
    cout << "heroHash(superman) = " << heroHash(superman) << endl;

    return 0;
}
