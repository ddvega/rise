//
// Created by samurai on 6/2/19.
//

#ifndef RISE_THROUGH_THE_RANKS__CHINESESOP_HPP
#define RISE_THROUGH_THE_RANKS__CHINESESOP_HPP
#include "Fighter.hpp"

class ChineseSOP : public Fighter
{
protected:
public:
   ChineseSOP();
   int attack() override;
   int attackDice() override;
   int defendDice() override;
   void defend(int) override;
   ~ ChineseSOP() override;
};

#endif //RISE_THROUGH_THE_RANKS__CHINESESOP_HPP
