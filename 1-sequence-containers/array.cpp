#include <iostream>
#include <array>

using namespace std;

void printList(string title, const auto &data)
{
    cout << title << endl;
    for (auto datum : data)
    {
        cout << datum << " ";
    }
    cout << endl;
}

/*** Declaration ***/
int main()
{
    array<int, 10> nums1;

    // Declaration with initialization
    array<int, 10> nums2 = {1, 2}; // initializer list
    array<int, 10> nums3{1, 2};    // uniform initialization

    // assign values using initializer list
    nums1 = {1, 2};

    printList("Array values ", nums1);
    return 0;
}

/*** Element access ***/
int ElementAccess()
{
    array<int, 5> nums{1, 2, 4, 10, 11};

    cout << "nums[0] : " << nums[0] << endl;
    nums[0] = 100;

    cout << "nums[0] : " << nums[0] << endl;

    cout << "nums.at(0) : " << nums.at(0) << endl;

    cout << "nums.front() : " << nums.front() << endl;

    cout << "nums.back() : " << nums.back() << endl;

    return 0;
}

/*** Other useful methods ***/
int Other()
{
    array<int, 5> nums{1, 2, 4, 10, 11};

    cout << nums.size() << endl;

    printList("Before fill", nums);
    nums.fill(0);
    printList("After fill", nums);

    return 0;
}
