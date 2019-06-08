/*******************************************************************************
** Program:       Rise Project 4
** Author:        David Vega
** Date:          6/3/19
** Description:   This is a derived class of the Fighter class. This class
**                creates a fighter character called Seal that ranks 1st in
**                overall power compared to the other characters
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
