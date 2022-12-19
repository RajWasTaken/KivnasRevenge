/**
* @author Kaelan Croucher <kaelan.croucher@uleth.ca>
 * @date December 9th, 2022
 */

#ifndef COMPUTER_NPC_H
#define COMPUTER_NPC_H

#include <vector>
#include <string>
#include "NPC.h"
#include "ComputerNPCScreenBuilder.h"

/**
 * @class ComputerNPC ComputerNPC "ComputerNPC"
 * @brief subclass of NPC.
 */
class ComputerNPC : public NPC {
 public:
  /**
    * @brief Sets bool of the NPC being in the game or not.
    * @details Assigns bool to disable or enable an npc within a game.
    * @param[in] string value to store NPC's name.
    * @param[in] int value to set a NPCs location.
    * @param[in] int value to set a NPCs current state
    */
  ComputerNPC(std::string a, int b, int c);

  /**
    * @brief Enters converation look for ComputerNPC.
    * @details Enters NPC Converation loop.
    * @param[in] int to accept current state.
    */
  void ConvoOut(int i);

  /**
    * @brief Returns bool is player has made succeeded.
    * @details Returns bool for whether or not player passed Quiz.
    */
  bool HasPassed();

  /**
    * @brief Returns bool is player has made succeeded.
    * @details Returns bool for whether or not player passed Quiz.
    */
  bool HasFailed();

  /**
    * @brief Returns a bool set within the class..
    * @details Returns bool based on whether or not a
    * player has talked to the npc this turn.
    */
  bool GetTalking();

  /**
    * @brief Returns int is player has made succeeded.
    * @details Returns int for whether or not player passed Quiz.
    */
  int WinCondition();

 private:
  /**<MenuUtil Computer screen builder*/
  ComputerNPCScreenBuilder MenuUtil;

  /**
    * @brief Accepts file to be stored.
    * @details stores the file into 3d array.
    * @param[in] string for file read.
    */
  std::string ReadQuestion(std::string);

  /**<NumCorrect string for storing the number
   *  of questions answered correctly.*/
  int NumCorrect = -1;

  /**<Attempts string for storing the number of attempts made on the quiz.*/
  int Attempts;

  /**<question array of strings for quiz questions.*/
  std::string question[4];

  /**<ansarr array of strings for answers to quiz questions*/
  std::string ansarr[4][4];
};
#endif  // NPC_H
