#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> nums{1, 2, 4, 5, 6};

    cout << boolalpha;

    cout << "Find 5 : " << binary_search(nums.begin(), nums.end(), 5) << endl;
    cout << "Find 10 : " << binary_search(nums.begin(), nums.end(), 10) << endl;

    return 0;
}