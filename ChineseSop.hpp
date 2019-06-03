/*******************************************************************************
** Program:       Rise Project 4
** Author:        David Vega
** Date:          6/3/19
** Description:
*******************************************************************************/

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
