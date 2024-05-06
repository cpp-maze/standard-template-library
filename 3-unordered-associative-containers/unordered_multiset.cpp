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
    unordered_multiset<int> ranks1;
    unordered_multiset<int> ranks2{10, 5, 5, 4, 2, 2, 1, 20};

    vector<int> input{10, 5, 5, 4, 2, 2, 1, 20};
    unordered_multiset<int> ranks3(input.begin(), input.end());

    printContainer("unorderd multiset", ranks3);

    return 0;
}

/*** Access Element ***/
int AccessElement()
{
    /**
     * .count()
     * .find()
     * .begin() -> .end()
     * .equal_range()
     */
    unordered_multiset<int> ranks = {3, 3, 1, 20};
    cout << "Count of 3: " << ranks.count(3) << endl;

    unordered_multiset<int>::iterator foundIt = ranks.find(1);
    if (foundIt == ranks.end())
    {
        cout << "Not Found 1" << endl;
    }
    else
    {
        cout << "Fount 1" << endl;
    }

    // (C++20)
    // cout << "Contains 3: " << ranks.contains(3) << endl;

    cout << "begin() -> end() : ";
    for (unordered_multiset<int>::iterator itr = ranks.begin(); itr != ranks.end(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

    // for (auto rank : ranks)
    // {
    //     cout << rank << " ";
    // }

    cout << "equal_range(): ";

    auto itrPair = ranks.equal_range(3);
    auto low = itrPair.first;

    while (low != itrPair.second)
    {
        cout << *low << " ";
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
     * .erase()
     * .clear()
     */
    unordered_multiset<int> ranks = {3, 3, 1, 20};

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
