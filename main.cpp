/*******************************************************************************
** Program:       Rise Project 4
** Author:        David Vega
** Date:          6/3/19
** Description:
*******************************************************************************/
#include <iostream>
#include "Game.hpp"
#include "Validation.hpp"

int main()
{
   int key;
   srand(time(nullptr));
   clearScreen(50);
   std::cout << "Welcome to RISE"
                "\n\nA series of circumstances have pushed you to the point of "
                "desperation, \nand in the process, you've made powerful "
                "enemies that could only be \nneutralized with the help "
                "of powerful allies. Thus, your entry to \nthe criminal "
                "underworld was inevitable. In little time you've "
                "managed \nto rise through the ranks and become a captain. "
                "You've shown great skill \nin your ability "
                "to wage small scale war for a notorious gang called The "
                "X, "
                "\nbased out of Chicago. "
             << std::endl;

   std::cout << "\nEnter [p] to proceed";
   key = getch("pq");
   clearScreen(50);
   std::cout << "\n\nEvery year the most powerful "
                "gangs in"
                " the world compete in a war \ntournament. Their smartest and "
                "most "
                "adept leaders, are sent to the world \nstage to lead a team of"
                " mercenaries to fight other teams of mercenaries."
                "\nYou're syndicate believes you can win and has invested "
                "heavily in your \npreparation"
                " and ticket to the tournament. Winning this tournament will "
                "\ngive your syndicate first dibs on all high priority "
                "contract"
                " killings and \na seat at the international table. "
                "They expect you to win."
                "\n\nIn order to win, you need five keys, one from each war "
                "zone. The only \nway to get these keys is by "
                "defeating the armies you encounter and taking \ntheir keys. "
                "Once you win all five keys, you'll earn the "
                "opportunity to face \nthe champion in the champions league."
             << std::endl;

   std::cout << "\nEnter [p] to proceed";
   key = getch("p");
   clearScreen(50);
   std::cout << "\nRules of Engagement"
                "\n\nYou start with a bank balance. With that balance you'll"
                "\nbe able to build your team of mercenaries by entering the"
                "\nWar Shop."
                "\n\nWith each battle that you fight, you will either earn"
                "\nmoney if you win or lose money if you lose. If you run out "
                "\nof money the game is over."
                "\n\nRemember...Traveling costs money. Moving from one "
                "territory \nto another will cost you $1000 a journey"
                "\nAlso, in order to enter the west or europe, you need a visa"
                "\nThere's only one region that will sell you a visa, find it "
                "\nand make your purchase. "
                "\n\nBuild your team, win five keys, enter Champions league"
                "\nand defeat the champion! Good luck"
             << std::endl;

   std::cout << "\nEnter [p] to proceed or [q] to exit";
   key = getch("pq");

   if (key == 'p')
   {
      Game s;
      s.play();
   }

   return 0;
}