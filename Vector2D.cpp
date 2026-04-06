#include <iostream>

#include "Vector2D.h"

using namespace std;

Vector2D::Vector2D() : x(0), y(0) {}

Vector2D::Vector2D(const double in_x, const double in_y) : x(in_x), y(in_y) {}

Vector2D operator*(const Vector2D& vector, const double mult) {
    // Return a new Vector2D with the multiplied x and y
    return Vector2D(vector.x * mult, vector.y * mult);
}

Vector2D operator/(const Vector2D& vector, const double div) {
    // Return a new Vector2D with the divided x and y
    return Vector2D(vector.x / div, vector.y / div);
}

ostream& operator<<(ostream& out, const Vector2D& vector) {
    // Print out the right x, y in the correct format
    out << "<" << vector.x << ", " << vector.y << ">";

    // Return the output stream
    return out;
}