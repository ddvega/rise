/*******************************************************************************
** Program:       Rise -- Final Project
** Author:        David Vega
** Date:          6/3/19
** Description:   This is a derived class of the Fighter class. This class
**                creates a fighter character called GRU that ranks 4th in
**                overall power compared to the other characters
*******************************************************************************/

#include "Gru.hpp"

/*******************************************************************************
**  Default constructor for derived class
*******************************************************************************/
Gru::Gru()
{
   name = "GRU Operative";
   armor = 3;
   strength = 25;
   killed = false;
}

/*******************************************************************************
**  Returns a random number within range of the die. Die is used in attack.
*******************************************************************************/
int Gru::attackDice()
{
   return rand() % 20 + 1;
}

/*******************************************************************************
**  Uses attackDice function to inflict damage on the opponent
*******************************************************************************/
int Gru::attack()
{
   //Gru attacks with a 20 sided die
   return attackDice();
}

/*******************************************************************************
**  Returns a random number within range of the die. Die is used in defense.
*******************************************************************************/
int Gru::defendDice()
{
   return rand() % 12 + 1;
}

/*******************************************************************************
**  Uses defendDice to supress damage done by opponents attack.  Additional
 *  traits provide added protection.
*******************************************************************************/
void Gru::defend(int pain)
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
Gru::~Gru() {}