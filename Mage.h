#ifndef MAGE_H
#define MAGE_H

#include <string>

#include "GameObject.h"
#include "ManaSpire.h"
#include "DemonHideout.h"

using namespace std;

/// Enumerated object for all the states for a mage.
enum MageStates {
    STOPPED = 0,
    MOVING = 1,
    KNOCKED_OUT = 2,
    AT_SPIRE = 3,
    IN_HIDEOUT = 4,
    MOVING_TO_SPIRE = 5,
    MOVING_TO_HIDEOUT = 6,
    BATTLING_IN_HIDEOUT = 7,
    RECOVERING_MANA = 8,
};

class Mage : public GameObject {
    private:
        double speed; // The speed this object travels, expressed as distance per update time unit.
        bool is_at_spire; // Set to true if the Mage is in a ManaSpire
        bool is_in_hideout; // Set to true if this Mage is in a DemonHideout
        unsigned int mana; // Amount of mana a Mage has
        unsigned int experience; // The amount of experience points this Mage has
        double gold_pieces; // The total amount of gold pieces this Mage holds.
        unsigned int battles_to_buy; // Stores the number of battles to buy when in a DemonHideout
        unsigned int crystals_to_buy; // Sroes the number of crystals to buy when in a ManaSpire
        string name; // The name of this Mage
        ManaSpire* current_spire; // A pointer to the current ManaSpire
        DemonHideout* current_hideout; // A pointer to the current DemonHideout
        Point2D destination; // This object's current destination coordinates in the real plane.
        Vector2D delta; // Contains the x and y amounts that the object will move on each time unit.

    public:
        /**
         * Default constructor for a Mage object:
         * - Initializes the speed to 5 
         * - Outputs "Mage default constructed"
         * - display_code should be initialized to 'M'
         */
        Mage();

        /**
         * Parameterized constructor for a Mage object.
         * - Initializes the speed to 5
         * - Outputs a message "Mage constructed"
         * - state: STOPPED
         * - display_code: in_code
         * 
         * @param in_code Display code to be initialized.
         */
        Mage(const char in_code);

        /// @brief Parameterized constructor for the Mage object.
        /// @param in_name Name of the Mage
        /// @param in_id Id of the Mage
        /// @param in_code Display code of the Mage
        /// @param in_speed Speed of the Mage
        /// @param in_loc Location of the Mage
        Mage(const string in_name, const int in_id, const char in_code, const unsigned int in_speed, const Point2D& in_loc);

        /**
         * Tells the mage to start moving. Calls the setup_desination() function. Sets the state to MOVING.
         * - If this Mage is already at the destination print "(display_code)(id): I'm already there."
         * - If this Mage is knocked out print "(display_code)(id): I am knocked out. I may move but you cannot see me."
         * - Otherwise prints "(display_code)(id): On my way."
         */
        void StartMoving(const Point2D& dest);

        /**
         * Tells the Mage to start moving to a DemonHideout.
         * - Calls the SetUpDestination() function with DemonHideout's location as the destination.
         * - Sets the state to MOVING_TO_HIDEOUT
         * - If this Mage is knocked out print "(display_code)(id): I am knocked out so I can't move to hideout..."
         * - Prints the message "(display_code)(id): On my way to hideout (hideout id)."
         * - If this Mage is already there print "(display_code)(id): I am already at the Demon Hideout!"
         */
        void StartMovingToHideout(DemonHideout* hideout);

        /**
         * - Tells the Mage to start moving to a ManaSpire.
         * - Calls the SetupDestination() function with ManaSpire's location as the destination.
         * - Sets the state to MOVING_TO_SPIRE
         * - If this Mage has lost all mana print "(display_code)(id): I am knocked out so I should have gone to the spire.."
         * - Prints the message "(display_code)(id): On my way to Spire (spire id)"
         * - If Mage is already there print "(display_code)(id): I am already at the Spire!"
         */
        void StartMovingToSpire(ManaSpire* spire);

        /**
         * Tells the Mage to start battling (num_battles) in a DemonHideout.
         * Sets the state to BATTLING_IN_HIDEOUT and prints the message "(display_code): Started to battle at the DemonHideout (hideout id)
         * with (number of battles) battles" unless the following conditions are true:
         * - This Mage is out of mana print "(display_code)(id): I'm knocked out and out of mana so no more battles for me..."
         * - This Mage is not in a DemonHideout print "(display_code)(id): I can only battle in a DemonHideout!"
         * This Mage does not have enough gold pieces print "(display_code)(id): Not enough money for battles!"
         * If this Mage can start training, set its num_battles to the requested battles and update the remaining battles in the hideout.
         * If a Mage requests more battles than are available, they should get the available amount.
         */
        void StartBattling(const unsigned int num_battles);

