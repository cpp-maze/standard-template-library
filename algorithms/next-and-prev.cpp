#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

int main()
{
    list<int> nodes{2, 8, 1, 6, 5};
    vector<int> nums{2, 8, 1, 6, 5};

    list<int>::iterator nodeItr = next(nodes.begin(), 2);
    cout << "nodeItr = " << *nodeItr << endl;

    vector<int>::iterator numItr = next(nums.begin(), 2);
    cout << "numItr = " << *numItr << endl;

    vector<int>::iterator backItr = prev(nums.end(), 4);
    cout << "backItr = " << *backItr << endl;

    return 0;
}