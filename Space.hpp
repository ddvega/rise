//
// Created by samurai on 5/31/19.
//

#ifndef RISE_THROUGH_THE_RANKS__SPACE_HPP
#define RISE_THROUGH_THE_RANKS__SPACE_HPP
#include <iostream>
#include <string>
#include "Fighter.hpp"
#include "Ninja.hpp"
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
public:
   //constructor and destructor
   Space();
   virtual ~Space();

   //functions only in base class
   void setTop(Space *&);
   void setRight(Space *&);
   void setLeft(Space *&);
   void setBottom(Space *&);

   //getters
   Space *getTop();
   Space *getRight();
   Space *getLeft();
   Space *getBottom();

   std::string getLocationName();

   //pure virtual functions overridden in derived classes
   virtual Fighter *buyFighter(int choice) = 0;
   virtual void buildTeam(int opponent) = 0;
   virtual std::queue<Fighter *> *getTeam() = 0;


};

#endif //RISE_THROUGH_THE_RANKS__SPACE_HPP
