//
// Created by samurai on 5/31/19.
//

#include "Sas.hpp"

/*******************************************************************************
**  Default constructor for derived class
*******************************************************************************/
SAS::SAS()
{
   name = "SAS Operative";
   armor = 3;
   strength = 25;
   killed = false;
}

/*******************************************************************************
**  Returns a random number within range of the die. Die is used in attack.
*******************************************************************************/
int SAS::attackDice()
{
   return rand() % 20 + 1;
}

/*******************************************************************************
**  Uses attackDice function to inflict damage on the opponent
*******************************************************************************/
int SAS::attack()
{
   //Gru attacks with a 20 sided die
   return attackDice();
}

/*******************************************************************************
**  Returns a random number within range of the die. Die is used in defense.
*******************************************************************************/
int SAS::defendDice()
{
   return rand() % 12 + 1;
}

/*******************************************************************************
**  Uses defendDice to supress damage done by opponents attack.  Additional
 *  traits provide added protection.
*******************************************************************************/
void SAS::defend(int pain)
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
SAS::~SAS() {}
