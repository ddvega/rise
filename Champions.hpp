/*******************************************************************************
** Program:       Rise Project 4
** Author:        David Vega
** Date:          6/3/19
** Description:
*******************************************************************************/

#ifndef RISE_THROUGH_THE_RANKS__CHAMPIONS_HPP
#define RISE_THROUGH_THE_RANKS__CHAMPIONS_HPP
#include "Space.hpp"
#include <queue>
class Champions : public Space
{
protected:
   std::queue<Fighter *> enemy;

public:
   Champions();
   ~Champions() override;
   Fighter *buyFighter(int choice) override;
   void buildTeam(int opponent) override;
   std::queue<Fighter *> *getTeam() override;
   void destroyTeam();


};

#endif //RISE_THROUGH_THE_RANKS__CHAMPIONS_HPP
