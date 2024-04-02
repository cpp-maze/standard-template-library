#include <iostream>
#include <vector>

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
    vector<int> nums1;
    vector<int> nums2(10);
    vector<int> nums3(10, 0);

    // Declaration with initialization
    vector<int> nums4 = {1, 2}; // initializer list
    vector<int> nums5{3, 4};    // uniform initialization

    printList("Vector values", nums4);
    return 0;
}

/*** Element access ***/
int ElementAccess()
{
    /**
     * []
     * .at()
     * .front()
     * .back()
     * .begin() -> .end()
     * .rbegin() -> .rend()
    */
    vector<int> nums{1, 2, 4};
    cout << "nums[0] : " << nums[0] << endl;

    nums[0] = 100;

    cout << "nums[0] : " << nums[0] << endl;

    // nums.at(0) = 100 // <- this also possible

    cout << "nums.at(0) : " << nums.at(0) << endl;

    cout << "nums.front() : " << nums.front() << endl;

    cout << "nums.back() : " << nums.back() << endl;

    cout << "Asc : ";
    for (vector<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << endl;

    cout << "Desc : ";
    for (vector<int>::reverse_iterator itr = nums.rbegin(); itr != nums.rend(); ++itr) {
        cout << *itr << " ";
    }
    cout << endl;

    return 0;
}

/*** Capacity ***/
int Capacity()
{
    /**
     * .size()
     * .capacity()
     * .reserve()
     * .resize()
    */
    vector<int> nums;

    // nums.reserve(3);
    // nums.resize(3);

    cout << "size() : " << nums.size() << ", ";
    cout << "capacity() : " << nums.capacity() << endl;

    for (int i = 1; i < 12; ++i) {
        nums.push_back(i);

        cout << "size() : " << nums.size() << ", ";
        cout << "capacity() : " << nums.capacity() << endl;
    }
}

/*** Modifiers ***/
int Modifiers()
{
    /**
     * .push_back()
     * .insert()
     * .emplace_back()
     * .emplace()
     * .erase()
     * .clear()
    */
    vector<int> nums{1, 2};
    nums.push_back(4);
    nums.push_back(16);

    printList("After push_back", nums);

    nums.pop_back();

    printList("After pop_back", nums);

    nums.insert(nums.begin(), 100);
    nums.insert(nums.begin(), {200, 300});

    printList("After insert", nums);

    nums.erase(nums.begin());

    printList("After erase", nums);

    nums.clear();

    cout << "size() : " << nums.size() << ", capacity() : " << nums.capacity() << endl;

    return 0;
}