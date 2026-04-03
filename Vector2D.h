#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

/**
 * @brief A class that represents a vector in 2D space.
 */
class Vector2D {
    public:
        double x; // X-coordinate of the vector
        double y; // Y-coordinate of the vector

        /**
         * @brief Default constructor for Vector2D. Sets x to 0 and y to 0.
         */
        Vector2D();

        /**
         * @brief Creates a new Vector2D with user-specified x and y.
         * 
         * @param in_x X value of the vector
         * @param in_y Y value of the vector
         */
        Vector2D(const double in_x, const double in_y);
};

/**
 * @brief Returns a new Vector2D object with x = vector.x * mult and y = vector.y * mult.
 * 
 * @param vector Vector to be multiplied.
 * @param mult Factor to multiply by.
 * 
 * @return Resulting Vector2D.
 */
Vector2D operator*(const Vector2D& vector, const double mult);

/**
 * @brief Returns a new Vector2B object with x = vector.x / div and y = vector.y / div.
 * 
 * @param vector Vector to be divided.
 * @param div Factor to divide by.
 * 
 * @return Resulting Vector2D.
 */
Vector2D operator/(const Vector2D& vector, const double div);

/**
 * @brief Produces output formatted as <x, y>.
 * 
 * @param out Output stream to print to.
 * @param vector Vector to be printed
 * 
 * @return Output stream
 */
ostream& operator<<(ostream& out, const Vector2D& vector);

#endif