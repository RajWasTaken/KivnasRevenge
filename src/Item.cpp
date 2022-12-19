/**
* @author Rohan Sharma <Rohan.sharma@uleth.ca>
* @date November 17th, 2022
*/

#include "Item.h"
#include <string>

Item::Item() {
name = "invalid";
}


Item::Item(std::string n) {
name = n;
}


std::string Item::getItem() {
return name;
}


void Item::setItem(std::string n) {
name = n;
}
