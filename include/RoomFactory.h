#ifndef FACTORY_H
#define FACTORY_H
#include <string>
#include "Rooms.h"

/**
 * @class A factory pattern for generating rooms with their given parameters and unique types.
 */
class RoomFactory {
 private:
  /**
   * @brief Type identifier for the different room types
   * @details 0 = Standard Room 1 = Undefined 2 = Furnace Room 3 = NPC Room.
   */
  int ClassType;
 public:
  /**
   * @brief Constructor for RoomFactory class 
   * @details Takes the constructor and manages it to different Room constructors 
   * @param[in] a A string parameter for room name 
   * @param[in] b A string parameter for the extreme detail
   * @param[in] c A string parameter for room description
   * @param[in] d A string parameter for direction
   * @param[in] d A string parameter for locked 
   * @param[in] f A bool parameter for noise
   * @param[in] g A string parameter for search
   */
  Rooms* GetRoom(std::string a, std::string b, std::string c, std::string d,
                 std::string e, bool f, std::string g);
};

#endif
