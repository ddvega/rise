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
//remove front node until the list is empty
   while (!asiaTeam.empty())
   {
      delete asiaTeam.front();
      asiaTeam.pop();
   }
}

void Asia::buildTeam(int opponent)
{
   int teamSize = rand() % (opponent * 2) + (opponent / 2);
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
