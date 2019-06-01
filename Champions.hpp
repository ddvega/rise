//
// Created by samurai on 5/31/19.
//

#ifndef RISE_THROUGH_THE_RANKS__CHAMPIONS_HPP
#define RISE_THROUGH_THE_RANKS__CHAMPIONS_HPP
#include "Space.hpp"
class Champions : public Space
{
public:
   Champions();
   ~Champions() override;
   Fighter *buyFighter(int choice) override;
   void buildTeam(int opponent) override;
   std::queue<Fighter *> *getTeam() override;

};

#endif //RISE_THROUGH_THE_RANKS__CHAMPIONS_HPP
