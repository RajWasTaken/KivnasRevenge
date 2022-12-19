#ifndef FURNACEROOM_H
#define FURNACEROOM_H
#include <string>
#include "Rooms.h"

class FurnaceRoom : public Rooms {
 private:
  /** Bool for the breaker in the room*/
  bool breaker = false;

 public:
  /**
  * @brief Constructor for Furnace Room class 
  * @details Takes the constructor from the RoomFactor class and creates the Furnace room
  * @param[in] RoomType A int parameter for the Room type
  * @param[in] a A string parameter 
  * @param[in] b A string parameter for room name 
  * @param[in] c A string parameter for the extreme detail
  * @param[in] d A string parameter for room description
  * @param[in] e A bool parameter for noise
  * @param[in] f A string parameter direction
  */
  FurnaceRoom(int RoomType, std::string a, std::string b, std::string c,
              std::string d, bool e, std::string f)
      :
      Rooms(RoomType, a, b, c, d, e, f) {
  }
  /**
  * @brief Makes the breaker equal to true 
  * @details Void function to make the breaker equal true 
  */
  void RoomAction() {
    breaker = true;
  }
  /**
  * @brief looks at the room flag and returns true if they use it 
  * @details Looks to see if the player uses the dumbwaiter
  * @return true if the player uses the room action in the dumbwaiter else false
  */
  bool GetRoomActionFlag() {
    return breaker;
  }
};

#endif
