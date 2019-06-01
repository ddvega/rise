//
// Created by samurai on 5/31/19.
//

#ifndef RISE_THROUGH_THE_RANKS__AMERICAS_HPP
#define RISE_THROUGH_THE_RANKS__AMERICAS_HPP
#include "Space.hpp"

class Americas : public Space
{
public:
   Americas();
   ~Americas() override;
   Fighter *buyFighter(int choice) override;
   void buildTeam(int opponent) override;
   std::queue<Fighter *> *getTeam() override;
   //void destroyTeam();

};

#endif //RISE_THROUGH_THE_RANKS__AMERICAS_HPP
