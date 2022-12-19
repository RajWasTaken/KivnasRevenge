/**
 * @author Kaelan Croucher <kaelan.croucher@uleth.ca>
 * @date November 17th, 2022
 */
#include <iostream>
#include <vector>
#include <string>
#include "Item.h"
#include "Inventory.h"
#include "InputChecker.h"
#include "NPC.h"

#ifndef ROOMS_H
#define ROOMS_H

class Rooms {
 private:
  /** Int for the type of room.*/
  int RoomType;
  /** Inventory for room object.*/
  Inventory RoomStuff;

  /** Integer noise value 0-3.*/
  int Noise;

  /** Boolean to determine room
   *  has been searched.*/

  /** String for Room Name*/
  std::string RoomName;

  /** String for detailed description
   *  of environment*/
  std::string RoomExtremeDetail;

  /** String for brief description
   *  of room. */
  std::string RoomDescription;

  /** String for a details printed
   *  when room is searched.*/
  std::string search_room_detail;

  std::string Directions;

 public:
  /** Item pointer to hold the item
   *  that was selected by user*/
  Item *SelectedItem;
  /**
   * Flag for if the room has been searched.
   */
  bool IsSearched;
  /**
   * Flag for if the room has been unlocked or not.
   */
  bool IsLocked;

  /**
   * @brief Default constructor for Rooms Class.
   * @details Constructs a empty room with no attributes.
   */
  Rooms();

  /**
   * @brief Override Constructor for Room Class.
   * @details Constructs a room with the specified attributes.
   */
  Rooms(int, std::string, std::string, std::string, std::string, bool,
        std::string);

  /**
   * @brief Void method for printing attribute to console.
   * @details Prints the name attribute of the room to the console.
   */
  void PrintRoomName();

  /**
   * @brief Int method that prints to console.
   * @details Checks if the inventory is empty then
   * the contents to the console and takes user input.
   * @return Int value of user input.
   */
  int ListOptions();

  /**
   * @brief Void method that prints to console.
   * @details Prints a detailed description of the room.
   */
  std::string GetRoomDescription();

  /**
   * @brief Void method that prints to the console.
   * @details Prints the contents of the inventory
   * to the room as well as a description.
   */
  void SearchIntensely();

  /**
   * @brief Void method that prints to the console.
   * @details Prompts user for input, assigns value to an
   * item pointer based on input.
   */
  bool PrintInventory();

  /**
   * @brief Int method returns noise value.
   * @details Get value of Int noise.
   * @return Int noise.
   */
  int GetNoise();

  /**
   * @brief Returns the number of items in the room
   * @details Calls the size of the inventory attribute in the room.
   */
  int GetInvSize();

  /**
   * @brief Returns the defined valid moveset of the room in the given state
   * @details Returns the moveset string read from the text file for that state.
   * @return An integer size value
   */
  std::string GetMoveSet();

  /**
   * @brief Returns the room name string
   * @return string of the room object's name
   */
  std::string GetRoomName();

  /**
   * @brief
   * @details A function for gamemain to be able to access and take items from the room inventory.
   */
  bool TransferItem(int);

  /**
   * @brief Returns the type of a room
   */
  int GetRoomType();

  /**
   * @brief Void method that adds pointer to inventory.
   * @details Adds an assigned Item pointer to the inventory of room.
   * @param[in] item pointer to add to inventory.
   */
  void AddItem(Item*);

  /**
   * @brief Returns the status of the room's items' accessiblity.
   * @return  A boolean value corresponding to the room's items' accesibility status.
   */
  bool ItemsHidden();

  /**
   * @brief A setter for room item acessibility.
   */
  void Reveal();

  /**
   * @brief An accessor to the room's NPC functionality. 
   * @details Meant for NPC room subclasses
   * @param[in] a  An NPC item passed by reference.
   */
  virtual void AddNPC(NPC *a) {
  }

  /**
   * @brief An accessor to the room's NPC's attributes. 
   * @details Meant for NPC room subclasses.
   * @returns a string corresponding to the name attribute of the NPC object.
   */
  virtual std::string NPCName() {
    return "Meow";
  }

  /**
   * @brief An accessor method to the unique functionalities of specialized rooms.
   * @details Meant for rooms with extra features such as switches or NPCs.
   */
  virtual void RoomAction() {
  }

  /**
   * @brief A getter method for the unique room attribute's status.
   * @details  Meant for rooms with extra features such as switches or NPCs.
   * @return A boolean value corresponding to the room attribute's status.
   */
  virtual bool GetRoomActionFlag() {
    return false;
  }

  /**
   * @brief An accessor method to the unique room attribute's status. 
   * @details  Meant for rooms with extra features such as switches or NPCs.
   */
  virtual void SetRoomActionFlag() {
  }

  /**
     * @brief An method to access win loss conditions within certain rooms.
     * @details  Meant to signal a win or loss condition has been met.
     */
  virtual int WinCondtionFlag() {
    return 0;
  }

  /**
   * @brief Void method that sets value.
   * @details Sets the value of private variable noise.
   * @param[in] z  value that we set noise to.
   */
  void SetNoise(int z);
};
#endif // ends ROOMS_H

