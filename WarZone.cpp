//
// Created by samurai on 5/31/19.
//

#include "WarZone.hpp"

WarZone::WarZone()
{
   locName = "War Zone";
   key = 1;
}

Fighter *WarZone::buyFighter(int choice)
{
   return nullptr;
}

WarZone::~WarZone()
{
   destroyTeam();
}

void WarZone::buildTeam(int opponent)
{
   opponent /= 2;
   for (int i = 0; i < rand() % opponent + 1; i++)
   {
      fighter = new Gru;
      enemy.push(fighter);
      fighter = nullptr;
   }
   for (int i = 0; i < rand()% opponent + 1; i++)
   {
      fighter = new ChineseSOP;
      enemy.push(fighter);
      fighter = nullptr;
   }
   for (int i = 0; i < rand()% opponent + 1; i++)
   {
      fighter = new SAS;
      enemy.push(fighter);
      fighter = nullptr;
   }
   for (int i = 0; i < rand()% opponent + 1; i++)
   {
      fighter = new Seal;
      enemy.push(fighter);
      fighter = nullptr;
   }
}

std::queue<Fighter *> *WarZone::getTeam()
{
   return &enemy;
}

void WarZone::destroyTeam()
{
   //remove front node until the list is empty
   while (!enemy.empty())
   {
      delete enemy.front();
      enemy.pop();
   }
}