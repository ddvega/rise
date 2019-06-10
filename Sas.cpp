/*******************************************************************************
** Program:       Rise -- Final Project
** Author:        David Vega
** Date:          6/3/19
** Description:   This is a derived class of the Fighter class. This class
**                creates a fighter character called SAS that ranks 2nd in
**                overall power compared to the other characters
*******************************************************************************/

#include "Sas.hpp"

/*******************************************************************************
**  Default constructor for derived class
*******************************************************************************/
SAS::SAS()
{
   name = "SAS Operative";
   armor = 5;
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
   //vampire defends with 1 6sided die
   int counter = defendDice();

   //completely blocks attack 33% of the time
   int charmed = rand() % 3 + 1;
   if (charmed != 1)
   {
      //subtract defense roll and armor from pain
      pain -= (counter + armor);
   }
   else //activate charm
   {
      pain = 0;
   }

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
