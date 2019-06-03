//
// Created by samurai on 5/31/19.
//

#include "Champions.hpp"

Champions::Champions()
{
   locName = "Champion's League";
   key = 1;
}

Fighter *Champions::buyFighter(int choice)
{
   return nullptr;
}

Champions::~Champions()
{
   destroyTeam();
}

void Champions::buildTeam(int opponent)
{
   for (int i = 0; i < rand() % (opponent * 2) + 1; i++)
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

