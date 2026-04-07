#include <iostream>

#include "Model.h"
#include "View.h"

using namespace std;

Model::Model() : time(0), num_objects(6), num_mages(2), num_spires(2), num_hideouts(2) {
    // Create new mages
    Mage* m1 = new Mage("Serena", 1, 'M', 1, Point2D(5, 1));
    Mage* m2 = new Mage("Rumi", 2, 'M', 2, Point2D(10, 1));

    // Put the mages in object_ptrs
    object_ptrs[0] = m1;
    object_ptrs[1] = m2;

    // Put the mages in mage_ptrs
    mage_ptrs[0] = m1;
    mage_ptrs[1] = m2;

    // Create new ManaSpires
    ManaSpire* s1 = new ManaSpire(1, 1, 100, Point2D(1, 20));
    ManaSpire* s2 = new ManaSpire(2, 2, 200, Point2D(10, 20));

    // Put the ManaSpires in object_ptrs
    object_ptrs[2] = s1;
    object_ptrs[3] = s2;

    // Put the ManaSpires in spire_ptrs
    spire_ptrs[0] = s1;
    spire_ptrs[1] = s2;

    // Create new DemonHideouts
    DemonHideout* d1 = new DemonHideout(10, 1, 2, 3, 1, Point2D(0, 0));
    DemonHideout* d2 = new DemonHideout(20, 5, 7.5, 4, 2, Point2D(5, 5));

    // Put the DemonHideouts in object_ptrs
    object_ptrs[4] = d1;
    object_ptrs[5] = d2;

    // Put the DemonHideouts in hideout_ptrs
    hideout_ptrs[0] = d1;
    hideout_ptrs[1] = d2;

    // Print output
    cout << "Model default constructed" << endl;
}

Mage* Model::GetMagePtr(const int id) {
    // Search for a Mage with the correct id
    for (int i = 0; i < num_mages; i++) {
        if (mage_ptrs[i]->GetId() == id) {
            return mage_ptrs[i];
        }
    }

    return 0;
}

ManaSpire* Model::GetManaSpirePtr(const int id) {
    // Search for a ManaSpire with the correct id
    for (int i = 0; i < num_spires; i++) {
        if (spire_ptrs[i]->GetId() == id) {
            return spire_ptrs[i];
        }
    }

    return 0;
}

DemonHideout* Model::GetDemonHideoutPtr(const int id) {
    // Search for a DemonHideout with the correct id
    for (int i = 0; i < num_hideouts; i++) {
        if (hideout_ptrs[i]->GetId() == id) {
            return hideout_ptrs[i];
        }
    }

    return 0;
}

bool Model::Update() {
    // Increment the time
    time++;

    // bool storage variables
    bool returnedTrue = false;
    bool gameOverHideouts = true;
    bool gameOverMages = true;

    // Iterate through the object_ptrs array and call their update function
    for (int i = 0; i < num_objects; i++) {
        if (object_ptrs[i]->Update()) {
            returnedTrue = true;
        }
    }

    // Checks for game over
    for (int i = 0; i < num_hideouts; i++) {
        if (!hideout_ptrs[i]->passed()) {
            gameOverHideouts = false;
        }
    }

    // Print game over loss condition
    if (gameOverHideouts) {
        cout << "GAME OVER! You win! All battles done!" << endl;
        exit(0);
    }

    // Checks for mages knocked out
    for (int i = 0; i < num_mages; i++) {
        if (!mage_ptrs[i]->IsKnockedOut()) {
            gameOverMages = false;
        }
    }

    // Print game over win condition
    if (gameOverMages) {
        cout << "GAME OVER: You lose! All of your Mages' mana is lost!" << endl;
        exit(0);
    }

    return returnedTrue;
}

void Model::Display(View& view) {
    // Clear view first
    view.Clear();

    // Draw every object
    for (int i = 0; i < num_objects; i++) {
        view.Plot(object_ptrs[i]);
    }

    // Display
    view.Draw();
}

void Model::ShowStatus() {
    // Output the time
    cout << "Time: " << time << endl;

    // Call ShowStatus functions of every object
    for (int i = 0; i < num_objects; i++) {
        object_ptrs[i]->ShowStatus();
    }
}