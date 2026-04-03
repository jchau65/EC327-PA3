#include <iostream>
#include <string>

#include "Mage.h"

using namespace std;

Mage::Mage() : GameObject('M'), speed(5) {
    cout << "Mage default constructed." << endl;
}

Mage::Mage(const char in_code) : GameObject(in_code), speed(5) {
    this->state = STOPPED;
    cout << "Mage constructed." << endl;
}

Mage::Mage(const string in_name, const int in_id, const char in_code, const unsigned int in_speed, const Point2D& in_loc) : 
    GameObject(in_loc, in_id, in_code),
    speed(in_speed),
    name(in_name)
{
    cout << "Mage constructed." << endl;
}

void Mage::StartMoving(const Point2D& dest) {
    this->SetupDestination();
    this->state = MOVING;
}