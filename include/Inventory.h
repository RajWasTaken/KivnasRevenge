/**
 * @author Rohan Sharma <Rohan.sharma@uleth.ca>
 * @date November 17th, 2022
 */

#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"
#include "InputChecker.h"
#include <string>
#include <vector>

class Inventory {
 public:
  /**
   * @brief Default constructor for Inventory class 
   * @details This method contructs a default Inventory object to nothing 
   */
  Inventory();

  /**
   * @brief Shows the item pointer at a certain postion in the inventory 
   * @details This method uses a integer to return the item pointer in the vector
   * @param[in] i  integer The Integer is used to find position.
   * @return The item pointer at that position 
   */
  Item* Itemshow(int i);

  /**
   * @brief Shows the size of the inventory
   * @details This method uses the vector to tell the inventory size
   * @return The size of the vector as an integer
   */
  int getSize();

  /**
   * @brief Adds an item to the inventory
   * @details Push back to the vector and add the item pointer in or display error
   * @param[in] add  Item pointer which is inputted in the vector
   */
  void addItem(Item *add);

  /**
   * @brief Removes item from the inventory  
   * @details User chooses an item to remove and its deleted from the vector
   */
  void removeItem();

  /**
   * @brief Removes item from the inventory  
   * @details integer parameter to remove item from the vector
   * @param[in] i  Integer to remove the element at that postion
   */
  void removeItemRoom(int i);

  /**
   * @brief lists the items in the inventory
   * @details Uses a for loop to output the vector elements or displays a message
   */
  void listItems();

  /**
   * @brief checks to see if inventory is empty
   * @details Looks at how many postions are in the vector
   * @return True or false depending if there are items in inventory 
   */
  bool notEmpty();

  /**
   * @brief checks to see if specific item is in inventory
   * @details Looks at the item within the inventory to see if its there 
   * @param[in] i Item pointer which is used to see if its in the vector
   * @return True or false depending if the item is in the inventory 
   */
  bool hasItem(Item *i);

 private:
  /**<Item* vector */
  std::vector<Item*> inv;
};

#endif  // INVENTORY_H
