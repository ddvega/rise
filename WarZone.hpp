/*******************************************************************************
** Program:       Rise -- Final Project
** Author:        David Vega
** Date:          6/3/19
** Description:   This is a derived class of the Space class.  This class
**                provides a space for a territory where armies can fight each
**                other.
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
