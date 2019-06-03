/*******************************************************************************
** Program:       Rise Project 4
** Author:        David Vega
** Date:          6/3/19
** Description:
*******************************************************************************/

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
