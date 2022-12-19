/**
 * @author Raj Pannu <manraj.pannu@uleth.ca>
 * @date November 18th, 2022
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>
/**
 * @class Person Person.h "Person.h"
 * @brief Implements a generalized entity that has a position in the matrix.
 * @details Abstracts the instantiation of an entity and contains its x and y coordinates/
 */
class Person {
 protected:
  /** Int for the X coord.*/
  int LocationPlace = 0;
  /** Int for the Y coord.*/
  int LocationLevel = 1;

 public:
  Person();
  /**
   * @brief Getter for x index
   * @returns Integer index
   */
  int GetLocationPlace();
  /**
   * @brief Getter for y index
   * @returns Integer index
   */
  int GetLocationLevel();
  /**
   * @brief Moves the entity to any coordinate in the matrix.
   * @param[in] x the x coordinate to be moved to
   * @param[in] y the y coordinate to be moved to
   */
  void SetLocation(int x, int y);
};

#endif  // PERSON_H
