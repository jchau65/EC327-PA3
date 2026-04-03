#ifndef BUILDING_H
#define BUILDING_H

#include "GameObject.h"

/**
 * @brief
 * Base class for all building type objects in the game. Inherits from GameObject
 * and is responsible for tracking the total number of Mages that enter or leave a building.
 */
class Building : public GameObject {
    private:
        unsigned int mage_count; // Number of mages in the building

    public:
        /**
         * @brief
         * Default constructor, initializes display_code to 'B'.
         * Also outputs the message "Building default constructed".
         */
        Building();

        /**
         * @brief
         * Initializes the id number to in_id, the location to in_loc, and the display_code to in_code.
         * The remainder of the initial variables are initialized to their default values.
         * 
         * @param in_code Display code to initialize to
         * @param in_id ID number to initialize to
         * @param in_loc Point2D object to initialize to
         */
        Building(const char in_code, const int in_id, const Point2D& in_loc);

        /**
         * @brief Increments mage_count by one.
         */
        void AddOneMage();

        /**
         * @brief Decrements mage_count by one.
         */
        void RemoveOneMage();

        /**
         * @brief
         * Prints "(display_code)(id) at (location)"
         * Prints "(mage_count) mage(s) is/are in this building"
         */
        void ShowStatus();

        /**
         * @brief Returns true because buildings are always visible.
         */
        bool ShouldBeVisible();
};

#endif