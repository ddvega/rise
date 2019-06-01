//
// Created by samurai on 5/31/19.
//

#include "MercenaryShop.hpp"

MercenaryShop::MercenaryShop()
{
   locName = "Mercenary Shop";
}

Fighter *MercenaryShop::buyFighter(int choice)
{

   if (choice == 1)
   {
      Fighter *vamp = new Ninja;
      return vamp;
   }

}

MercenaryShop::~MercenaryShop() {}

void MercenaryShop::buildTeam(int opponent) {}

std::queue<Fighter *> *MercenaryShop::getTeam() {}


