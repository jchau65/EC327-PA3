#ifndef MODEL_H
#define MODEL_H

#include "ManaSpire.h"
#include "DemonHideout.h"
#include "Mage.h"
#include "View.h"

class Model {
    private:
        int time; // The simulation time.
        GameObject* object_ptrs[10]; // Array to store pointers to objects
        int num_objects; // Number of objects
        Mage* mage_ptrs[10]; // Array to store pointers to Mages
        int num_mages; // Number of mages
        ManaSpire* spire_ptrs[10]; // Array to store pointers to ManaSpires
        int num_spires; // Number of spires
        DemonHideout* hideout_ptrs[10]; // Array to store pointers to DemonHideouts
        int num_hideouts; // Number of hidesouts

    public:
        /**
         * Default constructor for Model.
         * 
         * Initializes the time to 0 and then creates new objects in the heap using new as follows:
         * - Mage 1 (5, 1), object_ptrs[0], mage_ptrs[0]
         * - Mage 2 (10, 1), object_ptrs[1], mage_ptrs[1]
         * - ManaSpire 1 (1, 20), object_ptrs[2], spire_ptrs[0]
         * - ManaSpire 2 (10, 20), object_ptrs[3], spire_ptrs[1]
         * - DemonHideout 1 (0, 0), object_ptrs[4], hideout_ptrs[0]
         * - DemonHideout 2 (5, 5,), object_ptrs[5], hideout_ptrs[1]
         * 
         * Also sets num_objects to 6, num_mages to 2, num_spires to 2, and num_hideouts to 2.
         * Finally, outputs a message "Model default constructed."
         */
        Model();

        /**
         * Destructor for Model.
         * 
         * Deletes each object and outputs a message "Model destructed."
         */
        ~Model();

        /**
         * Searches for a Mage of a given ID, and returns its pointer if found. Returns 0 if not.
         */
        Mage* GetMagePtr(const int id);

        /**
         * Searches for a ManaSpire of a given ID, and returns its pointer if found. Returns 0 if not.
         */
        ManaSpire* GetManaSpirePtr(const int id);

        /**
         * Searches for a DemonHideout of a given ID, and returns its pointer if found. Returns 0 if not.
         */
        DemonHideout* GetDemonHideoutPtr(const int id);

        /**
         * Updates every object in the Model.
         * 
         * If the player finishes the DemonHideouts the game should print "GAME OVER! You win!"
         * 
         * The game should then exit.
         * 
         * @return True if any one of the objects returns true.
         */
        bool Update();

        /**
         * Provides a serive to the main program. 
         * 
         * Outputs the time, and generates the view display for all of the GameObjects.
         */
        void Display(View& view);

        /**
         * Outputs the time and status of all the GameObjects by calling their ShowStatus() function.
         */
        void ShowStatus();
};

#endif