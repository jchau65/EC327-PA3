#include <iostream>

#include "DemonHideout.h"

using namespace std;

DemonHideout::DemonHideout() :
    Building(),
    max_number_of_battles(10),
    num_battle_remaining(10),
    mana_cost_per_battle(1),
    gold_cost_per_battle(1.0),
    experience_per_battle(2)
{
    this->state = NOT_DEFEATED;
    this->display_code = 'D';

    cout << "DemonHideout default constructed" << endl;
}

DemonHideout::DemonHideout (const unsigned int max_battle, const unsigned int mana_loss, const double cost, const unsigned int exp_per_battle, const int in_id, const Point2D& in_loc) : 
    Building('D', in_id, in_loc),
    max_number_of_battles(max_battle),
    num_battle_remaining(max_battle),
    mana_cost_per_battle(mana_loss),
    experience_per_battle(exp_per_battle),
    gold_cost_per_battle(cost)
{
    this->state = NOT_DEFEATED;
    cout << "DemonHideout constructed" << endl;
}

double DemonHideout::GetGoldCost(const unsigned int battle_qty) const {
    return battle_qty * gold_cost_per_battle;
}

unsigned int DemonHideout::GetManaCost(const unsigned int battle_qty) const {
    return battle_qty * mana_cost_per_battle;
}

unsigned int DemonHideout::GetNumBattlesRemaining() const {
    return num_battle_remaining;
}

bool DemonHideout::IsAbleToBattle(const unsigned int battle_qty, double budget, unsigned int mana) const {
    // Check if a Mage has sufficient gold and mana to battle
    if (GetGoldCost(battle_qty) <= budget && GetManaCost(battle_qty) <= mana) {
        return true;
    }
    return false;
}

unsigned int DemonHideout::DemonBattle(const unsigned int battle_units) {
    // If this DemonHideout has sufficient battles, return experience gained from battle_units battles
    if (battle_units <= num_battle_remaining) {
        num_battle_remaining -= battle_units;
        return experience_per_battle * battle_units;
    }

    // Else, return experience gained from num_battle_remaining battles
    else {
        unsigned int exp_gain = num_battle_remaining * experience_per_battle;
        num_battle_remaining = 0;
        return exp_gain;
    }
}

unsigned int DemonHideout::GetExperiencePerBattle() const {
    return experience_per_battle;
}

bool DemonHideout::Update() {
    // Checks the first time that the DemonHideout is defeated
    if (num_battle_remaining == 0 && this->state == NOT_DEFEATED) {
        this->display_code = 'd';
        cout << this->display_code << id_num << " has been beaten" << endl;
        this->state = DEFEATED;
        return true;
    }
    return false;
}

bool DemonHideout::passed() const {
    if (num_battle_remaining == 0) {
        return true;
    }
    return false;
}

void DemonHideout::ShowStatus() const {
    cout << "DemonHideout Status: " << endl;
    Building::ShowStatus();
    cout << "Max number of battles: " << max_number_of_battles << endl;
    cout << "Mana cost per battle: " << mana_cost_per_battle << endl;
    cout << "Gold per battle: " << gold_cost_per_battle << endl;
    cout << "Experience per battle: " << experience_per_battle << endl;
    cout << num_battle_remaining << " battle(s) are remaining for this DemonHideout" << endl;
}