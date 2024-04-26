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
    multimap<string, int> charCode1;

    multimap<string, int> charCode2{
        {"c", 99},
        {"c", 199},
        {"a", 97},
        {"a", 197},
        {"b", 98}};
    multimap<string, int, greater<>> charCode3{
        {"c", 99},
        {"c", 199},
        {"a", 97},
        {"a", 197},
        {"b", 98}};

    printContainer("Asc multi map values", charCode2);
    printContainer("Desc multi map values", charCode3);

    return 0;
}

/*** Element access ***/
int ElementAccess()
{
    /**
     * .find()
     * .contains()
     * .begin() -> .end()
     * .rbegin() -> .rend()
     * .lower_bound(), upper_bound()
     * .equal_range()
     */
    multimap<string, int> charCode{
        {"c", 99},
        {"c", 199},
        {"a", 97},
        {"a", 197},
        {"b", 98}};

    printContainer("charCode ", charCode);

    multimap<string, int>::iterator foundIt = charCode.find("a");
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
    for (multimap<string, int>::iterator itr = charCode.begin(); itr != charCode.end(); ++itr)
    {
        cout << itr->first << " --> " << itr->second << endl;
    }
    cout << endl;

    cout << "rbegin() -> rend(): " << endl;
    for (multimap<string, int>::reverse_iterator itr = charCode.rbegin(); itr != charCode.rend(); ++itr)
    {
        cout << itr->first << " --> " << itr->second << endl;
    }
    cout << endl;

    // for (pair<string, int> p : charCode)
    // {
    //     cout << p.first << " --> " << p.second << endl;
    // }

    /* .lower_bound(), upper_bound() */

    multimap<string, int>::iterator itr = charCode.lower_bound("b");
    cout << "Elements from 'b' key to end : ";
    while (itr != charCode.end())
    {
        cout << itr->first << " --> " << itr->second << ", ";
        itr++;
    }
    cout << endl;

    multimap<string, int>::iterator positionLowerItr = charCode.lower_bound("b");
    multimap<string, int>::iterator positionUpperItr = charCode.upper_bound("b");

    cout << "Elements in 'b' key : ";
    while (positionLowerItr != positionUpperItr)
    {
        cout << positionLowerItr->first << " --> " << positionLowerItr->second << ", ";
        positionLowerItr++;
    }
    cout << endl;

    return 0;
}

/*** Modifiers ***/
int Modifiers()
{
    /**
     * .insert(), .emplace()
     * .equal_range()
     * .erase()
     * .clear()
    */
    multimap<string, int> charCode{
        {"c", 99},
        {"c", 199},
        {"a", 97},
        {"a", 197},
        {"b", 98}};

    charCode.emplace("e", 101);
    charCode.emplace("e", 301);
    // charCode.insert(make_pair("e", 101));

    printContainer("After insert", charCode);

    auto p = charCode.equal_range("a");

    for (auto itr = p.first; itr != p.second; itr++) {
        itr->second = 0;
    }
    cout << endl;

    printContainer("After equal_range", charCode);

    cout << "Erase 'a' : " << charCode.erase("a") << endl;
    printContainer("After erase('a')", charCode);

    cout << "Before clear, Size : " << charCode.size() << endl;
    charCode.clear();
    cout << "After clear, Size : " << charCode.size() << endl;

    return 0;
}
