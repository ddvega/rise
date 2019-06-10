/*******************************************************************************
** Program:       Rise -- Final Project
** Author:        David Vega
** Date:          6/3/19
** Description:   This is a base class responsible for setting a fighter with
**                various characteristics that will fight against other
**                fighters.
*******************************************************************************/

#ifndef RISE_THROUGH_THE_RANKS__FIGHTER_HPP
#define RISE_THROUGH_THE_RANKS__FIGHTER_HPP

#include <iomanip>
#include <iostream>
#include <string>
#include <ctime>

class Fighter
{
protected:
   std::string name;
   int strength;
   int armor;
   bool killed;

public:
   //constructor and destructor
   Fighter();
   virtual ~Fighter();

   //functions only in base class
   bool dead();
   std::string getName();
   void harden();

   //pure virtual functions overridden in derived classes
   virtual int attack() = 0;
   virtual int attackDice() = 0;
   virtual int defendDice() = 0;
   virtual void defend(int) = 0;
};

#endif //RISE_THROUGH_THE_RANKS__FIGHTER_HPP
