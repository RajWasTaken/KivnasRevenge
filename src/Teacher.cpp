/**
* @author Kaelan Croucher <kaelan.croucher@uleth.ca>
 * @date December 9th, 2022
 */
#include <Teacher.h>
#include <cstdlib>
#include <iostream>
#include "Person.h"

Teacher::Teacher()
    :
    Person::Person() {
}

int Teacher::MoveTeacher(int loudLevel, int loudPlace) {
  // Note that for this next bit, the x is the floor, and the y is the Room.
  // Don't let kivna into the dumbwaiters/outside.
  // if dumbwaiter column, then move right

  if (loudPlace == 0)
    loudPlace = 1;

  // Different floors, not in hallway
  if (loudLevel != LocationLevel && LocationPlace != 4) {
    LocationPlace += 1;
    return 1;

    // Different floors, in hallway
  } else if ((loudLevel != LocationLevel) && (LocationPlace == 4)) {
    //Move up
    if (loudLevel < LocationLevel) {
      LocationLevel -= 1;
      // Move down
    } else {
      LocationLevel += 1;
    }
    return 1;
    // Same floor, on left
  } else if (loudLevel == LocationLevel && loudPlace < LocationPlace) {
    LocationPlace -= 1;
    return 1;
    // Same floor, on right
  } else if (loudLevel == LocationLevel && loudPlace > LocationPlace) {
    LocationPlace += 1;
    return 1;
  }
  return 0;
}
