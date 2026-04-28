/*
 * 2D Point/Vector Structure
 */
using ftype = double;
const double EPS = 1e-9;

struct Point {
    ftype x, y;
    Point() {}
    Point(ftype x, ftype y): x(x), y(y) {}
    Point& operator+=(const Point &t) { x += t.x; y += t.y; return *this; }
    Point& operator-=(const Point &t) { x -= t.x; y -= t.y; return *this; }
    Point& operator*=(ftype t) { x *= t; y *= t; return *this; }
    Point& operator/=(ftype t) { x /= t; y /= t; return *this; }
    Point operator+(const Point &t) const { return Point(*this) += t; }
    Point operator-(const Point &t) const { return Point(*this) -= t; }
    Point operator*(ftype t) const { return Point(*this) *= t; }
    Point operator/(ftype t) const { return Point(*this) /= t; }
};

ftype dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
ftype cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
bool ccw(Point a, Point b){ return cross(a,b) > 0; }
ftype norm(Point a) { return dot(a, a); }
double abs(Point a) { return sqrt(norm(a)); }
double angle(Point a, Point b) { return acos(dot(a, b) / abs(a) / abs(b)); }
