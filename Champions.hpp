/*******************************************************************************
** Program:       Rise Project 4
** Author:        David Vega
** Date:          6/3/19
** Description:   This is a derived class of the Space class. The purpose of
**                this class is to provide the user a space to have a final
**                battle with the
**                champion army.
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
   Fighter *buyFighter(int choice, int &) override;
   void buildTeam(int opponent) override;
   std::queue<Fighter *> *getTeam() override;
   void destroyTeam() override;
};

#endif //RISE_THROUGH_THE_RANKS__CHAMPIONS_HPP
