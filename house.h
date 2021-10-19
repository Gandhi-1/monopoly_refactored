#include "property.h"
#ifndef HOUSE_H
#define HOUSE_H

class house: protected property{
    public:
        void buyHouse(Player p, Property pr);
        void sellHouse(Player p, Property pr);
        house();
        ~house();
};


#endif
