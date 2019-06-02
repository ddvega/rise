//
// Created by samurai on 5/31/19.
//

#include "ChineseSop.hpp"

/*******************************************************************************
**  Default constructor for derived class
*******************************************************************************/
ChineseSOP::ChineseSOP()
{
   name = "Chinese Special Operative";
   armor = 3;
   strength = 25;
   killed = false;
}

/*******************************************************************************
**  Returns a random number within range of the die. Die is used in attack.
*******************************************************************************/
int ChineseSOP::attackDice()
{
   return rand() % 20 + 1;
}

/*******************************************************************************
**  Uses attackDice function to inflict damage on the opponent
*******************************************************************************/
int ChineseSOP::attack()
{
   //Gru attacks with a 20 sided die
   return attackDice();
}

/*******************************************************************************
**  Returns a random number within range of the die. Die is used in defense.
*******************************************************************************/
int ChineseSOP::defendDice()
{
   return rand() % 12 + 1;
}

/*******************************************************************************
**  Uses defendDice to supress damage done by opponents attack.  Additional
 *  traits provide added protection.
*******************************************************************************/
void ChineseSOP::defend(int pain)
{
   //Gru defends with 2 6sided die
   int counter = defendDice();

   //subtract defense roll and armor from pain
   pain -= (counter + armor);

   //calculate damage taken
   if (pain > 0)
   {
      strength -= pain;
   }

   //check strength level and change kill status
   if (strength <= 0)
   {
      killed = true;
   }
}

/*******************************************************************************
**  Default destructor
*******************************************************************************/
ChineseSOP::~ChineseSOP() {}
