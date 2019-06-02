#include <iostream>
#include "Game.hpp"

int main()
{
   srand(time(nullptr));
   clearScreen(50);
   std::cout << "Welcome to RISE"
                "\n\nA series of circumstances have pushed you to the point of "
                "desperation \nand in the process you've made powerful enemies "
                "and powerful allies. \nYou've shown great skill in your "
                "ability "
                "to wage small scale war for \na notorious gang called The X, "
                "based out of Chicago. \n\nEvery year the most powerful gangs in"
                " the world compete in a war \ngame. Their smartest and most "
                "adept leaders, are sent to the world \nstage to lead a team of"
                " mercenaries to fight other teams of mercenaries."
                "\n\nIn order to win, you win five keys, one in each war zone."
                "\nIf you win these keys, you'll have the opportunity to fight"
                "\nThe champion in the champion's league. "
             << std::endl;

   std::cout << "\nEnter [p] to proceed or [q] to exit";
   int key = getch("pq");
   if (key == 'p')
   {
      clearScreen(50);
      std::cout << "\nRules of Engagement"
                   "\n\nYou start with a bank balance. With that balance you'll"
                   "\nbe able to build your team of mercenaries by entering the"
                   "\nWar Shop. If you run out of money, you will be executed"
                   "\nand the game will be over."
                   "\n\nWith each battle that you fight, you will either earn"
                   "\nmoney if you win or lose money if you lose."
                   "\n\nBuild your team, win five keys, enter Champions league"
                   "\nand defeat the champion!"
                << std::endl;
   }

   std::cout << "\nEnter [p] to proceed or [q] to exit";
   int key2 = getch("pq");

   if (key == 'p' && key2 == 'p')
   {
      Game s;
      s.play();
   }

   return 0;
}