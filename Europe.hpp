//
// Created by samurai on 5/31/19.
//

#ifndef RISE_THROUGH_THE_RANKS__EUROPE_HPP
#define RISE_THROUGH_THE_RANKS__EUROPE_HPP

#include "Space.hpp"

class Europe : public Space
{
public:
   Europe();
   ~Europe() override;
   Fighter *buyFighter(int choice) override;
   void buildTeam(int opponent) override;
   std::queue<Fighter *> *getTeam() override;
   void destroyTeam();

};

#endif //RISE_THROUGH_THE_RANKS__EUROPE_HPP
