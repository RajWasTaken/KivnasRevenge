#ifndef CONCRETE_STATE
#define CONCRETE_STATE

#include <string>
class Events {
 public:
  /**
   * @brief Pure virtual function for the subclasses
   * @details Looks to see if the state is ending
   * @return zero 
   */
  virtual int EndTest(int) = 0;
  /**
   * @brief Pure virtual function for the subclasses 
   * @details Looks to see the current state 
   * @return zero
   */
  virtual int CurrentState() = 0;
};

class StatePrologue : public Events {
 public:
  /**
   * @brief looks to see if we are moving to the next state
   * @details if the state is anything by 0 then we move to the next state 
   * @param[in] test we use this to see if we move states 
   * @return 1 if the test is anything but 0 else return 0 
   */
  int EndTest(int test) {
    if (test == 0)
      return 0;
    else
      return 1;
  }
  /**
   * @brief looks at the current state 
   * @details looks to see what the integer value of the state is and returns it 
   * @return zero
   */
  int CurrentState() {
    return 0;
  }
  /**
   * @brief Prologue constructor 
   * @details Constructor for the state after the previous state is passed 
   */
  StatePrologue() {
  }
};

class StateTalkAnvik : public Events {
 public:
  /**
   * @brief looks to see if we are moving to the next state
   * @details if the state is anything by 0 then we move to the next state 
   * @param[in] test we use this to see if we move states 
   * @return 2 if the test is anything but 0 else return 0
   */
  int EndTest(int test) {
    if (test == 0)
      return 0;
    else
      return 2;
  }
  /**
   * @brief looks at the current state 
   * @details looks to see what the integer value of the state is and returns it 
   * @return 1
   */
  int CurrentState() {
    return 1;
  }
  /**
   * @brief state constructor 
   * @details Constructor for the state after the previous state is passed 
   */
  StateTalkAnvik() {
  }
};

class StateGameStart : public Events {
 public:
  /**
   * @brief looks to see if we are moving to the next state
   * @details if the state is anything by 0 then we move to the next state 
   * @param[in] test we use this to see if we move states 
   * @return 3 if the test is anything but 0 else return 0
   */
  int EndTest(int test) {
    if (test == 0)
      return 0;
    else
      return 3;
  }
  /**
   * @brief looks at the current state 
   * @details looks to see what the integer value of the state is and returns it 
   * @return 2
   */
  int CurrentState() {
    return 2;
  }
  /**
   * @brief state constructor 
   * @details Constructor for the state after the previous state is passed 
   */
  StateGameStart() {
  }
};

class StateFindPassword : public Events {
 public:
  /**
   * @brief looks to see if we are moving to the next state
   * @details if the state is anything by 0 then we move to the next state 
   * @param[in] test we use this to see if we move states 
   * @return 4 if the test is anything but 0 else return 0
   */
  int EndTest(int test) {
    if (test == 0)
      return 0;
    else
      return 4;
  }
  /**
   * @brief looks at the current state 
   * @details looks to see what the integer value of the state is and returns it 
   * @return 3
   */
  int CurrentState() {
    return 3;
  }
  /**
   * @brief state constructor 
   * @details Constructor for the state after the previous state is passed 
   */
  StateFindPassword() {
  }
};

class StateTalkNiko1 : public Events {
 public:
  /**
   * @brief looks to see if we are moving to the next state
   * @details if the state is anything by 0 then we move to the next state 
   * @param[in] test we use this to see if we move states 
   * @return 5 if the test is anything but 0 else return 0
   */
  int EndTest(int test) {
    if (test == 0)
      return 0;
    else
      return 5;
  }
  /**
   * @brief looks at the current state 
   * @details looks to see what the integer value of the state is and returns it 
   * @return 4
   */
  int CurrentState() {
    return 4;
  }
  /**
   * @brief state constructor 
   * @details Constructor for the state after the previous state is passed 
   */
  StateTalkNiko1() {
  }
};

class StateDuckHunting : public Events {
 public:
  /**
   * @brief looks to see if we are moving to the next state
   * @details if the state is anything by 0 then we move to the next state 
   * @param[in] test we use this to see if we move states 
   * @return 6 if the test is 1, return 8 if the test is 2 else it's false 
   */
  int EndTest(int test) {
    if (test == 0)
      return 0;
    else if (test == 1)
      return 6;
    else if (test == 2)
      return 8;
    else
      return 0;
  }
  /**
   * @brief looks at the current state 
   * @details looks to see what the integer value of the state is and returns it 
   * @return 5
   */
  int CurrentState() {
    return 5;
  }
  /**
   * @brief state constructor 
   * @details Constructor for the state after the previous state is passed 
   */
  StateDuckHunting() {
  }
};

