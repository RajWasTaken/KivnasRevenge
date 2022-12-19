#include <string>
#include "Item.h"
#include "Person.h"
#include "Teacher.h"
#include "gtest/gtest.h"

TEST(TestTeacher, LeftTest) {
  Teacher* t = new Teacher();
  t->SetLocation(0, 4);
  t->MoveTeacher(0, 1);
  EXPECT_EQ(t-> GetLocationPlace(), 3);
  EXPECT_EQ(t-> GetLocationLevel(), 0);
  t->SetLocation(0, 3);
  t->MoveTeacher(0, 2);
  EXPECT_EQ(t-> GetLocationPlace(), 2);
  EXPECT_EQ(t-> GetLocationLevel(), 0);

  delete t;
}

TEST(TestTeacher, RightTest) {
  Teacher* t = new Teacher();
  t->SetLocation(0, 1);
  t->MoveTeacher(0, 3);
  EXPECT_EQ(t-> GetLocationPlace(), 2);
  EXPECT_EQ(t-> GetLocationLevel(), 0);
  t->SetLocation(0, 1);
  t->MoveTeacher(0, 2);
  EXPECT_EQ(t-> GetLocationPlace(), 2);
  EXPECT_EQ(t-> GetLocationLevel(), 0);
  delete t;
}

TEST(TestTeacher, UpTest1) {
  Teacher* t = new Teacher();
  // teacher is one level Down, but not at stairs. Moves to stairs.
  t->SetLocation(1, 2);
  t->MoveTeacher(0, 1);
  EXPECT_EQ(t-> GetLocationPlace(), 3);
  EXPECT_EQ(t-> GetLocationLevel(), 1);
  // teacher is two levels Down, but not at stairs. Moves to stairs.
  t->SetLocation(2, 3);
  t->MoveTeacher(0, 1);
  EXPECT_EQ(t-> GetLocationPlace(), 4);
  EXPECT_EQ(t-> GetLocationLevel(), 2);
  delete t;
}

TEST(TestTeacher, UpTest2) {
  // Test when Kivna is on the stairs.
  Teacher* t = new Teacher();
  // teacher is one level down, moves up stairs.
  t->SetLocation(1, 4);
  t->MoveTeacher(0, 1);
  EXPECT_EQ(t-> GetLocationPlace(), 4);
  EXPECT_EQ(t-> GetLocationLevel(), 0);
  // teacher is two levels down, moves up stairs.
  t->SetLocation(2, 4);
  t->MoveTeacher(0, 1);
  EXPECT_EQ(t-> GetLocationPlace(), 4);
  EXPECT_EQ(t-> GetLocationLevel(), 1);

  delete t;
}

TEST(TestTeacher, DownTest1) {
  Teacher* t = new Teacher();
  // teacher is one level up, but not at stairs. Moves to stairs.
  t->SetLocation(0, 2);
  t->MoveTeacher(1, 1);
  EXPECT_EQ(t-> GetLocationPlace(), 3);
  EXPECT_EQ(t-> GetLocationLevel(), 0);
  // teacher is two levels up, but not at stairs. Moves to stairs.
  t->SetLocation(0, 3);
  t->MoveTeacher(2, 1);
  EXPECT_EQ(t-> GetLocationPlace(), 4);
  EXPECT_EQ(t-> GetLocationLevel(), 0);
  delete t;
}

TEST(TestTeacher, DownTest2) {
  // Test when Kivna is on the stairs.
  Teacher* t = new Teacher();
  // teacher is one level up, moves down stairs.
  t->SetLocation(0, 4);
  t->MoveTeacher(1, 1);
  EXPECT_EQ(t-> GetLocationPlace(), 4);
  EXPECT_EQ(t-> GetLocationLevel(), 1);
  // teacher is two levels up, moves down stairs.
  t->SetLocation(0, 4);
  t->MoveTeacher(2, 1);
  EXPECT_EQ(t-> GetLocationPlace(), 4);
  EXPECT_EQ(t-> GetLocationLevel(), 1);

  delete t;
}

TEST(TestTeacher, TestSafeDumbwaiter) {
  // Test when Kivna is on the stairs.
  Teacher* t = new Teacher();
  // teacher is at the entrance to dumbwaiter on lvl 0, cannot move in.
  t->SetLocation(0, 1);
  t->MoveTeacher(0, 0);
  EXPECT_EQ(t-> GetLocationPlace(), 1);
  EXPECT_EQ(t-> GetLocationLevel(), 0);
  // teacher is at the entrance to dumbwaiter on lvl 1, cannot move in.
  t->SetLocation(1, 1);
  t->MoveTeacher(1, 0);
  EXPECT_EQ(t-> GetLocationPlace(), 1);
  EXPECT_EQ(t-> GetLocationLevel(), 1);

  delete t;
}
