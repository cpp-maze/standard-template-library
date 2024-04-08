#include <iostream>
#include <list>

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
    list<int> nums1;
    list<int> nums2 = {1, 2, 3};
    list<int> nums3{10, 20, 30};

    printList("list values", nums3);

    return 0;
}

/*** Element access ***/
int ElementAccess()
{
    /**
     * .front()
     * .back()
     * .begin() -> .end()
     * .rbegin() -> .rend()
     */
    list<int> nums{1, 10, 2, 20, 3, 30};

    cout << "Front : " << nums.front() << endl;
    cout << "Back : " << nums.back() << endl;

    cout << "Asc : ";
    for (list<int>::iterator itr = nums.begin(); itr != nums.end(); ++itr)
    {
        cout << *itr << " ";
    }
    cout << endl;

    cout << "Desc : ";
    for (list<int>::reverse_iterator itr = nums.rbegin(); itr != nums.rend(); ++itr)
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
     * .push_front(), emplace_front()
     * .push_back(), emplace_back()
     * .pop_front()
     * .pop_back()
     */
    list<int> nums{100};

    nums.insert(nums.begin(), 20);
    nums.insert(nums.begin(), {8, 9});
    // nums.emplace(nums.begin(), 20);

    cout << "size(): " << nums.size() << endl;
    printList("After insert", nums);

    nums.push_back(2);
    // nums.emplace_back(2);
    nums.push_front(0);
    // nums.emplace_front(2);

    printList("After push", nums);

    nums.pop_front();
    nums.pop_back();

    printList("After pop", nums);

    return 0;
}

/*** Operations ***/
int Operations()
{
    /**
     * .reverse()
     * .sort()
     * .remove()
     * .remove_if()
    */

    list<int> nums{1, 10, 2, 20, 30, 20};

    nums.reverse();

    printList("reverse", nums);

    nums.sort();

    printList("sort", nums);

    nums.remove(20);

    printList("remmove 20", nums);

    nums.remove_if([](int num)
                   { return num < 10; });

    printList("remove_if num < 10", nums);

    return 0;
}