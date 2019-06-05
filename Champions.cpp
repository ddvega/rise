/*******************************************************************************
** Program:       Rise Project 4
** Author:        David Vega
** Date:          6/3/19
** Description:
*******************************************************************************/

#include "Champions.hpp"

/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
Champions::Champions()
{
   locName = "Champion's League";
   key = 1;
   visa = 0;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
Fighter *Champions::buyFighter(int choice)
{
   return nullptr;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
Champions::~Champions()
{
   destroyTeam();
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
void Champions::buildTeam(int opponent)
{
   for (int i = 0; i < opponent; i++)
   {
      int point = rand() % 2 + 1;

      if (point == 1)
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
std::queue<Fighter *> *Champions::getTeam()
{
   return &enemy;
}
void Champions::destroyTeam()
{
   //remove front node until the list is empty
   while (!enemy.empty())
   {
      delete enemy.front();
      enemy.pop();
   }
}

