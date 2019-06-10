/*******************************************************************************
** Program:       Rise -- Final Project
** Author:        David Vega
** Date:          6/3/19
** Description:   This is a derived class of the Fighter class. This class
**                creates a fighter character called SAS that ranks 2nd in
**                overall power compared to the other characters
*******************************************************************************/

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
