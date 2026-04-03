#include <iostream>

#include "Building.h"

using namespace std;

Building::Building() : GameObject('B'), mage_count(0) {
    cout << "Building default constructed" << endl;
}

Building::Building(const char in_code, const int in_id, const Point2D& in_loc) : GameObject(in_loc, in_id, in_code), mage_count(0) {
    cout << "Building constructed" << endl;
}

void Building::AddOneMage() {
    mage_count++;
}

void Building::RemoveOneMage() {
    mage_count--;
}

void Building::ShowStatus() {
    GameObject::ShowStatus(); // Print out "(display_code)(id) located at (location)"

    // Conditionally select verbs is/are based on number of mages
    if (mage_count == 1) {
        cout << mage_count << " mage(s) is in this building" << endl;
    }
    else {
        cout << mage_count << " mage(s) are in this building" << endl;
    }
}

bool Building::ShouldBeVisible() {
    return true;
}