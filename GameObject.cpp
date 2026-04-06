#include <iostream>

#include "Point2D.h"
#include "GameObject.h"

GameObject::GameObject(const char in_code) : location(Point2D()), display_code(in_code), id_num(1), state(0) {
    cout << "GameObject constructed" << endl; // Default constructor
}

GameObject::GameObject(const Point2D& in_loc, const int in_id, const char in_code) : location(in_loc), id_num(in_id), display_code(in_code), state(0) {
    cout << "GameObject constructed" << endl; // Parameterized constructor
}

Point2D GameObject::GetLocation() const {
    return location;
}

int GameObject::GetId() const {
    return id_num;
}

char GameObject::GetState() const {
    return state;
}

void GameObject::ShowStatus() const {
    cout << display_code << id_num << " at " << location << endl;
}

GameObject::~GameObject() {
    cout << "GameObject destructed" << endl;
}