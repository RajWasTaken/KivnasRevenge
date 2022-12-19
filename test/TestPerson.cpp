#include <string>
#include "Person.h"
#include "gtest/gtest.h"

TEST(TestPerson, ConstructorTest) {
  Person* p = new Person();
  EXPECT_EQ(p-> GetLocationPlace(), 0);
  EXPECT_EQ(p-> GetLocationLevel(), 1);
  delete p;
}
TEST(TestPerson, UpdatePositionTest) {
  Person* p = new Person();
  p->SetLocation(1, 1);
  EXPECT_EQ(p-> GetLocationPlace(), 1);
  EXPECT_EQ(p-> GetLocationLevel(), 1);
  delete p;
}
