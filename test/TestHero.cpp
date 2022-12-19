#include <string>
#include "Item.h"
#include "Inventory.h"
#include "Person.h"
#include "Hero.h"
#include "gtest/gtest.h"

TEST(TestHero, ConstructorTest) {
  Hero l;
  Hero* h;
  h = &l;
  EXPECT_EQ(h-> GetLocationPlace(), 0);
  EXPECT_EQ(h-> GetLocationLevel(), 1);
  EXPECT_EQ(h-> GetRobbed(), false);
}

TEST(TestHero, UpdatePositionTest) {
  Hero l;
  Hero* h;
  h = &l;
  h->SetLocation(1, 1);
  EXPECT_EQ(h->GetLocationPlace(), 1);
  EXPECT_EQ(h->GetLocationLevel(), 1);
}

TEST(TestHero, MoveDownTest) {
  Hero l;
  Hero* h;
  h = &l;
  h->SetLocation(1, 1);
  h->MoveHero(4);
  EXPECT_EQ(h-> GetLocationPlace(), 1);
  EXPECT_EQ(h-> GetLocationLevel(), 2);
}

TEST(TestHero, MoveRightTest) {
  Hero l;
  Hero* h;
  h = &l;
  h->SetLocation(1, 1);
  h->MoveHero(2);
  EXPECT_EQ(h-> GetLocationPlace(), 2);
  EXPECT_EQ(h-> GetLocationLevel(), 1);
}

TEST(TestHero, MoveupTest) {
  Hero l;
  Hero* h;
  h = &l;
  h->SetLocation(1, 1);
  h->MoveHero(3);
  EXPECT_EQ(h-> GetLocationPlace(), 1);
  EXPECT_EQ(h-> GetLocationLevel(), 0);
}

TEST(TestHero, MoveLeftTest) {
  Hero l;
  Hero* h;
  h = &l;
  h->SetLocation(1, 1);
  h->MoveHero(1);
  EXPECT_EQ(h-> GetLocationPlace(), 0);
  EXPECT_EQ(h-> GetLocationLevel(), 1);
}

TEST(TestHero, MoveDumbWaiter) {
  Hero l;
  Hero* h;
  h = &l;
  h->SetLocation(0, 0);
  h->MoveHero(5);
  EXPECT_EQ(h-> GetLocationPlace(), 0);
  EXPECT_EQ(h-> GetLocationLevel(), 2);
  h->MoveHero(5);
  EXPECT_EQ(h-> GetLocationPlace(), 0);
  EXPECT_EQ(h-> GetLocationLevel(), 0);
}

TEST(TestHero, AddItemTest) {
  Hero l;
  Hero* h;
  h = &l;
  EXPECT_EQ(h->HasItems(), false);
  Item* i = new Item("thing");
  h->CallAdd(i);
  EXPECT_EQ(h->HasItems(), true);
  delete i;
}
/*
 TEST(TestHero, TestItemChecker) {
 Hero l;
 Hero *h;
 h = &l;
 EXPECT_EQ(h->HasItems(), false);
 Item *i = new Item("RajDuck");
 h->CallAdd(i);
 delete i;
 i = new Item("RohanDuck");
 h->CallAdd(i);
 delete i;
 i = new Item("KaelanDuck");
 h->CallAdd(i);
 delete i;
 i = new Item("High-Speed Centrifuge");
 h->CallAdd(i);
 delete i;
 i = new Item("Elmer's Glue");
 h->CallAdd(i);
 delete i;
 i = new Item("Rope");
 h->CallAdd(i);
 delete i;

 EXPECT_EQ(h->StateChecker("Ducks"), false);
 EXPECT_EQ(h->StateChecker("BombParts"), false);
 }
 */
/*
 TEST(TestHero, TestStateItemDeleterTRUE) {
 Hero l;
 Hero* h;
 h = &l;
 EXPECT_EQ(h->HasItems(), false);
 Item* i = new Item("RajDuck");
 h->CallAdd(i);
 delete i;
 i = new Item("RohanDuck");
 h->CallAdd(i);
 delete i;
 i = new Item("MarcusDuck");
 h->CallAdd(i);
 delete i;
 i = new Item("KaelanDuck");
 h->CallAdd(i);
 delete i;

 EXPECT_NO_THROW(h->StateItemDeleter("Ducks"));
 EXPECT_EQ(h->HasItems(), false);

 i = new Item("Enriched Uranium-235");
 h->CallAdd(i);
 Hero l;
 Hero* h;
 h = &l;
 delete i;
 i = new Item("High-Speed Centrifuge");
 h->CallAdd(i);
 delete i;
 i = new Item("Elmer's Glue");
 h->CallAdd(i);
 delete i;
 i = new Item("Rope");
 h->CallAdd(i);
 delete i;

 EXPECT_NO_THROW(h->StateItemDeleter("BombParts"));
 }
 */
/*
 TEST(TestHero, MoveUpTest){
 Hero l;
 Hero* h;
 h = &l;
 h->moveHero(3);
 h->moveHero(3);
 h->moveHero(3);
 h->moveHero(1);
 EXPECT_EQ(h-> GetLocationPlace(), 0);
 EXPECT_EQ(h-> GetLocationLevel(), 2);
 }
 */
//TEST(TestHero, addItemTest) {
//  Hero l;
//  Hero* h;
//  h = &l;
//  Item* i = new Item("thing");
//  h->CallAdd(i);
//  EXPECT_EQ(h->Status(), "1");
//  delete i;
//}
