/*******************************************************************************
** Program:       Rise Project 4
** Author:        David Vega
** Date:          6/3/19
** Description:
*******************************************************************************/

#ifndef RISE_THROUGH_THE_RANKS__GRU_HPP
#define RISE_THROUGH_THE_RANKS__GRU_HPP

#include "Fighter.hpp"
#include <iomanip>
#include <iostream>
#include <string>

class Gru : public Fighter
{
protected:
public:
   Gru();
   int attack() override;
   int attackDice() override;
   int defendDice() override;
   void defend(int) override;
   ~ Gru() override;
};

#endif //RISE_THROUGH_THE_RANKS__GRU_HPP
