#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Point2D.h"

/**
 * @brief
 * This class is the base class for all the objects in the game. It is 
 * responsible for the member variables and functions that they all have
 * in common.
 */
class GameObject {
    protected:
        Point2D location; // Location of the object
        int id_num; // ID number of the object
        char display_code; // Display code of the object
        char state; // State of the object

    public:
        /**
         * @brief
         * Creates a new GameObject with specified display code, id_num of 1, and state of 0.
         * Outputs the message: "GameObject constructed". 
         * 
         * @param in_code Display code to be initialized
         */
        GameObject(const char in_code);

        /**
         * @brief
         * Creates a new GameObject with specified location, id number, and display code.
         * The state is defaulted to 0. Outputs the message: "GameObject constructed".
         * 
         * @param in_loc Location to be initialized
         * @param in_id ID number to be initialized
         * @param in_code Display code to be initialized
         */
        GameObject(const Point2D& in_loc, const int in_id, const char in_code);

        /**
         * @brief Returns the location for this object.
         * 
         * @return Point2D object representing the location of this object
         */
        Point2D GetLocation();

        /**
         * @brief Returns the ID number for this object.
         * 
         * @return ID number
         */
        int GetId();

        /**
         * @brief Returns the state for this object.
         * 
         * @return Int representing the state of this object.
         */
        char GetState();

        /**
         * @brief
         * Outputs the information contained in this class: display_code, id_num, location, 
         * in the format "{display_code}{id_num} at {location}".
         */
        void ShowStatus();
};

#endif