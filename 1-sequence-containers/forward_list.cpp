#include <iostream>
#include <forward_list>

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

/*** Declaration ***/
int main()
{
    forward_list<int> nums1;
    forward_list<int> nums2 = {1, 2, 4, 16};
    forward_list<int> nums3{32, 64};
    nums1 = {10, 20};
    nums2 = nums3;
    printList("nums1", nums1);
    printList("nums2", nums2);

    return 0;
}

/*** Element access ***/
int ElementAccess()
{
    /**
     * .front()
     * .begin() -> .end()
     * .before_begin()
     */

    forward_list<int> nums{1, 2, 4, 16};

    cout << "front(): " << nums.front() << endl;

    for (forward_list<int>::iterator itr = nums.begin(); itr != nums.end(); itr++)
    {
        cout << *itr << " -> ";
    }
    cout << endl;

    // forward_list<int>::iterator itr = nums.before_begin();
    // itr++;
    // cout << *itr << endl;
}

/*** Modifiers ***/
int Modifiers()
{
    /**
     * .insert_after(), .emplace_after()
     * .push_front(), .emplace_front()
     * .erase_after()
     * .pop_front()
     */
    forward_list<int> nums{1, 2, 4, 16};

    nums.insert_after(nums.before_begin(), 50);
    // nums.emplace_after(nums.before_begin(), 50);
    printList("insert at front", nums);

    // nums.push_front(20);
    // // nums.emplace_front(20);
    // printList("insert at front", nums);

    nums.erase_after(nums.begin());
    printList("erase_after", nums);

    // nums.pop_front();
    // printList("pop_front", nums);

    return 0;
}

/*** Operations ***/
int Operations()
{
    /**
     * .reverse()
     * .sort()
     * .merge()
     * .splice_after()
     * .remove()
     * .remove_if()
     */
    forward_list<int> nums1{4, 16, 1, 2};
    forward_list<int> nums2{32, 30, 64, 30};

    nums1.reverse();
    printList("reverse", nums1);

    nums1.sort();
    printList("sorted nums1", nums1);

    forward_list<int> allNums;
    allNums.merge(nums1);
    allNums.merge(nums2);

    cout << "After merge" << endl;
    cout << "nums1.empty() : " << nums1.empty() << endl;
    cout << "nums2.empty() : " << nums2.empty() << endl;

    printList("allNums ", allNums);

    forward_list<int> nums3{-1, -2};
    allNums.splice_after(allNums.begin(), nums3);
    printList("splice_after ", allNums);
    cout << "nums3.empty() : " << nums3.empty() << endl;

    allNums.remove(30);
    printList("remove 30", allNums);

    allNums.remove_if([](int num)
                      { return num < 0; });
    printList("remove_if negatives", allNums);

    return 0;
}