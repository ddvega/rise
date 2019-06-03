//
// Created by samurai on 5/31/19.
//

#ifndef RISE_THROUGH_THE_RANKS__GAME_HPP
#define RISE_THROUGH_THE_RANKS__GAME_HPP

#include <queue>
#include "Space.hpp"
#include "MercenaryShop.hpp"
#include "WarZone.hpp"
#include "Champions.hpp"
#include "Fighter.hpp"
#include "Gru.hpp"
#include "Validation.hpp"
#include <vector>
#include <termios.h>
#include <unistd.h>

class Game
{

protected:
   std::queue<Fighter *> userTeam;
   std::queue<Fighter *> *enemyFighters;
   int bank;
   int keys;
   Fighter *fighter;
   Space *locator;
   Space *mercenaryShop;
   Space *east;
   Space *west;
   Space *asiaTrain;
   Space *americasTrain;
   Space *europeTrain;
   Space *champLeague;
   Space *enemyTeam;

public:
   Game();
   void printMap();
   void setSpaces();
   void moveMenu();
   void move(int &, int&);
   void play();
   void printTeam(std::queue<Fighter *>);
   void mShop();
   void warSpace();
   void hitFirst(Fighter *one, Fighter *two, int pick);
   void fight(std::queue<Fighter *> &uTeam, std::queue<Fighter *> enemy);
   ~Game();

};

#endif //RISE_THROUGH_THE_RANKS__GAME_HPP
