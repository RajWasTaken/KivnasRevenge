/**
* @author Kaelan Croucher <kaelan.croucher@uleth.ca>
 * @date December 9th, 2022
 */
#include <cstdlib>
#include <iostream>
#include "Inventory.h"
#include "Item.h"
#include "Person.h"

Person::Person() {
}

int Person::GetLocationPlace() {
  return LocationPlace;
}
int Person::GetLocationLevel() {
  return LocationLevel;
}

void Person::SetLocation(int level, int place) {
  LocationPlace = place;
  LocationLevel = level;
}
