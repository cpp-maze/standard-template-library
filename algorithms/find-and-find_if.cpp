#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/*** Find ***/
int main()
{
    vector<int> vectorNums{2, 4, 1, 6, 5};
    int ranks[]{2, 4, 1, 6, 5};
    set<int> setNums{2, 4, 1, 6, 5};

    cout << "find() function" << endl;
    vector<int>::iterator pos = find(vectorNums.begin(), vectorNums.end(), 5);
    // set<int>::iterator pos = find(setNums.begin(), setNums.end(), 5); // not recommended, use find method available in set

    if (pos != vectorNums.end())
    {
        cout << "found 5" << endl;
    }
    else
    {
        cout << "not found 5" << endl;
    }

    return 0;
}

/*** Find If ***/
int FindIf()
{
    vector<int> vectorNums{2, 4, 1, 6, 5};
    cout << "find_if() function" << endl;

    auto pos = find_if(vectorNums.begin(), vectorNums.end(), [](int num)
                       { return num == 5; });

    if (pos != vectorNums.end())
    {
        cout << "found 5" << endl;
    }
    else
    {
        cout << "not found 5" << endl;
    }

    return 0;
}