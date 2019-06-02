//
// Created by samurai on 5/31/19.
//

#ifndef RISE_THROUGH_THE_RANKS__WARZONE_HPP
#define RISE_THROUGH_THE_RANKS__WARZONE_HPP
#include "Space.hpp"
#include <queue>

class WarZone : public Space
{
protected:
   std::queue<Fighter *> asiaTeam;

public:
   WarZone();
   ~WarZone() override;
   void buildTeam(int opponent) override;
   Fighter *buyFighter(int choice) override;
   std::queue<Fighter *> *getTeam() override;
   void destroyTeam();


};

#endif //RISE_THROUGH_THE_RANKS__WARZONE_HPP
