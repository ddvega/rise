//
// Created by samurai on 6/2/19.
//

#ifndef RISE_THROUGH_THE_RANKS__SAS_HPP
#define RISE_THROUGH_THE_RANKS__SAS_HPP
#include "Fighter.hpp"

class SAS : public Fighter
{
protected:
public:
   SAS();
   int attack() override;
   int attackDice() override;
   int defendDice() override;
   void defend(int) override;
   ~ SAS() override;
};

#endif //RISE_THROUGH_THE_RANKS__SAS_HPP
