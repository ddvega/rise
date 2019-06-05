/*******************************************************************************
** Program:       Rise Project 4
** Author:        David Vega
** Date:          6/3/19
** Description:
*******************************************************************************/

#include "WarZone.hpp"
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
WarZone::WarZone()
{
   locName = "War Zone";
   key = 1;
   visa = 0;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
Fighter *WarZone::buyFighter(int choice)
{
   return nullptr;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
WarZone::~WarZone()
{
   destroyTeam();
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
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
**  This function validates that digits and special characters are not used.
*******************************************************************************/
std::queue<Fighter *> *WarZone::getTeam()
{
   return &enemy;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
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