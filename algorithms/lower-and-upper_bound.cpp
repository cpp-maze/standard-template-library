#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*** lower_bound ***/
int main()
{
    vector<int> nums{3, 4, 4, 5, 5, 5, 7, 10};

    vector<int>::iterator itr = lower_bound(nums.begin(), nums.end(), 5);

    if (itr == nums.end())
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Found " << *itr << endl;
    }

    return 0;
}

/*** upper_bound ***/
int UpperBound()
{
    vector<int> nums{3, 4, 4, 5, 5, 5, 7, 10};

    vector<int>::iterator itr = upper_bound(nums.begin(), nums.end(), 5);

    if (itr == nums.end())
    {
        cout << "Not found" << endl;
    }
    else
    {
        cout << "Found " << *itr << endl;
    }

    return 0;
}
