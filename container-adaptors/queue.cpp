#include <iostream>
#include <list>
#include <deque>
#include <queue>

using namespace std;

int main()
{
    queue<int> varName;

    list<int> input{0, 1};
    queue<int, list<int>> nums(input);

    nums.push(2);
    nums.push(4);
    nums.push(8);
    nums.push(16);
    // nums.emplace(30);

    cout << "Size : " << nums.size() << endl;

    cout << "Front : " << nums.front() << endl;
    cout << "Back : " << nums.back() << endl;

    nums.pop();

    cout << "After pop" << endl;

    cout << "Front : " << nums.front() << endl;
    cout << "Back : " << nums.back() << endl;

    // Not possible to iterate elements, below code will throw error
    // for (auto num : nums)
    // {
    //     cout << num << " ";
    // }

    while (nums.empty() == false)
    {
        cout << nums.front() << " ";
        nums.pop();
    }

    cout << endl;

    return 0;
}