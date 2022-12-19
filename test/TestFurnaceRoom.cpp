#include <string>
#include "Rooms.h"
#include "FurnaceRoom.h"
#include "RoomFactory.h"
#include "gtest/gtest.h"

TEST(TestFurnaceRoom, ConstructorTest) {
  std::string a ="a";
  std::string b = "a";
  std::string c ="a";
  std::string d ="a";
  std::string f ="a";
  bool e = false;
  FurnaceRoom* squi;
  EXPECT_NO_THROW(squi = new FurnaceRoom(2, a, b, c, d, e, f));
  delete squi;
}

TEST(TestFurnaceRoom, GetRoomActionFlagTest) {
  std::string a ="a";
  std::string b = "a";
  std::string c ="a";
  std::string d ="a";
  std::string f ="a";
  bool e = false;
  FurnaceRoom* squi;
  squi = new FurnaceRoom(2, a, b, c, d, e, f);
  EXPECT_FALSE(squi->GetRoomActionFlag());
  delete squi;
}

TEST(TestFurnaceRoom, RoomActionTest) {
  std::string a ="a";
  std::string b = "a";
  std::string c ="a";
  std::string d ="a";
  std::string f ="a";
  bool e = false;
  FurnaceRoom* squi;
  squi = new FurnaceRoom(2, a, b, c, d, e, f);
  EXPECT_NO_THROW(squi->RoomAction());
  delete squi;
}






