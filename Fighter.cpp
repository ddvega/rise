/*******************************************************************************
** Program:       Rise -- Final Project
** Author:        David Vega
** Date:          6/3/19
** Description:   This is a base class responsible for setting a fighter with
**                various characteristics that will fight against other
**                fighters.
*******************************************************************************/

#include "Fighter.hpp"

/*******************************************************************************
**  Default constructor for base class
*******************************************************************************/
Fighter::Fighter()
{
   name = "Default";
   armor = 0;
   strength = 0;
   killed = false;
}
/*******************************************************************************
**  Returns life status of character
*******************************************************************************/
bool Fighter::dead()
{
   return killed;
}
/*******************************************************************************
**  Returns name of character
*******************************************************************************/
std::string Fighter::getName()
{
   return name;
}
/*******************************************************************************
**  Adds strength to fighter
*******************************************************************************/
void Fighter::harden()
{
   strength += 5;
}
/*******************************************************************************
**  Default destructor for base class
*******************************************************************************/
Fighter::~Fighter() {}
