#include <string>
#include <vector>
#include "Inventory.h"
#include "Item.h"
#include "gtest/gtest.h"

TEST(TestInventory, DefaultConstructor) {
  Inventory h;
  EXPECT_EQ(h.notEmpty(), 0);
}

TEST(TestInventory, addItem) {
  Inventory h;
  Item i("Key");
  Item* ptr;
  ptr = &i;
  h.addItem(ptr);
  EXPECT_TRUE(h.hasItem(ptr));
}

TEST(TestInventory, removeItemRoom) {
  Inventory h;
  Item i("Key");
  Item i2("Lock");
  Item* ptr;
  Item* ptr2;
  ptr = &i;
  ptr2 = &i2;
  h.addItem(ptr);
  h.addItem(ptr2);
  h.removeItemRoom(1);

  EXPECT_FALSE(h.hasItem(ptr2));
}

TEST(TestInventory, ItemShow) {
  Inventory h;
  Item i("Key");
  Item* ptr;
  ptr = &i;
  h.addItem(ptr);

  EXPECT_EQ(h.Itemshow(0), ptr);
}

TEST(TestInventory, getSize) {
  Inventory h;
  Item i("Key");
  Item* ptr;
  ptr = &i;
  h.addItem(ptr);
  EXPECT_EQ(h.getSize(), 1);
}

TEST(TestInventory, notEmpty) {
  Inventory h;
  Item i("Key");
  Item* ptr;
  ptr = &i;
  h.addItem(ptr);

  EXPECT_TRUE(h.notEmpty());
}

TEST(TestInventory, hasItem) {
  Inventory h;
  Item i("Key");
  Item* ptr;
  ptr = &i;
  h.addItem(ptr);

  EXPECT_TRUE(h.hasItem(ptr));
}

