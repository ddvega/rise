/*******************************************************************************
** Program:       Rise Project 4
** Author:        David Vega
** Date:          6/3/19
** Description:
*******************************************************************************/

#include "Space.hpp"

Space::Space()
{
   top = nullptr;
   right = nullptr;
   left = nullptr;
   bottom = nullptr;
   fighter = nullptr;
   locName = "nowhere";
}

void Space::setTop(Space *&top)
{
   this->top = top;
}

void Space::setLocName(std::string locName)
{
   this->locName = locName;
}

void Space::setRight(Space *&right)
{
   this->right = right;
}

void Space::setLeft(Space *&left)
{
   this->left = left;
}

void Space::setBottom(Space *&bottom)
{
   this->bottom = bottom;
}

std::string Space::getLocationName()
{
   return locName;
}

Space *Space::getTop()
{
   return top;
}

Space *Space::getRight()
{
   return right;
}

Space *Space::getLeft()
{
   return left;
}

Space *Space::getBottom()
{
   return bottom;
}
void Space::setKey(int key)
{
   this->key = key;
}

int Space::getKey()
{
   return key;
}


//void Space::buildTeam() {}

Space::~Space() {}