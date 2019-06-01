//
// Created by samurai on 5/31/19.
//

#include "Asia.hpp"

Asia::Asia()
{
   locName = "Asia";
}

Fighter *Asia::buyFighter(int choice) {}

Asia::~Asia()
{
   destroyTeam();
}

void Asia::buildTeam(int opponent)
{
   int teamSize = (rand() % opponent + 1) * 1.25;
   for (int i = 0; i < teamSize; i++)
   {
      fighter = new Ninja;
      asiaTeam.push(fighter);
      fighter = nullptr;
   }
}

std::queue<Fighter *> *Asia::getTeam()
{
   return &asiaTeam;
}

void Asia::destroyTeam()
{
   //remove front node until the list is empty
   while (!asiaTeam.empty())
   {
      delete asiaTeam.front();
      asiaTeam.pop();
   }
}