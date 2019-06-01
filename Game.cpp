//
// Created by samurai on 5/31/19.
//

#include "Game.hpp"

Game::Game()
{
   bank = 0;
   setSpaces();
   locator = mercenaryShop;
   //setMap();
}
/*******************************************************************************
**  Function executes attack and defend, randomly deciding who attacks first
*******************************************************************************/
void Game::setSpaces()
{
   mercenaryShop = new MercenaryShop;
   mercenaryShopLeft = new MercenaryShop;
   mercenaryShopRight = new MercenaryShop;
   asiaTrain = new Asia;
   americasTrain = new Americas;
   europeTrain = new Europe;
   champLeague = new Champions;

   mercenaryShop->setBottom(americasTrain);
   mercenaryShop->setTop(asiaTrain);
   mercenaryShop->setLeft(europeTrain);
   mercenaryShop->setRight(champLeague);
   mercenaryShop->setLocName("Central Shop");

   mercenaryShopLeft->setTop(europeTrain);
   mercenaryShopLeft->setRight(americasTrain);
   mercenaryShopLeft->setLocName("West Shop");

   mercenaryShopRight->setLeft(asiaTrain);
   mercenaryShopRight->setRight(champLeague);
   mercenaryShopRight->setLocName("East Shop");

   asiaTrain->setBottom(mercenaryShop);
   asiaTrain->setTop(mercenaryShopRight);
   asiaTrain->setLeft(europeTrain);
   asiaTrain->setRight(champLeague);

   americasTrain->setBottom(mercenaryShopLeft);
   americasTrain->setTop(mercenaryShop);
   americasTrain->setRight(champLeague);
   americasTrain->setLeft(europeTrain);

   europeTrain->setBottom(americasTrain);
   europeTrain->setTop(asiaTrain);
   europeTrain->setRight(mercenaryShop);
   europeTrain->setLeft(mercenaryShopLeft);

   champLeague->setBottom(americasTrain);
   champLeague->setTop(asiaTrain);
   champLeague->setRight(mercenaryShopRight);
   champLeague->setLeft(mercenaryShop);

}
/*******************************************************************************
**  Function executes attack and defend, randomly deciding who attacks first
*******************************************************************************/
void Game::moveMenu()
{
   {
      std::cout << "You're currently in " << locator->getLocationName()
                << "\n1. Move Up"
                << "\n2. Move Down"
                << "\n3. Move Left"
                << "\n4. Move Right"
                << "\n5. Enter space"
                << "\n6. Quit"
                << std::endl;

   }
}
/*******************************************************************************
**  Function executes attack and defend, randomly deciding who attacks first
*******************************************************************************/
void Game::move(int &exit, int &enter)
{
   int choice;

   std::cout << "location: " << locator->getLocationName() << std::endl;
   moveMenu();
   choice = maxMinIntOnly(1, 6);
   if (choice == 1)
   {
      if (locator->getTop() != nullptr)
      {
         locator = locator->getTop();
      }
   }
   else if (choice == 2)
   {
      if (locator->getBottom() != nullptr)
      {
         locator = locator->getBottom();
      }
   }
   else if (choice == 3)
   {
      if (locator->getLeft() != nullptr)
      {
         locator = locator->getLeft();
      }
   }
   else if (choice == 4)
   {
      if (locator->getRight() != nullptr)
      {
         locator = locator->getRight();
      }
   }
   else if (choice == 5)
   {
      enter = 1;
   }
   else
   {
      exit = 2;
   }

}
/*******************************************************************************
**  Function executes attack and defend, randomly deciding who attacks first
*******************************************************************************/
void Game::printTeam(std::queue<Fighter *> q)
{
   int count = 0;
   std::queue < Fighter * > q2;
   q2 = q;
   std::cout << "Your team: ";
   while (!q.empty())
   {
      count++;
      std::cout << q.front()->getName() << " ";
      q.pop();

      //print no more than 20 numbers per line
      if (count % 20 == 0)
      {
         std::cout << std::endl;
      }
   }
   std::cout << std::endl;
}
/*******************************************************************************
**  Function executes attack and defend, randomly deciding who attacks first
*******************************************************************************/
void Game::mShop()
{
   int answer, quantity;
   do
   {
      std::cout << "Welcome to the Mercenary Shop"
                << "\nPlease select the fighter you want to purchase"
                << "\n1. Ninja $10,000"
                << "\n2. Leave Fighter room"
                << std::endl;
      answer = maxMinIntOnly(1, 2);

      if (answer == 1)
      {
         std::cout << "Quantity: ";
         quantity = maxMinIntOnly(1, 100);
         if (bank >= 10000 * quantity)
         {
            for (int i = 0; i < quantity; i++)
            {
               userTeam.push(locator->buyFighter(answer));
               //std::cout << "Your Team: ";
               //printTeam(userTeam);
            }
         }
         else
         {
            std::cout << "You can't afford that" << std::endl;
         }
      }
   }
   while (answer == 1);
}
/*******************************************************************************
**  Function executes attack and defend, randomly deciding who attacks first
*******************************************************************************/
void Game::asianSpace()
{
   int bribe = rand() % 200000 + 1;
   int choice;
   std::cout << "You have entered the Asian Territory"
             << "\nA team consisting of: ";

   printTeam(*tempTeam);
   std::cout << "\n is ready to FIGHT your team"
             << "\nThey demand a payment of "
             << bribe
             << " to pass without fighting"
             << "\n1. Pay fee"
             << "\n2. Fight"
             << std::endl;
   choice = maxMinIntOnly(1, 2);
   if (choice == 1)
   {
      bank -= bribe;
   }
   else
   {
      //training only for cash. Dont fight to kill. Make copy of userTeam;
      //std::queue<Fighter*> copyUserTeam = userTeam;
      fight(userTeam, *tempTeam);
   }
}
/*******************************************************************************
**  Function executes attack and defend, randomly deciding who attacks first
*******************************************************************************/
void Game::play()
{
   bank = 100000 + rand() % 1000000 + 10000;
   int choice = 1, enterRoom = 0;
   do
   {
      clearScreen(60);
      //setMap();
      printMap();
      printTeam(userTeam);
      if (locator->getLocationName() == "Central Shop" && enterRoom == 1)
      {
         enterRoom = 0;
         mShop();
      }
      if (locator->getLocationName() == "Asia" && enterRoom == 1 && !userTeam
         .empty())
      {
         asiaTrain->destroyTeam();
         enterRoom = 0;
         asiaTrain->buildTeam(userTeam.size());
         tempTeam = asiaTrain->getTeam();
         asianSpace();
      }
      else
      {
         std::cout << "You may not enter without warriors" << std::endl;
         enterRoom = 0;
      }

      if (choice == 1)
      {
         move(choice, enterRoom);
      }

   }
   while (choice != 2);
}

