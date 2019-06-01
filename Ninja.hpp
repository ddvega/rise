//
// Created by samurai on 5/31/19.
//

#ifndef RISE_THROUGH_THE_RANKS__NINJA_HPP
#define RISE_THROUGH_THE_RANKS__NINJA_HPP

#include "Fighter.hpp"
#include <iomanip>
#include <iostream>
#include <string>

class Ninja : public Fighter
{
protected:
public:
   Ninja();
   int attack() override;
   int attackDice() override;
   int defendDice() override;
   void defend(int) override;
   ~ Ninja() override;
};

#endif //RISE_THROUGH_THE_RANKS__NINJA_HPP
