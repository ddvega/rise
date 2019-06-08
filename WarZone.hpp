/*******************************************************************************
** Program:       Rise Project 4
** Author:        David Vega
** Date:          6/3/19
** Description:
*******************************************************************************/

#ifndef RISE_THROUGH_THE_RANKS__WARZONE_HPP
#define RISE_THROUGH_THE_RANKS__WARZONE_HPP
#include "Space.hpp"
#include <queue>

class WarZone : public Space
{
protected:
   std::queue<Fighter *> enemy;

public:
   WarZone();
   ~WarZone() override;
   void buildTeam(int opponent) override;
   Fighter *buyFighter(int choice, int &) override;
   std::queue<Fighter *> *getTeam() override;
   void destroyTeam();


};

#endif //RISE_THROUGH_THE_RANKS__WARZONE_HPP
