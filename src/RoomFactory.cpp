/**
* @author Kaelan Croucher <kaelan.croucher@uleth.ca>
 * @date December 9th, 2022
 */
#include <string>
#include "RoomFactory.h"
#include "DumbWaiter.h"
#include "NPCRoom.h"
#include "Rooms.h"
#include "FurnaceRoom.h"

Rooms* RoomFactory::GetRoom(std::string type, std::string a, std::string b,
                            std::string c, std::string d, bool e,
                            std::string f) {
  ClassType = type[0] - '0';
  switch (ClassType) {
    case 0:
      return new Rooms(ClassType, a, b, c, d, e, f);
      break;
    case 1:
      return new DumbWaiter(ClassType, a, b, c, d, e, f);
      break;
    case 2:
      return new FurnaceRoom(ClassType, a, b, c, d, e, f);
      break;
    case 3:
      return new NPCRoom(ClassType, a, b, c, d, e, f);
      break;
    default:
      return nullptr;
  }
}

