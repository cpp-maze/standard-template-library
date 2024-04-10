#include <iostream>
#include <tuple>

using namespace std;

tuple<char, float> getGrade()
{
    return {'C', 7.90};
    // return tuple<char, float>('A', 9.4);
    // return make_tuple('A', 9.4);
}

int main()
{
    /*** Declarations ***/
    tuple<int, char, float> values1;
    tuple<int, char, float> values2{1, 'A', 1.5};

    values1 = values2;

    /*** get function ***/
    cout << "get function" << endl;
    cout << get<0>(values1) << endl;
    cout << get<1>(values1) << endl;
    cout << get<2>(values1) << endl;


    tuple<char, float> myGrade = getGrade();

    cout << get<0>(myGrade) << "  " << get<1>(myGrade) << endl;

    /*** tie function ***/
    cout << "tie function" << endl;
    char grade;
    float percentage;

    tie(grade, percentage) = getGrade();

    cout << "With tie() : " << grade << "  " << percentage << endl;

    return 0;
}