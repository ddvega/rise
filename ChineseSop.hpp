/*******************************************************************************
** Program:       Rise -- Final Project
** Author:        David Vega
** Date:          6/3/19
** Description:   This is a derived class of the Fighter class. This class
**                creates a fighter character called Chinese Operative that
**                ranks 3rd in overall power compared to the other characters
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
