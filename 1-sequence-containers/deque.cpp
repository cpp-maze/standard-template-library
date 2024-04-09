#include <iostream>
#include <list>
#include <forward_list>
#include <deque>

using namespace std;

void printList(string title, const auto &string_list)
{
    cout << title << endl;
    for (auto item : string_list)
    {
        cout << item << " ";
    }
    cout << endl;
}

/*** Declarations ***/
int main()
{
    deque<int> nums1;
    deque<int> nums2 = {1, 2, 3};
    deque<int> nums3{10, 20, 30};

    list<int> input{10, 20, 30, 40};

    deque<int> output(input.begin(), input.end());

    printList("deque values", output);

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
    deque<int> nums{1, 2, 4, 10};

    cout << "nums[0] : " << nums[0] << endl;
    nums[0] = 100;
    cout << "nums[0] : " << nums[0] << endl;

    cout << "nums.at(2) : " << nums.at(2) << endl;

    cout << "nums.front() : " << nums.front() << endl;

    cout << "nums.back() : " << nums.back() << endl;

    cout << "begin() -> end() : ";
    for (deque<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

    cout << "rbegin() -> rend() : ";
    for (deque<int>::reverse_iterator itr = nums.rbegin(); itr != nums.rend(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

    return 0;
}

/*** Modifiers ***/
int Modifiers()
{
    /**
     * .insert(), .emplace()
     * .push_back(), .emplace_back()
     * .push_front(), .emplace_front()
     * .erase()
     * .pop_front()
     * .pop_back()
     * .clear()
     */

    deque<int> nums{2, 4};

    nums.insert(nums.begin(), 10);

    cout << "size(): " << nums.size() << endl;
    printList("After Insert", nums);

    nums.push_back(16);
    // nums.emplace_back(16);
    nums.push_front(1);
    // nums.emplace_front(1);

    printList("After push", nums);

    nums.erase(nums.begin());

    printList("After erase", nums);

    nums.pop_front();
    nums.pop_back();

    printList("After pop", nums);

    cout << "Before clear " << endl;
    cout << "nums.size(): " << nums.size() << ",  nums.empty(): " << nums.empty() << endl;
    nums.clear();
    cout << "After clear " << endl;
    cout << "nums.size(): " << nums.size() << ",  nums.empty(): " << nums.empty() << endl;

    return 0;
}