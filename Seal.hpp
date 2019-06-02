//
// Created by samurai on 6/2/19.
//

#ifndef RISE_THROUGH_THE_RANKS__SEAL_HPP
#define RISE_THROUGH_THE_RANKS__SEAL_HPP
#include "Fighter.hpp"

class Seal : public Fighter
{
public:
   Seal();
   int attack() override;
   int attackDice() override;
   int defendDice() override;
   void defend(int) override;
   ~ Seal() override;
};

#endif //RISE_THROUGH_THE_RANKS__SEAL_HPP
