/**
 * @author Raj Pannu <manraj.pannu@uleth.ca>
 * @date November 18th, 2022
 */
#include "Person.h"

#ifndef TEACHER_H
#define TEACER_H
/**
 * @class Teacher Teacher.h "Teacher.h"
 * @brief Implements the antagonistic person.
 * @details Implements the person that will navigate the matrix looking for you.
 */
class Teacher : public Person {
 public:
  Teacher();
  /**
   * @brief Algorithm for the Teacher's pathfinding.
   * @details Moves the teacher in a manner depending on the proximity of the noise that alerted it.
   * @param[in] loudPlace the room index that the teacher is pathfinding to.
   * @param[in] loudLevel the level index that the teacher is pathfinding to.
   */
  int MoveTeacher(int loudPlace, int loudLevel);

 private:
};

#endif  // TEACHER_H
