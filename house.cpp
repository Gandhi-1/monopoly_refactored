#include <iostream>
#include <string>
#include "house.h"
#include "player.h"
#include "property.h"

// house constructor
House::House() {}

// //house destructor
// House::~House() {}

// function for buying house
virtual void House::buyHouse(Player p, Property pr) {
  p.change_balance(0.5*pr.price,'-');
  pr.add_value(pr.rent*0.1);
  pr.num_house++;
}

// function for selling house
virtual void House::sellHouse(Player p, Property pr) {
  p.change_balance(0.5*pr.price,'+');
  pr.add_value(-1/11*pr.rent);
  pr.num_house--;
}
