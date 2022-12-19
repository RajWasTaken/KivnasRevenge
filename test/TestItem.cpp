#include <string>
#include "Item.h"
#include "gtest/gtest.h"

TEST(TestItem, DefaultConstructor) {
  Item i;
  EXPECT_EQ(i.getItem(), "invalid");
}


TEST(TestItem, PramConstructor) {
  Item i("Basement Key");
  EXPECT_EQ(i.getItem(), "Basement Key");
}

TEST(TestItem, SetItem) {
  Item i;
  std::string s = "Key";
    i.setItem(s);
  EXPECT_EQ(i.getItem(), "Key");
}

TEST(TestItem, GetItem) {
  Item i("Key");
  EXPECT_EQ(i.getItem(), "Key");
}
