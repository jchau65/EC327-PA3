#ifndef MANASPIRE_H
#define MANASPIRE_H

#include "Building.h"

/**
 * Enumerated object to represent when the ManaSpire object has crystals or not.
 */
enum ManaSpireStates {
    CRYSTALS_AVAILABLE = 0,
    NO_CRYSTALS_AVAILABLE = 1,
};

/**
 * @brief 
 * A specialized Building class with a location and a set amount of magic crystals.
 * Like a Building, it also has a display_code letter and an id number. Inherits from Building.
 */
class ManaSpire : public Building {
    private:
        unsigned int crystal_capacity; // Maximum number of crystals this ManaSpire can hold
        unsigned int num_crystals_remaining; // The amount of crystals currently in this ManaSpire
        double cost_per_crystal; // Per crystal cost in the ManaSpire

    public:
        /**
         * Default constructor that initializes the member variables to this initial values:
         * - display_code should be 'S'
         * - crystal_capacity should be 100
         * - num_crystals_remaining should be set to crystal_capacity
         * - cost_per_crystal should be set to 5
         * - state should be CRYSTALS_AVAILABLE
         * - SHould print out the message "ManaSpire default constructed"
         */
        ManaSpire();

        /**
         * @brief
         * Initializes the id number to in_id, location to in_loc, cost_per_crystal to crystal_cost
         * and crystal_capacity to crystal_cap. The rest of the variables are assigned default values.
         * Also prints out the message "ManaSpire constructed". state should be CRYSTALS_AVAILABLE
         * 
         * @param in_id ID number to initialize to
         * @param crystal_cost Crystal cost to initialize to
         * @param crystal_cap Max crystal capacity to initialize to
         * @param in_loc Location to initialize to
         */
        ManaSpire(const int in_id, const double crystal_cost, const unsigned int crystal_cap, const Point2D& in_loc);

        /**
         * @return Whether the ManaSpire has crystals or not
         */
        bool HasCrystals();

        /**
         * @return The number of crystals remaining in this ManaSpire.
         */
        unsigned int GetNumCrystalsRemaining();

        /**
         * @param crystal Number of crystals to be purchased
         * @param budget Budget able to be used to purchase crystal
         * 
         * @return True if this Mage can afford to purchase crystal with the given budget. Otherwise, false.
         */
        bool CanAffordCrystal(const unsigned int crystal, const double budget);

        /**
         * @param crystal Number of crystals specified
         * 
         * @return The cost (in gold pieces) for the specified number of crystals.
         */
        double GetCrystalCost(const unsigned int crystal);

        /**
         * @brief 
         * If the amount num_crystals_remaining in the ManaSpire is greater than or equal to crystals_needed,
         * it subtracts crystals_needed from ManaSpire amount and returns crystals_needed. If the amount of 
         * crystals in the ManaSpire is less, it returns the ManaSpire current amount, and the ManaSpire 
         * crystal amount is set to 0.
         * 
         * @param crystals_needed Number of crystals needed/specified
         * 
         * @return Number of crystals distributed
         */
        unsigned int DistributeCrystals(const unsigned int crystals_needed);

        /**
         * @brief
         * If the ManaSpire has no crystals remaining, state is set to NO_CRYSTALS_AVAILABLE, display_code
         * is set to 's', prints the message "ManaSpire (id_number) has run out of crystals, " and returns
         * true if crystal is depleted, false otherwise. This function shouldn't keep returning true if 
         * the ManaSpire has no crystal remaining. It should return true ONLY at the time when the ManaSpire
         * runs out of crystal, and return false for later Update() function calls.
         */
        bool Update();

        /**
         * Prints out the status of the object:
         * - "ManaSpire Status: "
         * - Calls Building::ShowStatus()
         * - "Gold pieces per crystal: (cost_per_crystal)"
         * - "has (crystal_remaining) crystal(s) remaining"
         */
        void ShowStatus();
};

#endif