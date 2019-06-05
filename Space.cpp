/*******************************************************************************
** Program:       Rise Project 4
** Author:        David Vega
** Date:          6/3/19
** Description:
*******************************************************************************/

#include "Space.hpp"
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
Space::Space()
{
   top = nullptr;
   right = nullptr;
   left = nullptr;
   bottom = nullptr;
   fighter = nullptr;
   locName = "nowhere";

}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
void Space::setTop(Space *&top)
{
   this->top = top;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
void Space::setLocName(std::string locName)
{
   this->locName = locName;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
void Space::setRight(Space *&right)
{
   this->right = right;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
void Space::setLeft(Space *&left)
{
   this->left = left;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
void Space::setBottom(Space *&bottom)
{
   this->bottom = bottom;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
std::string Space::getLocationName()
{
   return locName;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
Space *Space::getTop()
{
   return top;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
Space *Space::getRight()
{
   return right;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
Space *Space::getLeft()
{
   return left;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
Space *Space::getBottom()
{
   return bottom;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
void Space::setKey(int k)
{
   key += k;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
void Space::setVisa(int visa)
{
   this->visa = visa;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
int Space::getKey()
{
   return key;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
int Space::getVisa()
{
   return visa;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/

//void Space::buildTeam() {}

Space::~Space() {}