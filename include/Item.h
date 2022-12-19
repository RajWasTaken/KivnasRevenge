/**
* @author Rohan Sharma <Rohan.sharma@uleth.ca>
* @date November 17th, 2022
*/

#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
 public:
/**
* @brief Default constructor
* @details makes all variables equal to "invalid"
*/
  Item();

/**
* @brief Constructor for Items class
* @details Make the string parameter equal to the class name variable
* @param[in] n A string parameter to name the item
*/
  Item(std::string n);

/**
* @brief gets the string for item
* @details Gets the item name from the class variable
* @return The item name in a string 
*/  
  std::string getItem();

/**
* @brief Sets the name for a item 
* @details Rewrites the item name 
*/
  void setItem(std::string n);

 private:
/**<name for the item*/
  std::string name;
};


#endif  // ITEM_H
