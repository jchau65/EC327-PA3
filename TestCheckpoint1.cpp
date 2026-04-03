#include <iostream>

#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"

using namespace std;

int main() {
    // Create a default point
    Point2D defPoint = Point2D();
    cout << "Default Point: " << defPoint << endl;

    // Create two points
    Point2D point1 = Point2D(1, 1);
    Point2D point2 = Point2D(-1, -1);
    cout << "Point 1: " << point1 << endl;
    cout << "Point 2: " << point2 << endl;

    // Get the distance between the two points
    cout << "Distance between point 1 and point 2: " << GetDistanceBetween(point1, point2) << endl;

    // Create a default vector
    Vector2D defVector = Vector2D();
    cout << "Default Vector: " << defVector << endl;

    // Create a vector
    Vector2D vector = Vector2D(3, 3);

    // Add a point and a vector
    cout << "(1, 1) + <3, 3> = " << point1 + vector << endl;

    // Subtract two points
    cout << "(1, 1) - (-1, -1) = " << point1 - point2 << endl;

    // Multiply a vector by 10
    cout << "<3, 3> * 10 = " << vector * 10 << endl;

    // Divide a vector by 3
    cout << "<3, 3> / 3 = " << vector / 3 << endl;

    // Create a GameObject
    GameObject object1 = GameObject('a');
    GameObject object2 = GameObject(point1, 2, 'b');

    // Get locations of GameObject objects
    cout << "Object 1's Location: " << object1.GetLocation() << endl;
    cout << "Object 2's Location: " << object2.GetLocation() << endl;

    // Get id's of GameObject objects
    cout << "Object 1's ID: " << object1.GetId() << endl;
    cout << "Object 2's ID: " << object2.GetId() << endl;

    // Get states of GameObject objects
    cout << "Object 1's State: " << object1.GetState() << endl;
    cout << "Object 2's State: " << object2.GetState() << endl;

    // Show statuses of GameObject objects
    cout << "Object 1's Status: ";
    object1.ShowStatus();

    cout << "Object 2's Status: ";
    object2.ShowStatus();
}