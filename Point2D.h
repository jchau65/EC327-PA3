#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>

#include "Vector2D.h"

using namespace std;

/**
 * @brief A class that represents a point in 2D space.
 */
class Point2D {
    public:
        double x; // X-coordinate of the point
        double y; // Y-coordinate of the point

        /**
         * @brief Default constructor for Point2D. Sets x to 0 and y to 0.
         */
        Point2D();

        /**
         * @brief Creates a new Point2D with user-specified x and y.
         * 
         * @param in_x X value of the point
         * @param in_y Y value of the point
         */
        Point2D(const double in_x, const double in_y);
};

/**
 * @brief Returns the Cartesian (ordinary) distance between two points.
 * 
 * @param p1 1st point
 * @param p2 2nd point
 * 
 * @return Double value representing the distance between the two specified points.
 */
double GetDistanceBetween(const Point2D& p1, const Point2D& p2);

/**
 * @brief
 * Produces output formatted as (x, y).
 * 
 * Example: If p1 has x = 3.14, y = 7.07, then cout << p1 will print (3.14, 7.07).
 * 
 * @param out Output stream to output to.
 * @param point Point to print out.
 * 
 * @return Specified output stream.
 */
ostream& operator<<(ostream& out, const Point2D& point);

/**
 * @brief Returns a new Point2D object with x = p1.x + v1.x and y = p1.y + v1.y.
 * 
 * @param point Point to be added to.
 * @param vector Vector to add to point.
 * 
 * @return New Point2D sum.
 */
Point2D operator+(const Point2D& point, const Vector2D& vector);

/**
 * @brief Return a new Point2D object with x = p1.x - p2.x and y = p1.y - p2.y.
 * 
 * @param p1 Point to be subtracted from.
 * @param p2 Point that is subtracted from the other point.
 * 
 * @return Resulting Point2D object
 */
Vector2D operator-(const Point2D& p1, const Point2D& p2);

#endif