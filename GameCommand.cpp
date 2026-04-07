#include <iostream>

#include "GameCommand.h"

using namespace std;

extern bool quit = false;

void DoMoveCommand(Model& model, const int mage_id, Point2D& p1) {
    // Get the mage ptr
    Mage* mage = model.GetMagePtr(mage_id);

    // Check if mage exists
    if (mage != 0) {
        cout << "Moving " << mage->GetName() << " to " << p1 << endl;
        mage->StartMoving(p1);
    }

    // If mage doesn't exist
    else {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoMoveToSpireCommand(Model& model, const int mage_id, const int spire_id) {
    // Get the mage ptr
    Mage* mage = model.GetMagePtr(mage_id);

    // Get the ManaSpire ptr
    ManaSpire* spire = model.GetManaSpirePtr(spire_id);

    // Check if mage and spire exist
    if (mage != 0 && spire != 0) {
        cout << "Moving " << mage->GetName() << " to Mana Spire " << spire->GetId() << endl;
        mage->StartMovingToSpire(spire);
    }

    // If mage or spire doesn't exist
    else {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoMoveToHideoutCommand(Model& model, const int mage_id, const int hideout_id) {
    // Get the mage ptr
    Mage* mage = model.GetMagePtr(mage_id);

    // Get the DemonHideout ptr
    DemonHideout* hideout = model.GetDemonHideoutPtr(hideout_id);

    // Check if mage and hideout exist
    if (mage != 0 && hideout != 0) {
        cout << "Moving " << mage->GetName() << " to Demon Hideout " << hideout->GetId() << endl;
        mage->StartMovingToHideout(hideout);
    }

    // If mage or hideout doesn't exist
    else {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoStopCommand(Model& model, const int mage_id) {
    // Get the mage ptr
    Mage* mage = model.GetMagePtr(mage_id);

    // Check if mage exists
    if (mage != 0) {
        cout << "Stopping " << mage->GetName() << endl;
        mage->Stop();
    }

    // If mage doesn't exist
    else {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoBattleCommand(Model& model, const int mage_id, const unsigned int battles) {
    // Get the mage ptr
    Mage* mage = model.GetMagePtr(mage_id);

    // Check if mage exists and if they are in a hideout
    if (mage != 0 && mage->GetState() == IN_HIDEOUT) {
        cout << mage->GetName() << " is battling" << endl;
        mage->StartBattling(battles);
    }

    // If mage doesn't exist or they are not in a hideout
    else {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoRecoverInSpireCommand(Model& model, const int mage_id, const unsigned int crystals_needed) {
    // Get the mage ptr
    Mage* mage = model.GetMagePtr(mage_id);

    // Check if mage exists and if they are in a spire
    if (mage != 0 && mage->GetState() == AT_SPIRE) {
        cout << "Recovering " << mage->GetName() << "'s mana" << endl;
        mage->StartRecoveringMana(crystals_needed);
    }

    // If mage doesn't exist or they are not at a spire
    else {
        cout << "Error: Please enter a valid command!" << endl;
    }
}

void DoAdvanceCommand(Model& model, View& view) {
    cout << "Advancing one tick" << endl;

    // Run update
    model.Update();
}

void DoRunCommand(Model& model, View& view) {
    cout << "Advancing to next event" << endl;

    // Runs until 5 ticks, or until next event
    for (int i = 0; i < 5; i++) {
        if (model.Update()) {
            break;
        }
    }
}

void HandleCommand(Model& model, View& view, const char command) {
    // variables for IDs, x and y coordinates, etc. Max of 3 arguments per command
    double arg1;
    double arg2;
    double arg3;

    // variable to store Point2D
    Point2D point;

    switch (command) {
        case 'm':
            // Set arguments
            cin >> arg1 >> arg2 >> arg3;    
            point = Point2D(arg2, arg3);
            DoMoveCommand(model, arg1, point);
            break;
        case 's':
            // Set arguments
            cin >> arg1 >> arg2;
            DoMoveToSpireCommand(model, arg1, arg2);
            break;
        case 'd':
            // Set arguments
            cin >> arg1 >> arg2;
            DoMoveToHideoutCommand(model, arg1, arg2);
            break;
        case 'h':
            // Set arguments
            cin >> arg1;
            DoStopCommand(model, arg1);
            break;
        case 'c':
            // Set arguments
            cin >> arg1 >> arg2;
            DoRecoverInSpireCommand(model, arg1, arg2);
            break;
        case 'b':
            // Set arguments
            cin >> arg1 >> arg2;
            DoBattleCommand(model, arg1, arg2);
            break;
        case 'a':
            DoAdvanceCommand(model, view);
            break;
        case 'r':
            DoRunCommand(model, view);
            break;
        case 'q':
            exit(0);
            break;
    }
}