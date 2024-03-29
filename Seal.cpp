/*******************************************************************************
** Program:       Rise -- Final Project
** Author:        David Vega
** Date:          6/3/19
** Description:   This is a derived class of the Fighter class. This class
**                creates a fighter character called Seal that ranks 1st in
**                overall power compared to the other characters
*******************************************************************************/

#include "Seal.hpp"

/*******************************************************************************
**  Default constructor for derived class
*******************************************************************************/
Seal::Seal()
{
   name = "Navy SEAL";
   armor = 6;
   strength = 25;
   killed = false;
}

/*******************************************************************************
**  Returns a random number within range of the die. Die is used in attack.
*******************************************************************************/
int Seal::attackDice()
{
   return rand() % 20 + 1;
}

/*******************************************************************************
**  Uses attackDice function to inflict damage on the opponent
*******************************************************************************/
int Seal::attack()
{
   //Gru attacks with a 20 sided die
   return attackDice();
}

/*******************************************************************************
**  Returns a random number within range of the die. Die is used in defense.
*******************************************************************************/
int Seal::defendDice()
{
   return rand() % 15 + 1;
}

/*******************************************************************************
**  Uses defendDice to supress damage done by opponents attack.  Additional
 *  traits provide added protection.
*******************************************************************************/
void Seal::defend(int pain)
{
   //vampire defends with 1 6sided die
   int counter = defendDice();

   //completely blocks attack 50% of the time
   int charmed = rand() % 2 + 1;
   if (charmed == 1)
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
Seal::~Seal() {}
