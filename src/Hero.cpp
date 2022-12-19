/**
* @author Kaelan Croucher <kaelan.croucher@uleth.ca>
 * @date December 9th, 2022
 */
#include <bits/stdc++.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <typeinfo>
#include <vector>

#include "Hero.h"
#include "Inventory.h"
#include "Item.h"
#include "Person.h"

Hero::Hero()
    :
    Person() {
  IsRobbed = 0;
}

bool Hero::CorrectItem() {
  if (Bag_of_Holding->getSize() > 0) {
    int choice = 0;
    int referenceint = 0;
    std::cout << "What item would you like to use?" << std::endl;
    Bag_of_Holding->listItems();
    std::cin >> choice;

    if ((typeid(choice) != typeid(referenceint)) || choice < 1
        || choice > Bag_of_Holding->getSize()) {
      std::cout << "Pick an item in your inventory you spoon" << std::endl;
    } else if ((Bag_of_Holding->Itemshow(choice - 1))->getItem() == "key") {
      return true;
    } else {
      std::cout << "That item does not work here" << std::endl;
      return false;
    }
  } else {
    std::cout << "There is nothing in the inventory" << std::endl;
    return false;
  }
  return false;
}
void Hero::MoveHero(int direction) {
  switch (direction) {
    case 1:
      //Left
      LocationPlace -= 1;
      break;
    case 2:
      //Right
      LocationPlace += 1;
      break;
    case 3:
      //Upstairs
      LocationLevel -= 1;
      break;
    case 4:
      //Downstairs
      LocationLevel += 1;
      break;
    case 5:
      LocationLevel = 3 - LocationLevel - 1;
      break;
  }
}

void Hero::PrintInv() {
  Bag_of_Holding->listItems();
}
void Hero::CallAdd(Item *thing) {
  Bag_of_Holding->addItem(thing);
}
void Hero::CallDelete() {
  Bag_of_Holding->removeItem();
}

bool Hero::HasItems() {
  return Bag_of_Holding->notEmpty();
}

int Hero::StateChecker(std::string s) {
  int z;
  int counter = 0;
  std::string c1, c2, c3, c4;

  if (s == "Ducks") {
    c1 = "RohanDuck";
    c2 = "KaelanDuck";
    c3 = "MarcusDuck";
    c4 = "RajDuck";
  } else if (s == "BombParts") {
    c1 = "Enriched Uranium-235";
    c2 = "High-Speed Centrifuge";
    c3 = "Elmer's Glue";
    c4 = "Rope";
  }

  z = Bag_of_Holding->getSize();

  for (int i = 0; i < z; i++) {
    Item *a = Bag_of_Holding->Itemshow(i);

    if (a->getItem() == c1) {
      counter++;
    }

    if (a->getItem() == c2) {
      counter++;
    }
    if (a->getItem() == c3) {
      counter++;
    }
    if (a->getItem() == c4) {
      counter++;
    }
    a = nullptr;
  }
  return counter;
}

void Hero::StateItemDeleter(std::string State) {
  int z;
  int counter = 0;
  std::string c1, c2, c3, c4;

  if (State == "Ducks") {
    c1 = "RohanDuck";
    c2 = "KaelanDuck";
    c3 = "MarcusDuck";
    c4 = "RajDuck";
  }
  if (State == "BombParts") {
    c1 = "Enriched Uranium-235";
    c2 = "High-Speed Centrifuge";
    c3 = "Elmer's Glue";
    c4 = "Rope";
  }

  z = Bag_of_Holding->getSize();
  std::vector<int> ItemPosition;
  for (int i = 0; i < z; i++) {
    Item *a = Bag_of_Holding->Itemshow(i);

    if (a->getItem() == c1) {
      ItemPosition.push_back(i);
      counter++;
    }
    if (a->getItem() == c2) {
      ItemPosition.push_back(i);
      counter++;
    }
    if (a->getItem() == c3) {
      ItemPosition.push_back(i);
      counter++;
    }
    if (a->getItem() == c4) {
      ItemPosition.push_back(i);
      counter++;
    }
  }

  std::sort(ItemPosition.begin(), ItemPosition.end());
  int i = ItemPosition.size();

  for (int j = 0; j < i; j++) {
    Bag_of_Holding->removeItemRoom(ItemPosition[i - j - 1]);
  }

  if (counter == 4 && State == "BombParts") {
    Item *s = new Item("Bomb");
    Bag_of_Holding->addItem(s);
    s = nullptr;
  }
}

bool Hero::GetRobbed() {
  return IsRobbed;
}

void Hero::SetRobbed() {
  IsRobbed = true;
}

