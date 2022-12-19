/**
 * @author Rohan Sharma <Rohan.sharma@uleth.ca>
 * @date November 17th, 2022
 */

#include "Inventory.h"
#include "InputChecker.h"
#include <Item.h>
#include <string>
#include <vector>
#include <iostream>

Inventory::Inventory() {
}

Item* Inventory::Itemshow(int i) {
  return inv[i];
}

void Inventory::listItems() {
  InputChecker inputchecker;
  int counter = 1;
  for (int i = 0; i < inv.size(); i++) {
    std::string InvOut = std::to_string(counter) + ": " + inv[i]->getItem();
    inputchecker.PrintMenuPrompt(InvOut);
    counter++;
  }
}

int Inventory::getSize() {
  int i;
  i = inv.size();
  return i;
}

void Inventory::addItem(Item *add) {
  if (add->getItem() == "invalid") {
    std::cout << "You can't add this item to the inventory" << std::endl;
  } else {
    inv.push_back(add);
  }
}

void Inventory::removeItem() {
  int input;
  listItems();

  std::cout << "Which item would you like to use" << ": ";
  std::cin >> input;
  input = input - 1;

  inv.erase(inv.begin() + input);
  listItems();
}

void Inventory::removeItemRoom(int i) {
  inv.erase(inv.begin() + i);
}

bool Inventory::notEmpty() {
  if (inv.size() > 0) {
    return 1;
  } else {
    return 0;
  }
}

bool Inventory::hasItem(Item *i) {
  int counter = 0;
  for (int z = 0; z < inv.size(); z++) {
    if (i->getItem() == inv[z]->getItem()) {
      counter = counter + 1;
    }
  }
  if (counter > 0) {
    return 1;
  } else {
    return 0;
  }
}

