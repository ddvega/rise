/*******************************************************************************
** Program:       Rise -- Final Project
** Author:        David Vega
** Date:          6/3/19
** Description:   This is a base class that has four pointers used to connect
**                to other spaces above, below, to the left and to the right
*******************************************************************************/

#ifndef RISE_THROUGH_THE_RANKS__SPACE_HPP
#define RISE_THROUGH_THE_RANKS__SPACE_HPP
#include <iostream>
#include <string>
#include "Fighter.hpp"
#include "Gru.hpp"
#include "ChineseSop.hpp"
#include "Sas.hpp"
#include "Seal.hpp"
#include <queue>

class Space
{
protected:
   Space *top;
   Space *right;
   Space *left;
   Space *bottom;
   std::string locName;
   Fighter *fighter;
   int key;
   int visa;
public:
   //constructor and destructor
   Space();
   virtual ~Space();

   //functions only in base class
   void setTop(Space *&);
   void setRight(Space *&);
   void setLeft(Space *&);
   void setBottom(Space *&);
   void setLocName(std::string);
   void setKey(int);
   void setVisa(int);
   int getVisa();
   int getKey();
   std::string getLocationName();
   Space *getTop();
   Space *getRight();
   Space *getLeft();
   Space *getBottom();

   //pure virtual functions overridden in derived classes
   virtual Fighter *buyFighter(int, int &) = 0;
   virtual void buildTeam(int opponent) = 0;
   virtual std::queue<Fighter *> *getTeam() = 0;
   virtual void destroyTeam() = 0;
};

#endif //RISE_THROUGH_THE_RANKS__SPACE_HPP
