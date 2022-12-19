/**
* @author Kaelan Croucher <kaelan.croucher@uleth.ca>
 * @date December 9th, 2022
 */
#ifndef NPCROOM_H
#define NPCROOM_H
#include <string>
#include "NPC.h"
#include "Rooms.h"


/**
 * @class NPCRoom NPCRoom.h "NPCRoom.h"
 * @brief Subclass of rooms for rooms with NPCs.
 * @details Constructor Constructs the room based on a
 * the room factory specifications.
 */
class NPCRoom : public Rooms {
  NPC *npc;

 public:
  NPCRoom(int RoomType, std::string a, std::string b, std::string c,
          std::string d, bool e, std::string f)
      :
      Rooms(RoomType, a, b, c, d, e, f) {
  }

/**
  * @brief Assigns pointer a value.
  * @details Assigns pointer a value of passed through npc.
  * @param[in] a MPC* pointer that is passed through.
  */
  void AddNPC(NPC *a) {
    npc = a;
  }

 /**
   * @brief Returns string attribute of NPC
   * @details Returns string of NPC's name.
   */
  std::string NPCName() {
    return npc->GetName();
  }

/**
  * @brief Generic pass through function.
  * @details Generic pass through function used to
  * access the conversation menu in NPC.
  */
  void RoomAction() {
    npc->ConvoOut(1);
  }

/**
  * @brief Deconstructor of NPCRoom.
  * @details Deletes npc pointer allocated to room.
  */
  ~NPCRoom() {
    delete npc;
  }

/**
  * @brief Generic pass through function.
  * @details Accesses the get talking bool function of NPC.
  */
  bool GetRoomActionFlag() {
    return npc->GetTalking();
  }

/**
  * @brief Generic pass through function.
  * @details Increments and sets attributes in NPC.
  */
  void SetRoomActionFlag() {
    npc->SetTalkedThisState();
  }

/**
  * @brief Generic pass through function.
  * @details Returns the integer win/loss condition flag of NPC.
  */
  int WinCondtionFlag() {
    return npc->WinCondition();
  }
};

#endif
