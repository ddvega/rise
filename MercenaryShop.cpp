/*******************************************************************************
** Program:       Rise Project 4
** Author:        David Vega
** Date:          6/3/19
** Description:
*******************************************************************************/
#include "MercenaryShop.hpp"

/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
MercenaryShop::MercenaryShop()
{
   locName = "Mercenary Shop";
   key = 0;
   visa = 0;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
Fighter *MercenaryShop::buyFighter(int choice)
{

   if (choice == 1)
   {
      Fighter *g = new Gru;
      return g;
   }
   else if (choice == 2)
   {
      Fighter *c = new ChineseSOP;
      return c;
   }
   else if (choice == 3)
   {
      Fighter *s = new SAS;
      return s;
   }
   else
   {
      Fighter *seal = new Seal;
      return seal;
   }

}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
MercenaryShop::~MercenaryShop() {}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
void MercenaryShop::buildTeam(int opponent) {}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
std::queue<Fighter *> *MercenaryShop::getTeam()
{
   return nullptr;
}
/*******************************************************************************
**  This function validates that digits and special characters are not used.
*******************************************************************************/
void MercenaryShop::destroyTeam() {}



