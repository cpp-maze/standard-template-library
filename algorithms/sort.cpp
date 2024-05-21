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
    vector<int> nums{2, 4, 1, 6, 5};

    sort(nums.begin(), nums.end());
    printContainer("Asc order", nums);

    sort(nums.begin(), nums.end(), greater<>());
    // sort(nums.rbegin(), nums.rend());
    printContainer("Desc order", nums);

    sort(nums.begin(), nums.end(), [](int a, int b)
         { return a > b; });
    printContainer("Using Compare function", nums);

    vector<pair<int, int>> points;
    points.emplace_back(2, 3);
    points.emplace_back(1, 0);
    points.emplace_back(1, 3);
    points.emplace_back(0, 2);
    points.emplace_back(1, 1);

    cout << "Before sort" << endl;
    for (auto point : points)
    {
        cout << "(" << point.first << ", " << point.second << "), ";
    }
    cout << endl;

    sort(points.begin(), points.end());

    cout << "After sort" << endl;
    for (auto point : points)
    {
        cout << "(" << point.first << ", " << point.second << "), ";
    }
    cout << endl;
    return 0;

    return 0;
}