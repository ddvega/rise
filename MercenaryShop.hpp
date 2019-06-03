/*******************************************************************************
** Program:       Rise Project 4
** Author:        David Vega
** Date:          6/3/19
** Description:
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
   Fighter *buyFighter(int choice) override;
   ~MercenaryShop() override;
   std::queue<Fighter *> *getTeam() override;
   void destroyTeam();


};

#endif //RISE_THROUGH_THE_RANKS__MERCENARYSHOP_HPP
