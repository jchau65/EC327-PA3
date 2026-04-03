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
    // Calls the SetupDestination() function (make the next step)
    SetupDestination(dest);

    // Sets the state to MOVING
    this->state = MOVING;

    // If this Mage already at the destination run this bit
    Point2D currentLocation = GetLocation();
    if (currentLocation.x == dest.x && currentLocation.y == dest.y) {
        cout << display_code << id_num << ": I'm already there. See?" << endl;
    }

    // If this Mage is knocked out run this bit
    else if (IsKnockedOut()) {
        cout << display_code << id_num << ": I am knocked out. I may move but you cannot see me." << endl;
    }

    // Otherwise
    else {
        cout << display_code << id_num << ": On my way." << endl;
    }
}

void Mage::StartMovingToHideout(const DemonHideout* hideout) {
    // Create a new variable for destination
    Point2D dest = hideout->GetLocation();

    // Calls the SetupDestination() function with hideout's location (make the next step)
    SetupDestination(dest);

    // Sets the state to MOVING_TO_HIDEOUT
    this->state = MOVING_TO_HIDEOUT;

    // If this Mage is knocked out run this bit
    if (IsKnockedOut()) {
        cout << display_code << id_num << ": I am knocked out so I can't move to hideout..." << endl;
    }
    
    // If this Mage is already at destination run this bit
    else if (GetLocation().x == dest.x && GetLocation().y == dest.y) {
        cout << display_code << id_num << ": I am already at the Demon Hideout!" << endl;
    }

    // Otherwise
    else {
        cout << display_code << id_num << ": on my way to hideout " << hideout->GetId() << endl;
    }
}

void Mage::StartMovingToSpire(const ManaSpire* spire) {
    // Create a new variable for destination point
    Point2D dest = spire->GetLocation();

    // Calls the SetupDestination() function with spire's location (make the next step)
    SetupDestination(dest);

    // Sets the state to MOVING_TO_SPIRE
    this->state = MOVING_TO_SPIRE;

    // If this Mage has lost all mana run this bit
    if (IsKnockedOut()) {
        cout << display_code << id_num << ": I am knocked out so I should have gone to the spire..." << endl;
    }

    // If the Mage is already there, run this bit
    else if (GetLocation().x == dest.x && GetLocation().y == dest.y) {
        cout << display_code << id_num << ": I am already at the Spire!" << endl;
    }

    // Otherwise, general case
    else {
        cout << display_code << id_num << ": On my way to Spire " << spire->GetId() << endl;
    }
}

void Mage::StartBattling(const unsigned int num_battles) {
    // if Mage is out of mana
    if (IsKnockedOut()) {
        cout << display_code << id_num << ": I'm knocked out and out of mana so no more battles for me..." << endl;
    }

    // If Mage is not in a hideout
    else if (this->state != IN_HIDEOUT) {
        cout << display_code << id_num << ": I can only battle in a Demon Hideout!" << endl;
    }

    // If Mage cannot afford battle
    else if (current_hideout->GetGoldCost(num_battles) > gold_pieces) {
        cout << display_code << id_num << ": Not enough money for battles" << endl;
    }

    // If the currrent hideout is done
    else if (current_hideout->GetNumBattlesRemaining() == 0) {
        cout << display_code << id_num << ": Cannot battle! This Demon Hideout has no more mages to battle!" << endl;
    }

    // Otherwise, general case
    else {
        cout << display_code << id_num << ": Started to battle at the Demon Hideout " << current_hideout->GetId() << "with " << num_battles << " battles" << endl;
        if (num_battles > current_hideout->GetNumBattlesRemaining()) {
            current_hideout->DemonBattle(num_battles);
        }
        else {
            current_hideout->DemonBattle(current_hideout->GetNumBattlesRemaining());
        }
    }

    // Sets the state to BATTLING_IN_HIDEOUT
    this->state = BATTLING_IN_HIDEOUT;
}