        /**
         * Tells the Mages to start reocvering at a ManaSpire.
         * Sets the state to RECOVERING_MANA and prints the message "(display_code)(id): Started recoving (num_crystals) crystals at Mana Spire (current_spire_id)" unless the following conditions are true:
         * - This Mage does not have enough gold pieces print "(display_code)(id): Not enough money to recover mana."
         * - This ManaSpire does not have at least one crystal remaining otherwise print "(display_code)(id): Cannot recover! No crystal remaining in this Mana Spire"
         * - This Mage is not in a Mana Spire otherwise print "(display_code)(id): I can only recover mana at a Mana Spire!"
         * - If a Mage requests more crystals than are available, they should get the available amount.
         * If this Mage can start recovering mana, set its crystals_to_buy to the minimum of the requested crystals and update the remaining crystals in the spire.
         * Five mana is recovered for each crystal purchased
         */
        void StartRecoveringMana(const unsigned int num_crystals);

        /**
         * Tells this Mage to stop doing whatever it was doing.
         * Sets the state to STOPPED.
         * Prints "(display_code)(id): Stopping..."
         */
        void Stop();

        /**
         * @return True if mana is 0
         */
        bool IsKnockedOut() const;

        /**
         * @return True if this mage is not knocked out
         */
        bool ShouldBeVisible() const override;

        /**
         * Prints "(name) status: "
         * Call GameObject::ShowStatus()
         * Print state specific status information. 
         * 
         * - STOPPED - "Stopped"
         * - MOVING - "Moving at a speed of (speed) to destination <X, Y> at each step of (delta)"
         * - MOVING_TO_HIDEOUT - "Heading to DemonHideout (current_hideout id) at a speed of (speed) at each step of (delta)"
         * - MOVING_TO_SPIRE - "Heading to Mana Spire (current_spire id) at a speed of (speed) at each step of (delta)"
         * - IN_HIDEOUT - "Inside Demon Hideout (current_hideout id)"
         * - AT_SPIRE - "Inside Mana Spire (current_Spire id)"
         * - BATTLING_IN_HIDEOUT - "Battling in DemonHideout (current_hideout id)"
         * - RECOVERING_MANA - "Recovering mana in Mana Spire (current_spire id)"
         */
        void ShowStatus() const override;

        /**
         * If the object is moving, this calls the UpdateLocation() function.
         * 
         * This function first checks to see if the object is within one step of its destination 
         * (if the absolute value of both the x and y components of fabs(destination - location) are less than or equal
         * to the x and y components of delta). If it is, UpdateLocation() sets the object's lcoation to the destination,
         * prints an "arrived" message, and then returns true to indicate that the object arrived.
         * 
         * If the object is not within a step of destination, UpdateLocation() adds the delta to the location, prints a "moved"
         * message, and returns false to indicate that the object has not yet arrived.
         * 
         * Thus, the object will take a "speed-sized" step on each update "tick" until it gets within one step of the destination,
         * and then on the last step, goes exactly to the destination.
         * 
         * For each state:
         * - STOPPED - return false
         * - MOVING - Call UpdateLocation() to take a step, if the object has arrived, set the state to STOPPED and return true, otherwise stay in MOVING state
         * - MOVING_TO_HIDEOUT - Call UpdateLocation(), if it has arrived, set the state to IN_HIDEOUT, and return true, otherwise stay in MOVING state
         * - MOVING_TO_SPIRE - Call UpdateLocation(), if it has arrived, set the state to AT_SPIRE and return true, otherwise stay in current state
         * - IN_HIDEOUT - return false
         * - AT_SPIRE - return false
         * - BATTLING_IN_HIDEOUT - reduce Mana, gold pieces, increase Mage exp, print "** (name) completed (battles_to_buy) battle(s)! **" and "** (name) gained (experience gained) experience! **", set state to IN_HIDEOUT and return true
         * - RECOVERING_MANA - increase Mana, reduce gold pieces, prints "** (name) recovered (mana recovered) mana! **" and "** (name) bought (crystals_received) crystal(s)! **", set state to AT_SPIRE and return true
         */
        bool Update() override;

        /**
         * Getter function for the Mage's name.
         */
        string GetName();

        /**
         * Destructor for Mage. Outputs the message "Mage destructed."
         */
        virtual ~Mage();

    protected:
        /**
         * Updates the object's location while it is moving.
         * 
         * If the object is within a step of its destination, UpdateLocation() sets the object's lcoation to the destination,
         * prints an "arrived" message, and then returns true to indicate that the object arrived.
         * 
         * If the object is not within a step of destination, UpdateLocation() adds the delta to the location, prints a "moved"
         * message, and returns false to indicate that the object has not yet arrived.
         * 
         * Thus, the object will take a "speed-sized" step on each update "tick" until it gets within one step of the destination,
         * and then on the last step, goes exactly to the destination.
         * 
         * Prints "(display_code)(id): I'm there!" if a Mage has arrived at its destination.
         * Prints "(display_code)(id): step..." otherwise.
         */
        bool UpdateLocation();

        /**
         * Sets up the object to start moving to dest.
         * 
         * Saves the destination and calculates the delta value.
         * 
         * delta = (destination - location) * (speed / GetDistanceBetween(destination, location))
         */
        void SetupDestination(const Point2D& dest);
};

/**
 * @return A random number between 0.0 and 2.0 inclusive.
 */
double GetRandomAmountOfGP();

#endif