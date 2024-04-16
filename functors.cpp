#include <iostream>

using namespace std;

class Hello
{
public:
    void operator()()
    {
        cout << "Hello" << endl;
    }
};

int main()
{
    Hello sayHello;

    sayHello();

    return 0;
}

/* less and greater functor */
int LessAndGreater()
{
    less<int> isLess;

    cout << "less" << endl;
    cout << "(1 < 2) = " << isLess(1, 2) << endl;
    cout << "(2 < 1) = " << isLess(2, 1) << endl;

    greater<int> isGreater;

    cout << "greater" << endl;
    cout << "(1 > 2) = " << isGreater(1, 2) << endl;
    cout << "(2 > 1) = " << isGreater(2, 1) << endl;

    return 0;
}