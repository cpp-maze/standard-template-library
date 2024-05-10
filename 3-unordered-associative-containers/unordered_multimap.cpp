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
    unordered_multimap<int, string> colorCodes1;

    unordered_multimap<int, string> colorCodes2{
        {10, "red"},
        {20, "green"},
        {20, "orange"},
        {30, "blue"}};

    printContainer("Unordered multimap values", colorCodes2);

    return 0;
}

/*** Element access ***/
int ElementAccess()
{
    /**
     * .count()
     * .find()
     * .begin() -> .end()
     * .equal_range()
     */
    unordered_multimap<int, string> colorCodes{
        {10, "red"},
        {20, "green"},
        {20, "orange"},
        {30, "blue"}};

    cout << "count(20): " << colorCodes.count(20) << endl;

    unordered_multimap<int, string>::iterator foundIt = colorCodes.find(10);

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

    cout << "equal_range(): " << endl;

    auto itrPair = colorCodes.equal_range(20);
    auto low = itrPair.first;

    while (low != itrPair.second)
    {
        cout << low->first << " --> " << low->second << endl;
        low++;
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
    unordered_multimap<int, string> colorCodes{
        {10, "red"},
        {20, "green"},
        {30, "blue"}};

    // colorCodes.insert(make_pair(40, "orange"));
    // colorCodes.insert(make_pair(40, "new orange"));
    colorCodes.emplace(40, "orange");
    colorCodes.emplace(40, "new orange");

    printContainer("After insert", colorCodes);

    cout << "equal_range(): " << endl;

    auto itrPair = colorCodes.equal_range(40);
    auto low = itrPair.first;

    while (low != itrPair.second)
    {
        low->second = "light orange";
        low++;
    }
    cout << endl;

    printContainer("After equal_range()", colorCodes);

    colorCodes.erase(30);
    printContainer("After erase(30)", colorCodes);

    cout << "Before clear, Size : " << colorCodes.size() << endl;
    colorCodes.clear();
    cout << "After clear, Size : " << colorCodes.size() << endl;

    return 0;
}