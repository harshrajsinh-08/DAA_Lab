#include <iostream>
using namespace std;
struct Point {
    int x, y;
};
int direction(Point p1, Point p2, Point p3) {
    return (p3.x - p1.x) * (p2.y - p1.y) - (p2.x - p1.x) * (p3.y - p1.y);
}
bool on_segment(Point p1, Point p2, Point p3) {
    return (p3.x >= min(p1.x, p2.x) && p3.x <= max(p1.x, p2.x) &&
            p3.y >= min(p1.y, p2.y) && p3.y <= max(p1.y, p2.y));
}
bool segments_intersect(Point p1, Point p2, Point p3, Point p4) {
    int d1 = direction(p3, p4, p1);
    int d2 = direction(p3, p4, p2);
    int d3 = direction(p1, p2, p3);
    int d4 = direction(p1, p2, p4);

    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
        return true;
    } else if (d1 == 0 && on_segment(p3, p4, p1)) {
        return true;
    } else if (d2 == 0 && on_segment(p3, p4, p2)) {
        return true;
    } else if (d3 == 0 && on_segment(p1, p2, p3)) {
        return true;
    } else if (d4 == 0 && on_segment(p1, p2, p4)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Point p1 = {1, 1};
    Point p2 = {4, 4};
    Point p3 = {1, 4};
    Point p4 = {4, 1};

    cout<<endl;
    if (segments_intersect(p1, p2, p3, p4)) {
        cout << "Segments intersect." << endl;
    } else {
        cout << "Segments do not intersect." << endl;
    }
    cout<<endl;
    cout<<"NAME : HARSHRAJSINH ZALA"<<endl;
    cout<<"ROLL NO : 22BCE2238"<<endl;

    return 0;
}