/*******************************************************************************
**  Function executes attack and defend, randomly deciding who attacks first
*******************************************************************************/
void Game::hitFirst(Fighter *one, Fighter *two, int pick)
{
   //Player 1 attacks first
   if (pick == 1)
   {
      two->defend(one->attack());

      //stop counter attack if player dies in first attack
      if (!(two->dead()))
      {
         one->defend(two->attack());
      }
   }

   //Player 2 attacks first
   if (pick == 2)
   {
      one->defend(two->attack());

      //stop counter attack if player dies in first attack
      if (!(one->dead()))
      {
         two->defend(one->attack());
      }
   }

}
/*******************************************************************************
**  Function activates game by having two characters fight until one dies
*******************************************************************************/
void Game::fight(std::queue<Fighter *> &uTeam, std::queue<Fighter *> enemy)
{
   int battle = 1, t1Points = 0, t2Points = 0, rounds = 0;
   int money = 0;

   std::cout << "\nEnemy Team Size: " << enemy.size() << std::endl;
   std::cout << "Your Team Size: " << userTeam.size() << std::endl;
   do //while loop stops when one team runs out of fighters
   {
      //round consists of an attack and counter attack. Who attacks first is
      //randomly selected every round
      int test = rand() % 2 + 1;
      if (test == 1)
      {
         hitFirst(uTeam.front(), enemy.front(), 1);
      }
      else
      {
         hitFirst(uTeam.front(), enemy.front(), 2);
      }

      //keep track of how many rounds are fought in each battle
      rounds++;

      //team 1 fighter killed, team 2 wins battle
      if (uTeam.front()->dead())
      {
         std::cout << "Battle " << battle << ": Your Team's "
                   << uTeam.front()->getName()
                   << " "
                   << " vs Enemy's "
                   << enemy.front()->getName()
                   << " "
                   << "\nEnemy's "
                   << enemy.front()->getName()
                   << " "
                   << " Won after " << rounds << " rounds "
                   << std::endl;

         delete uTeam.front();//activate if you want to fight to death
         uTeam.pop(); //loser is removed from team1 stack
         t2Points++; //point added to team2
         battle++;//increment total battles
         rounds = 0;//reset rounds
         money -= 1000;
      }

      //team 2 fighter killed, team 1 wins battle
      if (enemy.front()->dead())
      {
         std::cout << "Battle " << battle << ": Your Team's "
                   << uTeam.front()->getName()
                   << " "
                   << " vs Enemy's " << enemy.front()->getName()
                   << " "
                   << "\nYour Team's "
                   << uTeam.front()->getName()
                   << " "
                   << " Won after " << rounds << " rounds "
                   << std::endl;
         uTeam.front()->harden();
         Fighter *fighterBack = uTeam.front();
         uTeam.push(fighterBack);
         uTeam.pop();
         //delete enemy.front();
         enemy.pop(); //loser is removed from team2 stack
         t1Points++; //point added to team1
         battle++;//increment total battles
         rounds = 0;//reset rounds
         money += 10000;
      }


      //if either team is empty, check who has the most points and print winner
      if ((uTeam.empty() || enemy.empty()))
      {
         //tie game
         if (t1Points == t2Points)
         {
            std::cout << "\nTeam A and Team B Tie! " << t2Points << " to "
                      << t1Points << std::endl << std::endl;
         }
            //team B wins
         else if (t2Points > t1Points)
         {
            std::cout << "\nTeam B Wins " << t2Points << " to " << t1Points
                      << std::endl << std::endl;
         }
            //team A wins
         else if (t1Points > t2Points)
         {
            std::cout << "\nTeam A Wins " << t1Points << " to " << t2Points
                      << std::endl << std::endl;
         }
      }
   }
   while (!(uTeam.empty() || enemy.empty())); //kill loop if team empty
   std::cout << "Bank Balance: " << bank;
   bank += money;
   std::cout << "\nYou earned: " << money
             << "\nNew Bank Balance: "
             << bank
             << std::endl;
   std::cout << "\nEnemy Team Size: " << enemy.size() << std::endl;
   std::cout << "Your Team Size: " << userTeam.size() << std::endl;
   printTeam(userTeam);

}

