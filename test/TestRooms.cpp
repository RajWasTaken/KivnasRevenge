/**
 * @author Kaelan Croucher <kaelan.croucher@uleth.ca>
 * @date November 17th, 2022
 */

/*
 *Functions I have to test:
 *  Constructors - both
 *  TransferItem
 *
 *
 *Functions that allow me to test:
 * GetNoise
 * SetNoise
 * GetInvSize
 * GetMoveSet
 * GetRoomName
 * GetRoomType
 * AddItem
 * ItemsHidden	returns IsSearched
 * Reveal	What on earth?
 *
 *Functions that are never to be touched:
 * PrintRoomName()	- useless
 * ListOptions()	- prints to console
 * GetRoomDescription	- to be deleted.
 * SearchIntensly	- prints to console.
 * PrintInventory	- takes user input.
 *
 */

#include "Rooms.h"
#include "Inventory.h"
#include "Item.h"
#include "gtest/gtest.h"

TEST(TestRooms, DefaultConstructorTest) {
  Rooms r;
  EXPECT_EQ(r.GetNoise(), 0);
  EXPECT_EQ(r.GetInvSize(), 0);
  EXPECT_EQ(r.GetMoveSet(), "");
  EXPECT_EQ(r.GetRoomName(), "");
  EXPECT_EQ(r.GetRoomType(), 0);
}

TEST(TestRooms, OverrideConstructorTest) {
  Rooms r(0, "a", "b", "c", "d", 1, "f");

  EXPECT_EQ(r.GetMoveSet(), "f");
  EXPECT_EQ(r.GetRoomName(), "a");
  EXPECT_EQ(r.GetRoomType(), 0);

  EXPECT_EQ(r.IsLocked, true);
}

TEST(TestRooms, SetNoise) {
  Rooms r;
  r.SetNoise(1);
  EXPECT_EQ(r.GetNoise(), 1);
}

TEST(TestRooms, TransferItemsTEST) {
  Rooms r;
  Item *q = new Item("KillerRabit");
  r.AddItem(q);
  delete q;
  EXPECT_EQ(r.TransferItem(1), true);
}

