//
// Created by samurai on 5/31/19.
//

#ifndef RISE_THROUGH_THE_RANKS__MERCENARYSHOP_HPP
#define RISE_THROUGH_THE_RANKS__MERCENARYSHOP_HPP

#include "Space.hpp"
#include "Fighter.hpp"
#include "Ninja.hpp"
#include "Validation.hpp"

class MercenaryShop : public Space
{
protected:
public:
   MercenaryShop();
   void buildTeam(int opponent) override;
   Fighter *buyFighter(int choice) override;
   ~MercenaryShop() override;
   std::queue<Fighter *> *getTeam() override;

};

#endif //RISE_THROUGH_THE_RANKS__MERCENARYSHOP_HPP
