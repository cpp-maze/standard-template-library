#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*** Max Priority ***/
int main()
{
    priority_queue<int> marks{1, 2};

    marks.push(10);
    marks.push(1);
    marks.push(100);
    marks.push(19);
    marks.push(78);
    // marks.emplace(78);

    cout << "Top : " << marks.top() << endl;
    cout << "Elements : ";

    // Not possible to iterate elements, below code will throw error
    // for (auto mark : marks)
    // {
    //     cout << mark << " ";
    // }

    while (marks.empty() == false)
    {
        cout << marks.top() << " ";
        marks.pop();
    }
    cout << endl;

    return 0;
}

/*** Min Priority ***/
int MinPriority()
{
    priority_queue<int, vector<int>, greater<int>> marks;

    marks.push(10);
    marks.push(1);
    marks.push(100);
    marks.push(19);
    marks.push(78);

    cout << "Top : " << marks.top() << endl;
    cout << "Elements : ";

    while (marks.empty() == false)
    {
        cout << marks.top() << " ";
        marks.pop();
    }
    cout << endl;

    return 0;
}

class User
{
public:
    string name;
    User(string userName)
    {
        this->name = userName;
    }
};

struct UserLessFunctor
{
    bool operator()(const User &user1, const User &user2)
    {
        return user1.name < user2.name;
    }
};

/*less (<)*/
// bool operator<(const User &user1, const User &user2)
// {
//     return user1.name < user2.name;
// }

/*** Custom class ***/
int CustomClass()
{
    priority_queue<User, vector<User>, UserLessFunctor> marks;

    marks.emplace("a");
    marks.emplace("b");
    marks.emplace("c");
    marks.emplace("z");
    // marks.push(User("a"));

    cout << "Top : " << marks.top().name << endl;
    cout << "Elements : ";

    while (marks.empty() == false)
    {
        cout << marks.top().name << ", ";
        marks.pop();
    }
    cout << endl;

    return 0;
}