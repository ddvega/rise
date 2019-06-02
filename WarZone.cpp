//
// Created by samurai on 5/31/19.
//

#include "WarZone.hpp"

WarZone::WarZone()
{
   locName = "Asia";
   key = 1;
}

Fighter *WarZone::buyFighter(int choice) {}

WarZone::~WarZone()
{
   destroyTeam();
}

void WarZone::buildTeam(int opponent)
{
   int teamSize = (rand() % opponent + 1) * 1.25;
   for (int i = 0; i < teamSize; i++)
   {
      fighter = new Gru;
      asiaTeam.push(fighter);
      fighter = nullptr;
   }
}

std::queue<Fighter *> *WarZone::getTeam()
{
   return &asiaTeam;
}

void WarZone::destroyTeam()
{
   //remove front node until the list is empty
   while (!asiaTeam.empty())
   {
      delete asiaTeam.front();
      asiaTeam.pop();
   }
}