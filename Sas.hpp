/*******************************************************************************
** Program:       Rise Project 4
** Author:        David Vega
** Date:          6/3/19
** Description:
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