/*******************************************************************************
**  Function executes attack and defend, randomly deciding who attacks first
*******************************************************************************/
void Game::printMap()
{
   int xSize = 24;
   int ySize = 90;
   int count = 0;
   char map[xSize][ySize];
   for (int x = 0; x < xSize; x++)
   {
      for (int y = 0; y < ySize; y++)
      {
         map[x][0] = '|';
         map[x][ySize - 1] = '|';
         map[0][y] = '-';
         map[xSize - 1][y] = '-';
      }
   }
   //set the white spaces
   for (int x = 1; x < xSize - 1; x++)
   {
      for (int y = 1; y < ySize - 1; y++)
      {
         map[x][y] = ' ';
      }
      count++;
   }

   std::vector <std::pair<int, int>> points;
   if (locator->getLocationName() == "Europe")
   {
      //euro zone
      points.emplace_back(8, 3);
      points.emplace_back(8, 6);
      points.emplace_back(8, 9);
      points.emplace_back(8, 12);
      points.emplace_back(8, 15);
      points.emplace_back(8, 18);
      points.emplace_back(8, 21);
      points.emplace_back(8, 24);
      points.emplace_back(9, 3);
      points.emplace_back(12, 3);
      points.emplace_back(10, 3);
      points.emplace_back(11, 3);
      points.emplace_back(12, 24);
      points.emplace_back(12, 6);
      points.emplace_back(12, 9);
      points.emplace_back(12, 12);
      points.emplace_back(12, 15);
      points.emplace_back(12, 18);
      points.emplace_back(12, 21);
      points.emplace_back(9, 24);
      points.emplace_back(10, 24);
      points.emplace_back(11, 24);

      //set borders
      for (int i = 0; i < 22; i++)
      {
         map[points[i].first][points[i].second] = '#';
      }
   }

   if (locator->getLocationName() == "West Shop")
   {
      //shop left
      points.emplace_back(16, 3);
      points.emplace_back(16, 6);
      points.emplace_back(16, 9);
      points.emplace_back(16, 12);
      points.emplace_back(16, 15);
      points.emplace_back(16, 18);
      points.emplace_back(16, 21);
      points.emplace_back(16, 24);
      points.emplace_back(20, 3);
      points.emplace_back(20, 24);
      points.emplace_back(20, 6);
      points.emplace_back(20, 9);
      points.emplace_back(20, 12);
      points.emplace_back(20, 15);
      points.emplace_back(20, 18);
      points.emplace_back(20, 21);
      points.emplace_back(18, 24);
      points.emplace_back(19, 3);
      points.emplace_back(18, 3);
      points.emplace_back(19, 24);
      points.emplace_back(17, 3);
      points.emplace_back(17, 24);

      //set borders
      for (int i = 0; i < 22; i++)
      {
         map[points[i].first][points[i].second] = '#';
      }
   }

   if (locator->getLocationName() == "Asia")
   {
      //asia
      points.emplace_back(1, 30);
      points.emplace_back(1, 33);
      points.emplace_back(1, 36);
      points.emplace_back(1, 39);
      points.emplace_back(1, 42);
      points.emplace_back(1, 45);
      points.emplace_back(1, 48);
      points.emplace_back(5, 27);
      points.emplace_back(5, 30);
      points.emplace_back(5, 33);
      points.emplace_back(5, 36);
      points.emplace_back(5, 39);
      points.emplace_back(5, 42);
      points.emplace_back(5, 45);
      points.emplace_back(5, 48);
      points.emplace_back(4, 48);
      points.emplace_back(2, 48);
      points.emplace_back(3, 48);
      points.emplace_back(1, 27);
      points.emplace_back(2, 27);
      points.emplace_back(3, 27);
      points.emplace_back(4, 27);

      //set borders
      for (int i = 0; i < 22; i++)
      {
         map[points[i].first][points[i].second] = '#';
      }

   }

   if (locator->getLocationName() == "Central Shop")
   {
      //shop middle
      points.emplace_back(9, 30);
      points.emplace_back(9, 33);
      points.emplace_back(9, 36);
      points.emplace_back(9, 39);
      points.emplace_back(9, 42);
      points.emplace_back(9, 45);
      points.emplace_back(9, 48);
      points.emplace_back(9, 51);
      points.emplace_back(13, 33);
      points.emplace_back(13, 36);
      points.emplace_back(13, 39);
      points.emplace_back(13, 42);
      points.emplace_back(13, 45);
      points.emplace_back(13, 48);
      points.emplace_back(13, 30);
      points.emplace_back(13, 51);
      points.emplace_back(11, 30);
      points.emplace_back(10, 30);
      points.emplace_back(12, 30);
      points.emplace_back(11, 51);
      points.emplace_back(12, 51);
      points.emplace_back(10, 51);


      //set borders
      for (int i = 0; i < 22; i++)
      {
         map[points[i].first][points[i].second] = '#';
      }

   }

   if (locator->getLocationName() == "Americas")
   {
      //americas
      points.emplace_back(16, 42);
      points.emplace_back(16, 75);
      points.emplace_back(16, 45);
      points.emplace_back(16, 48);
      points.emplace_back(16, 51);
      points.emplace_back(16, 54);
      points.emplace_back(16, 57);
      points.emplace_back(16, 60);
      points.emplace_back(16, 63);
      points.emplace_back(16, 66);
      points.emplace_back(16, 69);
      points.emplace_back(16, 72);
      points.emplace_back(20, 42);
      points.emplace_back(20, 75);
      points.emplace_back(20, 45);
      points.emplace_back(20, 48);
      points.emplace_back(20, 51);
      points.emplace_back(20, 54);
      points.emplace_back(20, 57);
      points.emplace_back(20, 60);
      points.emplace_back(20, 63);
      points.emplace_back(20, 66);
      points.emplace_back(20, 69);
      points.emplace_back(20, 72);
      points.emplace_back(17, 42);
      points.emplace_back(18, 42);
      points.emplace_back(19, 42);
      points.emplace_back(17, 75);
      points.emplace_back(18, 75);
      points.emplace_back(19, 75);

      //set borders
      for (int i = 0; i < 29; i++)
      {
         map[points[i].first][points[i].second] = '#';
      }
   }

   if (locator->getLocationName() == "Champion's League")
   {
      //champs
      points.emplace_back(9, 63);
      points.emplace_back(9, 66);
      points.emplace_back(9, 69);
      points.emplace_back(9, 72);
      points.emplace_back(9, 75);
      points.emplace_back(9, 78);
      points.emplace_back(9, 81);
      points.emplace_back(9, 84);
      points.emplace_back(13, 87);
      points.emplace_back(13, 63);
      points.emplace_back(13, 66);
      points.emplace_back(13, 69);
      points.emplace_back(13, 72);
      points.emplace_back(13, 75);
      points.emplace_back(13, 78);
      points.emplace_back(13, 81);
      points.emplace_back(13, 84);
      points.emplace_back(10, 60);
      points.emplace_back(11, 60);
      points.emplace_back(13, 60);
      points.emplace_back(9, 60);
      points.emplace_back(9, 87);
      points.emplace_back(10, 87);
      points.emplace_back(11, 87);
      points.emplace_back(12, 60);
      points.emplace_back(12, 87);

      //set borders
      for (int i = 0; i < 25; i++)
      {
         map[points[i].first][points[i].second] = '#';
      }
   }

   if (locator->getLocationName() == "East Shop")
   {
      //shop right
      points.emplace_back(6, 60);
      points.emplace_back(2, 60);
      points.emplace_back(6, 81);
      points.emplace_back(2, 81);
      points.emplace_back(2, 63);
      points.emplace_back(2, 66);
      points.emplace_back(2, 69);
      points.emplace_back(2, 72);
      points.emplace_back(2, 75);
      points.emplace_back(2, 78);
      points.emplace_back(3, 60);
      points.emplace_back(3, 81);
      points.emplace_back(4, 60);
      points.emplace_back(4, 81);
      points.emplace_back(5, 60);
      points.emplace_back(5, 81);
      points.emplace_back(6, 63);
      points.emplace_back(6, 66);
      points.emplace_back(6, 69);
      points.emplace_back(6, 72);
      points.emplace_back(6, 75);
      points.emplace_back(6, 78);

      //set borders
      for (int i = 0; i < 22; i++)
      {
         map[points[i].first][points[i].second] = '#';
      }
   }



   //print labels

   map[18][9] = 'S';
   map[18][12] = 'H';
   map[18][15] = 'O';
   map[18][18] = 'P';

   map[11][36] = 'S';
   map[11][39] = 'H';
   map[11][42] = 'O';
   map[11][45] = 'P';

   map[4][66] = 'S';
   map[4][69] = 'H';
   map[4][72] = 'O';
   map[4][75] = 'P';

   map[18][48] = 'A';
   map[18][51] = 'M';
   map[18][54] = 'E';
   map[18][57] = 'R';
   map[18][60] = 'I';
   map[18][63] = 'C';
   map[18][66] = 'A';
   map[18][69] = 'S';

   map[11][66] = 'C';
   map[11][69] = 'H';
   map[11][72] = 'A';
   map[11][75] = 'M';
   map[11][78] = 'P';
   map[11][81] = 'S';

   map[10][9] = 'E';
   map[10][12] = 'U';
   map[10][15] = 'R';
   map[10][18] = 'O';

   map[3][33] = 'A';
   map[3][36] = 'S';
   map[3][39] = 'I';
   map[3][42] = 'A';








   //print map
   for (int i = 0; i < xSize; i++)
   {
      std::cout << std::endl;
      for (int c = 0; c < ySize; c++)
         std::cout << map[i][c];
   }
   std::cout << std::endl;
}
/*******************************************************************************
**  Function executes attack and defend, randomly deciding who attacks first
*******************************************************************************/
/*void Game::destroyTeam(std::queue<Fighter *>*& team)
{
   while (!team.empty())
   {
      delete team.front();
      team.pop();
   }
}*/
/*******************************************************************************
**  Function executes attack and defend, randomly deciding who attacks first
*******************************************************************************/
Game::~Game()
{
   // destroy2dArray(map, xSize);
   //remove front node until the list is empty
   while (!userTeam.empty())
   {
      delete userTeam.front();
      userTeam.pop();
   }

   delete mercenaryShop;
   delete mercenaryShopLeft;
   delete mercenaryShopRight;
   delete asiaTrain;
   delete americasTrain;
   delete europeTrain;
   delete champLeague;

}
