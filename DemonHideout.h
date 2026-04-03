#ifndef DEMONHIDEOUT_H
#define DEMONHIDEOUT_H

#include "Building.h"

/**
 * Enumerated object to represent when DemonHideout has been cleared or not.
 */
enum DemonHideoutStates {
    NOT_DEFEATED = 0,
    DEFEATED = 1,
};

class DemonHideout : public Building {
    private:
        unsigned int num_battle_remaining; // The amount of battles remaining in the DemonHideout
        unsigned int max_number_of_battles; // Number of battles for this Demon Hideout
        unsigned int mana_cost_per_battle; // Mana lost for a single hideout battle
        double gold_cost_per_battle; // Entry cost (in gold) for single battle
        unsigned int experience_per_battle; // Amount of experience gained from each class.

    public:
        /**
         * Default constructor that initializes the member variables to their inital values.
         * - Display Code: 'D'
         * - State: NOT_DEFEATED
         * - max_number_of_battles should be 10
         * - num_battle_remaining should be set to max_number_of_battles
         * - mana_cost_per_battle should be 1
         * - gp_cost_per_battle should be 1.0
         * - experience_per_battle should be 2
         * - Prints out the message "DemonHideout default constructed"
         */
        DemonHideout();

        /**
         * Parameter constructor for DemonHideout:
         * - Initializes the id number to in_id
         * - max_number_of_battles to max_battle
         * - mana_cost_per_battle to mana_loss
         * - experience_per_battle to exp_per_battle
         * - gold_cost_per_battle to cost 
         * - location to in_loc
         * - Iniitlizes the rest of the member variables to default values
         * - Prints out the mesage "DemonHideout constructed"
         * 
         * @param max_battle Maximum number of battles
         * @param mana_loss Mana cost per battle
         * @param cost Gold cost per battle
         * @param exp_per_battle Experience per battle
         * @param in_id Id number for this DemonHideout
         * @param in_loc Location for this DemonHideout
         */
        DemonHideout(const unsigned int max_battle, const unsigned int mana_loss, const double cost, const unsigned int exp_per_battle, const int in_id, const Point2D& in_loc);

        /**
         * @param battle_qty Specified number of battles
         * 
         * @return The gold cost of battling a specified number of times
         */
        double GetGoldCost(const unsigned int battle_qty) const;

        /**
         * @param battle_qty Specified number of battles
         * 
         * @return The mana cost of battling a specified number of times
         */
        unsigned int GetManaCost(const unsigned int battle_qty) const;

        /**
         * @return The number of battles remaining in this DemonHideout.
         */
        unsigned int GetNumBattlesRemaining() const;

        /**
         * @param battle_qty Specified number of battles
         * @param budget Specified budget left
         * @param mana Specified mana left
         * 
         * @return True if a Mage in a DemonHideout with a given budget and mana can request to take battle_qty battles. False otherwise.
         */
        bool IsAbleToBattle(const unsigned int battle_qty, const double budget, const unsigned int mana) const; 

        /**
         * Subtracts battles from num_battles_remaiing if this DemonHideout has enough units. If the amount of
         * battles requested is greater than the amount available at this DemonHideout, then num_battles_remaining
         * will be used isntead of battle_units when calculating experience gain.
         * 
         * Experience points can be calculated using (number of battles) * experience_per_battle.
         * 
         * @param battle_units
         * 
         * @return The amount of experience gained by winning the battles.
         */
        unsigned int DemonBattle(const unsigned int battle_units);

        /**
         * @return The experience gained from each battle.
         */
        unsigned int GetExperiencePerBattle() const;

        /**
         * If the DemonHideout has zero battles remaining, set the state to DEFEATED and display_code to 'd'.
         * Then print the message "(display_code)(id) has been beaten."
         * 
         * @return false if battles still remain within the DemonHideout.
         */
        bool Update();

        /**
         * @return Whether battles remaining is 0
         */
        bool passed() const;

        /**
         * Prints out the status of the object by calling GameObject's show status and then the values of its member variables:
         * - "DemonHideoutStatus: "
         * - Calls Building::ShowStatus()
         * - "Max number of battles: (max_number_of_battles)"
         * - "Mana cost per battle: (mana_cost_per_battle)"
         * - "Gold per battle: (gold_cost_per_battle)"
         * - "Experience per battle: (experience_per_battle)"
         * - "(num_battles_remaining) battle(s) are remaining for this DemonHideout"
         */
        void ShowStatus() const;
};

#endif