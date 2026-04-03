#include <cmath>
#include <iostream>

#include "Point2D.h"

using namespace std;

Point2D::Point2D() : x(0), y(0) {} 

Point2D::Point2D(const double in_x, const double in_y) : x(in_x), y(in_y) {}

double GetDistanceBetween(const Point2D& p1, const Point2D& p2) {
    // Return a distance using the Pythagorean Theorem
    return sqrt(pow(abs(p1.x - p2.x), 2) + pow(abs(p1.y - p2.y), 2));
}

ostream& operator<< (ostream& out, const Point2D& point) {
    // Print out the x and y coordinate in the right format
    out << "(" << point.x << ", " << point.y << ")";

    // Return the out stream
    return out;
}

Point2D operator+ (const Point2D& point, const Vector2D& vector) {
    // Return a new point 2D with added x and y values
    return Point2D(point.x + vector.x, point.y + vector.y);
}

Point2D operator- (const Point2D& p1, const Point2D& p2) {
    // Return a new point 2D with subtracted x and y values
    return Point2D(p1.x - p2.x, p1.y - p2.y);
}
