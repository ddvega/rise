/*******************************************************************************
** Program:       Rise -- Final Project
** Author:        David Vega
** Date:          6/3/19
** Description:   This is a derived class of the Space class. The purpose of
**                this class is to provide the user with a space that acts as a
**                marketplace of fighters
*******************************************************************************/

#ifndef RISE_THROUGH_THE_RANKS__MERCENARYSHOP_HPP
#define RISE_THROUGH_THE_RANKS__MERCENARYSHOP_HPP

#include "Space.hpp"
#include "Fighter.hpp"
#include "Gru.hpp"
#include "ChineseSop.hpp"
#include "Sas.hpp"
#include "Seal.hpp"
#include "Validation.hpp"

class MercenaryShop : public Space
{
protected:
public:
   MercenaryShop();
   void buildTeam(int opponent) override;
   Fighter *buyFighter(int choice, int &) override;
   ~MercenaryShop() override;
   std::queue<Fighter *> *getTeam() override;
   void destroyTeam() override;
};

#endif //RISE_THROUGH_THE_RANKS__MERCENARYSHOP_HPP
