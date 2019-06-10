/*******************************************************************************
** Program:       Rise -- Final Project
** Author:        David Vega
** Date:          6/3/19
** Description:   This is a derived class of the Space class.  This class
**                provides a space for a territory where armies can fight each
**                other.
*******************************************************************************/

#include "WarZone.hpp"
/*******************************************************************************
**  Default constructor
*******************************************************************************/
WarZone::WarZone()
{
   locName = "War Zone";
   key = 1;
   visa = 0;
}
/*******************************************************************************
**  Pure virtual function not used in this class
*******************************************************************************/
Fighter *WarZone::buyFighter(int choice, int &money)
{
   return nullptr;
}
/*******************************************************************************
**  Default destructor initiates function to delete memory allocated to enemy
**  team
*******************************************************************************/
WarZone::~WarZone()
{
   destroyTeam();
}
/*******************************************************************************
**  Creates n fighters and adds them to the enemy team
*******************************************************************************/
void WarZone::buildTeam(int opponent)
{

   for (int i = 0; i < rand() % (opponent * 2) + 1; i++)
   {
      int point = rand() % 4 + 1;
      if (point == 1)
      {
         fighter = new Gru;
         enemy.push(fighter);
         fighter = nullptr;
      }
      else if (point == 2)
      {
         fighter = new ChineseSOP;
         enemy.push(fighter);
         fighter = nullptr;
      }
      else if (point == 3)
      {
         fighter = new SAS;
         enemy.push(fighter);
         fighter = nullptr;
      }
      else
      {
         fighter = new Seal;
         enemy.push(fighter);
         fighter = nullptr;
      }
   }
}
/*******************************************************************************
**  returns a queue of fighter pointers
*******************************************************************************/
std::queue<Fighter *> *WarZone::getTeam()
{
   return &enemy;
}
/*******************************************************************************
**  destroys a team one node at a time
*******************************************************************************/
void WarZone::destroyTeam()
{
   //remove front node until the list is empty
   while (!enemy.empty())
   {
      delete enemy.front();
      enemy.pop();
   }
}