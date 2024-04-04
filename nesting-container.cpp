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

int main() {
    // one dimensional Array
    vector<int> oneDimensionalArray{1, 2, 4, 10};

    printList("oneDimensionalArray: ", oneDimensionalArray);

    // two dimensional Array
    vector<vector<int>> twoDimensionalArray(3, vector<int>(3, 0));
    // twoDimensionalArray.push_back(vector<int>(3, 0));
    // twoDimensionalArray.emplace_back(3, 1);

    cout << "twoDimensionalArray: " << endl;

    for (int r = 0; r < twoDimensionalArray.size(); r++) {
        cout << "row " << r << ": ";
        for (int c = 0; c < twoDimensionalArray[r].size(); c++) {
            cout << twoDimensionalArray[r][c] << ", ";
        }
        cout << endl;
    }

    // three dimensional Array
    vector<vector<vector<int>>> threeDimensionalArray(3, vector<vector<int>>(3, vector<int>(3, 0)));

    return 0;
}