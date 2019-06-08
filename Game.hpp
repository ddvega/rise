/*******************************************************************************
** Program:       Rise Project 4
** Author:        David Vega
** Date:          6/3/19
** Description:
*******************************************************************************/

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
   struct backpack
   {
      int cash, keys, visa;
   };
protected:
   std::queue<Fighter *> userTeam;
   std::queue<Fighter *> *enemyFighters;
   //int bank;
   //int keys;
   //int visa;
   //std::vector<int> backpack;
   backpack items;
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
   void printCup();
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
