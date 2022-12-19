#ifndef DUMBWAITER_H
#define DUMBWAITER_H
#include "Rooms.h"
#include <string>

class DumbWaiter : public Rooms {
 public:
  /**
  * @brief Constructor for DumbWaiter class 
  * @details Takes the constructor from the RoomFactor class and creates the dumbwaiter room
  * @param[in] RoomType A int parameter for the Room type
  * @param[in] a A string parameter 
  * @param[in] b A string parameter for room name 
  * @param[in] c A string parameter for the extreme detail
  * @param[in] d A string parameter for room description
  * @param[in] e A bool parameter for noise
  * @param[in] f A string parameter direction
  */
  DumbWaiter(int RoomType, std::string a, std::string b, std::string c,
             std::string d, bool e, std::string f)
      :
      Rooms(RoomType, a, b, c, d, e, f) {
  }

  /**
  * @brief looks at the room flag and returns true if they use it 
  * @details Looks to see if the player uses the dumbwaiter
  * @return true if the player uses the room action in the dumbwaiter else false
  */
  bool GetRoomActionFlag() {
    return true;
  }
};

#endif

