#include <iostream>
#include <vector>
#include <algorithm>

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

int main()
{
    vector<int> nums{1, 2, 4, 8, 16};

    reverse(nums.begin(), nums.end());

    printContainer("After reverse", nums);

    return 0;
}