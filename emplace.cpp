#include <iostream>
#include <vector>

using namespace std;

class Point {
    public:
        int x, y;
        Point(int parm1 = 0, int parm2 = 0) {
            x = parm1;
            y = parm2;
            cout << "Point constructor" << endl;
        }
        Point(const Point &point) {
            x = point.x;
            y = point.y;
            cout << "Point copy constructor" << endl;
        }
};

int main() {
    vector<Point> points;

    points.insert(points.end(), Point(10, 20));
    // points.emplace(points.end(), 10, 20);

    for (auto &point : points) {
        cout << "(" << point.x << ", " << point.y << ") ";
    }

    cout << endl;

    return 0;
}