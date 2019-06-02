//
// Created by samurai on 5/31/19.
//

#include "MercenaryShop.hpp"

MercenaryShop::MercenaryShop()
{
   locName = "Mercenary Shop";
   key = 0;
}

Fighter *MercenaryShop::buyFighter(int choice)
{

   if (choice == 1)
   {
      Fighter *g = new Gru;
      return g;
   }
   else if (choice == 2)
   {
      Fighter *c = new ChineseSOP;
      return c;
   }
   else if (choice == 3)
   {
      Fighter *s = new SAS;
      return s;
   }
   else if (choice == 4)
   {
      Fighter *seal = new Seal;
      return seal;
   }

}

MercenaryShop::~MercenaryShop() {}

void MercenaryShop::buildTeam(int opponent) {}

std::queue<Fighter *> *MercenaryShop::getTeam() {}
void MercenaryShop::destroyTeam() {}



