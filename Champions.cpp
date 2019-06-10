/*******************************************************************************
** Program:       Rise -- Final Project
** Author:        David Vega
** Date:          6/3/19
** Description:   This is a derived class of the Space class. The purpose of
**                this class is to provide the user a space to have a final
**                battle with the
**                champion army.
*******************************************************************************/

#include "Champions.hpp"

/*******************************************************************************
**  Default constructor
*******************************************************************************/
Champions::Champions()
{
   locName = "Champion's League";
   key = 1;
   visa = 0;
}
/*******************************************************************************
**  Not used in this class, does nothing put return a nullpr
*******************************************************************************/
Fighter *Champions::buyFighter(int choice, int &money)
{
   return nullptr;
}
/*******************************************************************************
**  Default destructor initiates function to delete memory allocated to enemy
**  team
*******************************************************************************/
Champions::~Champions()
{
   destroyTeam();
}
/*******************************************************************************
**  Creates n fighters and adds them to the enemy team
*******************************************************************************/
void Champions::buildTeam(int opponent)
{
   for (int i = 0; i < opponent; i++)
   {
      int point = rand() % 5 + 1;

      if (point == 1)
      {
         fighter = new SAS;
         enemy.push(fighter);
         fighter = nullptr;
      }
      else if (point == 2 || point == 3 || point == 4)
      {
         fighter = new Seal;
         enemy.push(fighter);
         fighter = nullptr;
      }
      else
      {
         fighter = new ChineseSOP;
         enemy.push(fighter);
         fighter = nullptr;
      }
   }
}
/*******************************************************************************
**  returns a queue of fighter pointers
*******************************************************************************/
std::queue<Fighter *> *Champions::getTeam()
{
   return &enemy;
}
/*******************************************************************************
**  destroys a team one node at a time
*******************************************************************************/
void Champions::destroyTeam()
{
   //remove front node until the list is empty
   while (!enemy.empty())
   {
      delete enemy.front();
      enemy.pop();
   }
}

