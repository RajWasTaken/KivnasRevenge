#include <string>
#include "Rooms.h"
#include "DumbWaiter.h"
#include "RoomFactory.h"
#include "gtest/gtest.h"

TEST(TestDumbWaiter, ConstructorTest) {
  std::string a ="a";
  std::string b = "a";
  std::string c ="a";
  std::string d ="a";
  std::string f ="a";
  bool e = false;
  DumbWaiter* squi;
  EXPECT_NO_THROW(squi = new DumbWaiter(2, a, b, c, d, e, f));
  delete squi;
}

TEST(TestDumbWaiter, GetRoomActionFlagTest) {
  std::string a ="a";
  std::string b = "a";
  std::string c ="a";
  std::string d ="a";
  std::string f ="a";
  bool e = false;
  DumbWaiter* squi;
  squi = new DumbWaiter(2, a, b, c, d, e, f);
  EXPECT_TRUE(squi->GetRoomActionFlag());
  delete squi;
}