class DuckTalkToNiko : public Events {
 public:
  /**
   * @brief looks to see if we are moving to the next state
   * @details if the state is anything by 0 then we move to the next state 
   * @param[in] test we use this to see if we move states 
   * @return 0 if the test is 0, return 8 if the test is 2 else it's 7 
   */
  int EndTest(int test) {
    if (test == 0)
      return 0;
    else if (test == 2)
      return 8;
    else
      return 7;
  }
  /**
   * @brief looks at the current state 
   * @details looks to see what the integer value of the state is and returns it 
   * @return 6
   */
  int CurrentState() {
    return 6;
  }
  /**
   * @brief state constructor 
   * @details Constructor for the state after the previous state is passed 
   */
  DuckTalkToNiko() {
  }
};

class StateCompLab : public Events {
 public:
  /**
   * @brief looks to see if we are moving to the next state
   * @details if the state is anything by 0 then we move to the next state 
   * @param[in] test we use this to see if we move states 
   * @return 0 if the test is 0, else return 100
   */
  int EndTest(int test) {
    if (test == 0)
      return 0;
    else
      return 100;
  }
  /**
   * @brief looks at the current state 
   * @details looks to see what the integer value of the state is and returns it 
   * @return 7
   */
  int CurrentState() {
    return 7;
  }
  /**
   * @brief state constructor 
   * @details Constructor for the state after the previous state is passed 
   */
  StateCompLab() {
  }
};

class StateTalkNiko2 : public Events {
 public:
  /**
   * @brief looks to see if we are moving to the next state
   * @details if the state is anything by 0 then we move to the next state 
   * @param[in] test we use this to see if we move states 
   * @return 0 if the test is 0, else return 9
   */
  int EndTest(int test) {
    if (test == 0)
      return 0;
    else
      return 9;
  }
  /**
   * @brief looks at the current state 
   * @details looks to see what the integer value of the state is and returns it 
   * @return 8
   */
  int CurrentState() {
    return 8;
  }
  /**
   * @brief state constructor 
   * @details Constructor for the state after the previous state is passed 
   */
  StateTalkNiko2() {
  }
};

class StateBombHunting : public Events {
 public:
  /**
   * @brief looks to see if we are moving to the next state
   * @details if the state is anything by 0 then we move to the next state 
   * @param[in] test we use this to see if we move states 
   * @return 0 if the test is 0, else return 10
   */
  int EndTest(int test) {
    if (test == 0)
      return 0;
    else
      return 10;
  }
  /**
   * @brief looks at the current state 
   * @details looks to see what the integer value of the state is and returns it 
   * @return 9
   */
  int CurrentState() {
    return 9;
  }
  /**
   * @brief state constructor 
   * @details Constructor for the state after the previous state is passed 
   */
  StateBombHunting() {
  }
};

class BombTalkToNiko : public Events {
 public:
  /**
   * @brief looks to see if we are moving to the next state
   * @details if the state is anything by 0 then we move to the next state 
   * @param[in] test we use this to see if we move states 
   * @return 0 if the test is 0, else return 11
   */
  int EndTest(int test) {
    if (test == 0)
      return 0;
    else
      return 11;
  }
  /**
   * @brief looks at the current state 
   * @details looks to see what the integer value of the state is and returns it 
   * @return 10
   */
  int CurrentState() {
    return 10;
  }
  /**
   * @brief state constructor 
   * @details Constructor for the state after the previous state is passed 
   */
  BombTalkToNiko() {
  }
};

class StateFurnaceRoom : public Events {
 public:
  /**
   * @brief looks to see if we are moving to the next state
   * @details if the state is anything by 0 then we move to the next state 
   * @param[in] test we use this to see if we move states 
   * @return 0 if the test is 0, else return 12
   */
  int EndTest(int test) {
    if (test == 0)
      return 0;
    else
      return 12;
  }
  /**
   * @brief looks at the current state 
   * @details looks to see what the integer value of the state is and returns it 
   * @return 11
   */
  int CurrentState() {
    return 11;
  }
  /**
   * @brief state constructor 
   * @details Constructor for the state after the previous state is passed 
   */
  StateFurnaceRoom() {
  }
};

class StateGetOut : public Events {
 public:
  /**
   * @brief looks to see if we are moving to the next state
   * @details if the state is anything by 0 then we move to the next state 
   * @param[in] test we use this to see if we move states 
   * @return 0 if the test is 0, else return 100
   */
  int EndTest(int test) {
    if (test == 0)
      return 0;
    else
      return 100;
  }
  /**
   * @brief looks at the current state 
   * @details looks to see what the integer value of the state is and returns it 
   * @return 12
   */
  int CurrentState() {
    return 12;
  }
  /**
   * @brief state constructor 
   * @details Constructor for the state after the previous state is passed 
   */
  StateGetOut() {
  }
};

#endif
