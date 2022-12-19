/**
* @author Kaelan Croucher <kaelan.croucher@uleth.ca>
 * @date December 9th, 2022
 */
#ifndef NPC_H
#define NPC_H

#include <string>
#include "NPCScreenBuilder.h"


/**
 * @class NPC NPC.h "NPC.h"
 * @brief Baseclass of NPC.
 */
class NPC {
 public:
  /**
    * @brief Constructor of NPC.
    * @details Constructs basic data of npc.
    * @param[in] a String value of NPC's name.
    * @param[in] b Location of the NPC in building.
    * @param[in] c The current state which the game is on.
    */
  NPC(std::string, int, int);

  /**
    * @brief Returns string a NPC.
    * @details Returns string of NPC's name attribute.
    */
  std::string GetName();

  /**
    * @brief Enters a Conversation Interface.
    * @details Enters NPC Conversation Interface and internal loop.
    */
  virtual void ConvoOut(int i);

  /**
    * @brief Returns a bool set within the class..
    * @details Returns bool based on whether or not a
    * player has talked to the npc this turn.
    */
  virtual bool GetTalking();

  /**
    * @brief Return an int to determine players win condition.
    * @details Returns an integer based on how many
    * questions a player got correct in debugging quiz.
    */
  virtual int WinCondition() {
    return 0;
  }

  /**
    * @brief Sets bool of the NPC being in the game or not.
    * @details Assigns bool to disable or enable an npc within a game.
    * @param[in] Boolean value to set a NPCs internal attribute.
    */
  void SetDeath(bool d);

  /**
    * @brief Returns Bool based on NPC's current alive status.
    * @details Returns the Private dead bool attribute.
    */
  bool GetDeath();

  /**
    * @brief Sets talk this state bool.
    * @details Sets talked this state bool to false
    *  and increments the current state attribute.
    */
  void SetTalkedThisState();

 protected:
  /**<name for storing NPC's string*/
  std::string name;

  /**<description for storing brief Description of NPC*/
  std::string description;

  /**<entryconvo stores the opening line to conversation.*/
  std::string entryconvo;

  /**<SpecialEventFlag stores an integer value of special event.*/
  int SpecialEventFlag;

 private:
  /**<npcdialogue Stores strings for npc dialogue tree.*/
  std::string npcdialogue[4][3][3];

  /**<platerresponse stores string for
   *  players response to npc dialogue.*/
  std::string playerresponse[4][3][3];

  /**<screenbuilder Stores NPCSreenBuilder object for building menus.*/
  NPCScreenBuilder screenbuilder;

  /**<currentState int for storing which state of the game we are in
   * and what the npc should be displaying in their dialogue.*/
  int currentState = 0;

  /**<statesAlive stores the number of states an NPC will be alive.*/
  int statesAlive;

  /**<dead Bool to store whether or not a NPC is dead or alive.*/
  bool dead;

  /**<TalkedThisState bool to determine whether or not a player has
   *  talked to this NPC this state.*/
  bool TalkedThisState = false;
};
#endif  // NPC_H
