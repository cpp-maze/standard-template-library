#include <iostream>
#include <tuple>

using namespace std;

pair<char, float> getGrade()
{
    return {'C', 7.90};
    // return pair<char, float>('A', 9.5);
    // return make_pair('A', 9.5);
}

int main()
{
    /*** Declarations ***/
    pair<char, float> values1;
    pair<char, float> values2{'A', 1.2};

    values1 = values2;

    /*** first and second property ***/

    cout << values1.first << ", " << values1.second << endl;

    pair<char, float> myGrade = getGrade();
    cout << myGrade.first << ", " << myGrade.second << endl;

    /*** tie function ***/
    cout << "tie function" << endl;

    char grade;
    float percentage;

    tie(grade, percentage) = getGrade();

    cout << "With tie() : " << grade << "  " << percentage << endl;

    return 0;
}