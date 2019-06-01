//
// Created by samurai on 5/31/19.
//

#ifndef RISE_THROUGH_THE_RANKS__ASIA_HPP
#define RISE_THROUGH_THE_RANKS__ASIA_HPP
#include "Space.hpp"
#include <queue>

class Asia : public Space
{
protected:
   std::queue<Fighter *> asiaTeam;

public:
   Asia();
   ~Asia() override;
   void buildTeam(int opponent) override;
   Fighter *buyFighter(int choice) override;
   std::queue<Fighter *> *getTeam() override;

};

#endif //RISE_THROUGH_THE_RANKS__ASIA_HPP
