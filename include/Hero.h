/**
 * @author Raj Pannu <manraj.pannu@uleth.ca>
 * @date November 18th, 2022
 */
#include <string>
#include <vector>
#include "Inventory.h"
#include "Item.h"
#include "Person.h"

#ifndef HERO_H
#define HERO_H
/**
 * @class Hero Hero.h "Hero.h"
 * @brief Implements the concrete player object.
 * @details Implements an object for the player with an inventory and functions that communicate with the game and environments.
 */
class Hero : public Person {
 private:
  /**<name for the hero inventory*/
  Inventory *Bag_of_Holding = new Inventory();
  /**<bool for the Robbed variable*/
  bool IsRobbed;

 public:
  /**
   * @brief Default Constructor. No parameters.
   */
  Hero();

  virtual ~Hero() {
    delete Bag_of_Holding;
  }
  /**
   * @brief Return a string describing the player's current status.
   * @details Prints a string showing the player's items and current gameplay state.
   */
  void PrintInv();
  /**
   * @brief Moves the player's position around the matrix/
   * @param[in] direction An integer direction.
   */
  void MoveHero(int direction);
  /**
   * @brief Utlitizes the inventory's methods to add an item from the inventory.
   */
  void CallAdd(Item *thing);
  /**
   * @brief Utlitizes the inventory's methods to delete an item from the inventory.
   */
  void CallDelete();
  /**
   * @brief Evaluates the player's inventory and determines if an item in there matches a specific item's name.
   * @details  For example looks to see if any item is named "Basement Key."
   */
  bool CorrectItem();

  /**
   * @brief User inputs what item they want to use and checks to see if we can use it 
   * @details checks which item is being used and sees if we can use it
   * @return true if we can use item, false otherwise
   */
  bool HasItems();

  /**
   * @brief checks to see if you have all the ducks or bomb parts 
   * @details deletes all the ducks and bombs parts if there all all 4 and then gives you bomb
   * @return true if the 4 items are found
   */
  int StateChecker(std::string s);

  /**
   * @brief returns the Robbed variable
   * @details returns the Robbed variable 
   * @return Robbed variable
   */

  bool GetRobbed();

  /**
   * @brief sets Robbed variable
   * @details changes the robbed variable to true 
   */
  void SetRobbed();

  void StateItemDeleter(std::string);
};

#endif  // HERO_H
