/**
* @author Kaelan Croucher <kaelan.croucher@uleth.ca>
 * @date December 9th, 2022
 */
#include "Rooms.h"
#include "DumbWaiter.h"
#include "Teacher.h"
#include "Hero.h"
#include "Inventory.h"
#include "Item.h"
#include "NPC.h"
#include "MainScreenBuilder.h"
#include "ConcreteState.h"
#include <string>
#include <iostream>
#include <vector>

#define LEVEL 3
#define PLACE 5

#ifndef GAMEMAIN_H
#define GAMEMAIN_H
/**
 * @class GameMain GameMain.h "GameMain.h"
 * @brief Sets up and runs the game.
 * @details Constructor creates all objects. Function called GameLoop
 * call is called to run the game that was set up. GameLoop calls all
 * other functions in this class.
 */
class GameMain {
 private:
  /**<int for the death counter*/
  int death_counter = 0;
  /**<name for the sound string*/
  std::string Sound = "The facility is eerily quiet.";
  /**<name for the string*/
  std::string Objective;
  /**<name for the stage pointer*/
  Events *Stages;
  /**<name for checking user input*/
  MainScreenBuilder inputchecker;
  /**<name for the Room pointer*/
  Rooms *current_room;
  /**<name for the Quit bool*/
  bool GameQuit = false;
  /**<name for the vector startlogo*/
  std::vector<std::string> StartLogo;

  Teacher *Kivna;
  /**
   * @brief The coolest guy around
   */
  Hero Mike_Mahon;
  /**
   * @brief The place where the magic happens
   */
  Rooms *Building[LEVEL][PLACE];
  /**
   * @brief Where antagonist goes in x direction.
   */
  int DestinationPlace;
  /**
   * @brief Where antagonist goes in y direction.
   */
  int DestinationLevel;

  /**
   * @brief prints out the text when the game ends.
   */
  void DeathText();

  /**
   * @brief prints out help for playing the game.
   */
  void help(void);

  /**
   * @brief prints movement menu
   * @details The system shows the ways player can move
   */
  bool PrintMoveMenu();

  /**
   * @brief prints inventory menu
   * @details The system shows the player inventory
   */
  bool PrintInventoryMenu();

  /**
   * @brief prints the pause menu
   * @details The system shows the pause menu
   */
  bool PrintPauseMenu();

  /**
   * @brief prints pickup menu
   * @details The system shows the pickup menu
   */
  bool PrintPickupMenu();

  /**
   * @brief Calls other functions in the GameMain class.
   * @details The system allows the player to pause the game
   * and review information he/she should already know.
   * These are things like help, inventory, or story events
   */
  bool MainMenu(void);

  /**
   * @brief Allows the player to interface with room.
   * @details Functions of the room class often need to interact
   * with the person class. This function facilitates this. It is
   * also the primary method by which the user interacts with the
   * room object they are located in.
   */
  bool interfaceRoom(void);

  /**
   * @brief a function to move between rooms.
   * @details a function that stores a responsibility of the interfaceRoom
   * function. Allows for more clarity when reading code.
   */
  void MovePlayer(int);

  /**
   * @brief prints out instructions for the game.
   */
  void Instructions();

  /**
   * @brief Checks to see if we are moving states 
   * @details calls new txt files and creates new states 
   */
  int StateMover(int);

 public:
  /**
   * @brief default constructor
   * @details sets up board.
   */
  GameMain(/*What do I put in here?*/);
  /**
   * @brief Responsible for setting up the game.
   */
  virtual ~GameMain();

  /**
   * @brief Deletes the map
   * @details Destructor for the matrix
   */
  void DeleteBuildings();

  /**
   * @brief Prints the start menu 
   * @details calls the printstartmenu function and checks to see if we quit
   */
  bool StartMenu();

  /**
   * @brief responsible for running the game.
   * @details Calls other functions until the game ends. The game
   * is acessed through this function.
   */
  void GameLoop(void);

  /**
   * @brief makes new map
   * @details Takes in a new text file and makes the new map 
   * @param[in] s A string parameter to new txt file
   */
  void StateRoomCreater(std::string s);

  /**
   * @brief Makes new NPC's
   * @details Reads from a txt file and sets up the npc
   * @param[in] x A int parameter for the floor 
   * @param[in] y A int parameter to the level
   * @param[in] s A string parameter to name the item
   * @param[in] z A int parameter for the state dialogue 
   */
  void NPCRoomCreater(int x, int y, std::string s, int z);

  /**
   * @brief Make sound relative to player location
   * @details makes different sound depending on the floor and level of the player
   */
  void KivnaSound(int);
  /**
   * @brief Updates Kivna movement 
   * @details Gives an int value to update is sound movement 
   * @param[in] x A int parameter for the sound update 
   */
  void KivnaUpdater(int x);
  /**
   * @brief Updates death checker
   * @details Gives an int value to update if we die
   * @param[in] x A int parameter for the death update 
   */
  bool CheckDeath(int x);
};
#endif // GAMEMAIN_H
