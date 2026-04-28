/*
 * 3D Point/Vector Structure
 */
using ftype = double;

struct Point3D {
    ftype x, y, z;
    Point3D() {}
    Point3D(ftype x, ftype y, ftype z): x(x), y(y), z(z) {}
    Point3D& operator+=(const Point3D &t) { x += t.x; y += t.y; z += t.z; return *this; }
    Point3D& operator-=(const Point3D &t) { x -= t.x; y -= t.y; z -= t.z; return *this; }
    Point3D& operator*=(ftype t) { x *= t; y *= t; z *= t; return *this; }
    Point3D& operator/=(ftype t) { x /= t; y /= t; z /= t; return *this; }
    Point3D operator+(const Point3D &t) const { return Point3D(*this) += t; }
    Point3D operator-(const Point3D &t) const { return Point3D(*this) -= t; }
};

ftype dot(Point3D a, Point3D b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
Point3D cross(Point3D a, Point3D b) {
    return Point3D(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z, a.x * b.y - a.y * b.x);
}
ftype triple(Point3D a, Point3D b, Point3D c) { return dot(a, cross(b, c)); }
