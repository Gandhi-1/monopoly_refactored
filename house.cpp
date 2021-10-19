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
  pr.rent = pr.rent*1.1
  num_house++;
}

// function for selling house
virtual void House::sellHouse(Player p, Property pr) {
  p.change_balance(0.5*pr.price,'+');
  pr.rent = pr.rent/1.1;
  num_house--;
}
