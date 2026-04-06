#include <iostream>

#include "GameCommand.h"

using namespace std;

void DoMoveCommand(Model& model, const int mage_id, Point2D& p1) {
    // Get the mage ptr
    Mage* mage = model.GetMagePtr(mage_id);

    // Check if mage exists
    if (mage != 0) {
        mage->StartMoving(p1);
        cout << "Moving " << mage->GetName() << " to " << p1 << endl;
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
        mage->StartMovingToSpire(spire);
        cout << "Moving " << mage->GetName() << " to Mana Spire " << spire->GetId() << endl;
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
        mage->StartMovingToHideout(hideout);
        cout << "Moving " << mage->GetName() << " to Demon Hideout " << hideout->GetId() << endl;
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
        mage->Stop();
        cout << "Stopping " << mage->GetName() << endl;
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
        mage->StartBattling(battles);
        cout << mage->GetName() << " is battling" << endl;
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
        mage->StartRecoveringMana(crystals_needed);
        cout << "Recovering " << mage->GetName() << "'s mana" << endl;
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
    int arg1;
    int arg2;
    int arg3;

    switch (command) {
        case 'm':
            // Set arguments
            cin >> arg1 >> arg2 >> arg3;    
            DoMoveCommand(model, arg1, Point2D(arg2, arg3));
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
            // TBA
    }
}