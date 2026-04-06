#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H

#include "Model.h"

/**
 * If the command arguments are valid prints "Moving (mage name) to p1"
 * 
 * Otherwise prints "Error: please enter a valid command!"
 */
void DoMoveCommand(Model& model, const int mage_id, Point2D& p1);

/**
 * If the command arguments are valid prints "Moving (mage name) to Mana Spire (spire_id)"
 * 
 * Otherwise prints "Error: please enter a valid command!"
 */
void DoMoveToSpireCommand(Model& model, const int mage_id, const int spire_id);

/**
 * If the command arguments are valid prints "Moving (mage name) to Demon Hideout (hideout_id)"
 * 
 * Otherwise prints "Error: please enter a valid command!"
 */
void DoMoveToHideoutCommand(Model& model, const int mage_id, const int hideout_id);

/**
 * If the command arguments are valid prints "Stopping (mage name)"
 * 
 * Otherwise prints "Error: please enter a valid command!"
 */
void DoStopCommand(Model& model, const int mage_id);

/**
 * If the command arguments are valid prints "(mage name) is battling"
 * 
 * Otherwise prints "Error: please enter a valid command!"
 */
void DoBattleCommand(Model& model, const int mage_id, const unsigned int battles);

/**
 * If the command arguments are valid prints "Recovering (mage name)'s mana"
 * 
 * Otherwise prints "Error: please enter a valid command!"
 */
void DoRecoverInSpireCommand(Model& model, const int mage_id, const unsigned int crystals_needed);

/**
 * Prints "Advancing one tick"
 */
void DoAdvanceCommand(Model& model, View& view);

/**
 * Prints "Advancing to next event"
 */
void DoRunCommand(Model& model, View& view);

/**
 * Handles all of the input commands by the user.
 */
void HandleCommand(Model& model, View& view, const char command);

#endif
