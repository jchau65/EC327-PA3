#include <iostream>

#include "ManaSpire.h"

using namespace std;

ManaSpire::ManaSpire() : 
    Building(), 
    crystal_capacity(100), 
    num_crystals_remaining(crystal_capacity), 
    cost_per_crystal(5) 
{
    this->display_code = 'S';
    this->state = CRYSTALS_AVAILABLE;

    cout << "ManaSpire default constructed" << endl; 
}

ManaSpire::ManaSpire(const int in_id, const double crystal_cost, const unsigned int crystal_cap, const Point2D& in_loc) :
    Building('S', in_id, in_loc), 
    crystal_capacity(crystal_cap), 
    num_crystals_remaining(crystal_capacity), 
    cost_per_crystal(crystal_cost) 
{
    this->state = CRYSTALS_AVAILABLE;
    cout << "ManaSpire constructed" << endl;
}

bool ManaSpire::HasCrystals() const {
    // Returns true if there is at least one crystal remaining
    if (this->num_crystals_remaining >= 1) {
        return true;
    }
    return false;
}

unsigned int ManaSpire::GetNumCrystalsRemaining() const {
    return num_crystals_remaining;
}

bool ManaSpire::CanAffordCrystal(unsigned int crystal, double budget) const {
    // Returns true if the given budget can afford to buy specified number of crystals
    if (budget >= GetCrystalCost(crystal)) {
        return true;
    }
    return false;
}

double ManaSpire::GetCrystalCost(unsigned int crystal) const {
    return crystal * cost_per_crystal;
}

unsigned int ManaSpire::DistributeCrystals(unsigned int crystals_needed) {
    // Returns true if there is sufficient crystal, then distributes it
    if (num_crystals_remaining >= crystals_needed) {
        num_crystals_remaining -= crystals_needed;
        return crystals_needed;
    }

    // Returns false if there is not sufficient crystal, and distributes as much as possible
    else {
        unsigned int temp = num_crystals_remaining;
        num_crystals_remaining = 0;
        return temp;
    }
}

bool ManaSpire::Update() {
    // Sets display code to 's' if there are no crystals, and prints a message
    if (!HasCrystals() && state != NO_CRYSTALS_AVAILABLE) {
        this->display_code = 's';
        cout << "ManaSpire " << this->id_num << " has ran out of crystals." << endl;
        state = NO_CRYSTALS_AVAILABLE;
        return true;
    }

    return false;
}

void ManaSpire::ShowStatus() const {
    cout << "ManaSpire Status: " << endl; 
    Building::ShowStatus();
    cout << "Gold pieces per crystal: " << cost_per_crystal << endl;
    cout << "Has " << num_crystals_remaining << " crystal(s) remaining." << endl;
}

ManaSpire::~ManaSpire() {
    cout << "ManaSpire destructed." << endl;
}