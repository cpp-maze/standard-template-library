#include <iostream>
#include <deque>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    stack<int> varName;

    vector<int> input{1, 2};
    stack<int, vector<int>> nums(input);

    nums.push(10);
    nums.push(90);
    nums.push(80);
    nums.push(70);

    cout << "Size : " << nums.size() << endl;
    cout << "Top : " << nums.top() << endl;

    nums.pop();

    cout << "After pop" << endl;
    cout << "Size : " << nums.size() << endl;
    cout << "Top : " << nums.top() << endl;

    // Not possible to iterate elements
    // for (auto name : nums)
    // {
    //     cout << name << " ";
    // }

    while (nums.empty() == false)
    {
        cout << nums.top() << " ";
        nums.pop();
    }

    cout << endl;
    return 0;
}