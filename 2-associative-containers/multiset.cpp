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
    multiset<int> ranks1;
    multiset<int> ranks2 = {5, 2, 2, 1, 10, 5};
    multiset<int> ranks3{5, 2, 2, 1, 10, 5};

    vector<int> input{1, 2, 0, 0, 10};
    multiset<int, std::greater<>> ranks4(input.begin(), input.end());

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
     * .lower_bound(), .upper_bound()
     */
    multiset<int> ranks = {5, 5, 1, 20, 11, 1, 5};
    cout << "Count of 5: " << ranks.count(5) << endl;

    multiset<int>::iterator foundIt = ranks.find(5);
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
    for (multiset<int>::iterator itr = ranks.begin(); itr != ranks.end(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

    cout << "rbegin() -> rend() : ";
    for (multiset<int>::reverse_iterator itr = ranks.rbegin(); itr != ranks.rend(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

    // for (int rank : ranks)
    // {
    //     cout << rank << endl;
    // }

    multiset<int>::iterator positionItr = ranks.lower_bound(3);
    cout << "Elements after 3 : ";
    while (positionItr != ranks.end())
    {
        cout << *positionItr << " ";
        positionItr++;
    }
    cout << endl;

    multiset<int>::iterator positionLowerItr = ranks.lower_bound(5);
    multiset<int>::iterator positionUpperItr = ranks.upper_bound(5);

    cout << "Elements from 5 lower to 5 upper : ";
    while (positionLowerItr != positionUpperItr)
    {
        cout << *positionLowerItr << " ";
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
     * .erase()
     */
    multiset<int> ranks = {3, 3, 2, 2, 4, 4, 1, 20};

    ranks.insert(4);
    // ranks.emplace(4);
    printContainer("After insert", ranks);

    cout << "4 Erase Count : " << ranks.erase(4) << endl;
    printContainer("After erase(4)", ranks);

    ranks.erase(ranks.begin());
    printContainer("After erase(ranks.begin())", ranks);

    cout << "Before clear, Size : " << ranks.size() << endl;
    ranks.clear();
    cout << "After clear, Size : " << ranks.size() << endl;

    return 0;
}
