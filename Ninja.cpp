//
// Created by samurai on 5/31/19.
//

#include "Ninja.hpp"

/*******************************************************************************
**  Default constructor for derived class
*******************************************************************************/
Ninja::Ninja()
{
   name = "Ninja";
   armor = 3;
   strength = 12;
   killed = false;
}

/*******************************************************************************
**  Returns a random number within range of the die. Die is used in attack.
*******************************************************************************/
int Ninja::attackDice()
{
   return rand() % 6 + 1;
}

/*******************************************************************************
**  Uses attackDice function to inflict damage on the opponent
*******************************************************************************/
int Ninja::attack()
{
   //Ninja attacks with 2 6 sided die
   return attackDice() + attackDice();
}

/*******************************************************************************
**  Returns a random number within range of the die. Die is used in defense.
*******************************************************************************/
int Ninja::defendDice()
{
   return rand() % 6 + 1;
}

/*******************************************************************************
**  Uses defendDice to supress damage done by opponents attack.  Additional
 *  traits provide added protection.
*******************************************************************************/
void Ninja::defend(int pain)
{
   //Ninja defends with 2 6sided die
   int counter = defendDice() + defendDice();

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
Ninja::~Ninja() {}