/**
 * @author Kaelan Croucher <kaelan.croucher@uleth.ca>
 * @date November 17th, 2022
 */
#include <cstdlib>
#include <iostream>
#include <string>

#include "Inventory.h"
#include "Item.h"
#include "Rooms.h"
#include "InputChecker.h"
#include "NPC.h"

Rooms::Rooms() {
  RoomType = 0;
  RoomName = "";
  IsSearched = false;
  RoomDescription = "";
  RoomExtremeDetail = "";
  search_room_detail = "";
  Noise = 0;
  Directions = "";
}

Rooms::Rooms(int type, std::string Name, std::string Description,
             std::string ExtremeDescription, std::string Search, bool Locked,
             std::string Direction) {
  RoomType = type;
  RoomName = Name;
  IsLocked = Locked;
  IsSearched = false;
  RoomDescription = Description;
  RoomExtremeDetail = ExtremeDescription;
  search_room_detail = Search;
  Directions = Direction;
}

std::string Rooms::GetRoomDescription() {
  return RoomDescription;
}

void Rooms::SearchIntensely() {
  Noise = 2;
  IsSearched = true;
  if (RoomExtremeDetail != "!!!!!!") {
    RoomDescription = RoomExtremeDetail;
    RoomExtremeDetail = "!!!!!!";
  }
  std::cout << search_room_detail << std::endl << std::endl;
}

bool Rooms::PrintInventory() {
  InputChecker inputchecker;
  if (RoomStuff.notEmpty()) {
    inputchecker.PrintMenuPrompt("You find these Items:");
    RoomStuff.listItems();
    return true;
  } else {
    return false;
  }
}

bool Rooms::TransferItem(int ItemSelection) {
  SelectedItem = RoomStuff.Itemshow(ItemSelection - 1);
  RoomStuff.removeItemRoom(ItemSelection - 1);

  if (SelectedItem) {
    return true;
  } else {
    return false;
  }
}

int Rooms::GetInvSize() {
  return RoomStuff.getSize();
}

std::string Rooms::GetMoveSet() {
  return Directions;
}

std::string Rooms::GetRoomName() {
  return RoomName;
}

int Rooms::GetNoise() {
  return Noise;
}

void Rooms::SetNoise(int value) {
  Noise = value;
}

void Rooms::AddItem(Item *item) {
  RoomStuff.addItem(item);
}

int Rooms::GetRoomType() {
  return RoomType;
}

bool Rooms::ItemsHidden() {
  return IsSearched;
}

void Rooms::Reveal() {
  IsSearched = false;
}
