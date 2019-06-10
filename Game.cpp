/*******************************************************************************
** Program:       Rise -- Final Project
** Author:        David Vega
** Date:          6/3/19
** Description:   This is the Game class responsible for grouping all of the
**                game's functions and making them interact.
*******************************************************************************/

#include "Game.hpp"

/*******************************************************************************
**  Default constructor
*******************************************************************************/
Game::Game()
{
   setSpaces();
   locator = mercenaryShop;
   items.keys = 0;
   items.visa = 0;
   items.cash = 0;
}
/*******************************************************************************
**  Randomly charges an entry fee
*******************************************************************************/
bool Game::payEntry(int &cBal)
{
   int manager = rand() % 3 + 1;
   bool paid = false;
   int payDude;
   if (manager == 1)
   {
      int fee = rand() % 50000 + 1;
      clearScreen(50);
      std::cout << "You must pay a bribe of $" << fee
                << " dollars to enter this region"
                << std::endl;
      if (cBal < fee)
      {
         std::cout << "You dont have enough cash" << std::endl;
      }
      else
      {
         std::cout << "Enter [p] to pay or [r] refuse" << std::endl;
         payDude = getch("pr");
         if (payDude == 'p')
         {
            cBal -= fee;
            paid = true;
            std::cout << "Bribe paid. Thank you" << std::endl;
         }
      }
   }
   else
   {
      paid = true;
   }
   return paid;
}
/*******************************************************************************
**  Sets the game's spaces and links them with four pointers
*******************************************************************************/
void Game::setSpaces()
{
   //6 spaces, three derived (MercenaryShop, Champions, WarZone)
   mercenaryShop = new MercenaryShop;
   west = new WarZone;
   east = new WarZone;
   asiaTrain = new WarZone;
   americasTrain = new WarZone;
   europeTrain = new WarZone;
   champLeague = new Champions;
   enemyTeam = new WarZone;

   //set top, left, right, bottom pointers for all spaces
   mercenaryShop->setBottom(americasTrain); //mercenaryShop Space
   mercenaryShop->setTop(asiaTrain);
   mercenaryShop->setLeft(europeTrain);
   mercenaryShop->setRight(champLeague);
   mercenaryShop->setLocName("War Shop");
   west->setTop(europeTrain);               //west
   west->setRight(americasTrain);
   west->setLocName("West World");
   east->setLeft(asiaTrain);                //east
   east->setBottom(champLeague);
   east->setLocName("East World");
   asiaTrain->setBottom(mercenaryShop);     //asia
   asiaTrain->setLeft(europeTrain);
   asiaTrain->setRight(east);
   asiaTrain->setLocName("Asia");
   asiaTrain->setVisa(1);
   americasTrain->setBottom(west);          //americas
   americasTrain->setTop(mercenaryShop);
   americasTrain->setRight(champLeague);
   americasTrain->setLeft(west);
   americasTrain->setLocName("Americas");
   europeTrain->setBottom(west);            //europe
   europeTrain->setTop(asiaTrain);
   europeTrain->setRight(mercenaryShop);
   europeTrain->setLeft(west);
   europeTrain->setLocName("Europe");
   champLeague->setBottom(americasTrain);   //champion's league
   champLeague->setTop(east);
   champLeague->setRight(east);
   champLeague->setLeft(mercenaryShop);
   champLeague->setLocName("Champion's League");

}
/*******************************************************************************
**  Prints game data and navigation keys
*******************************************************************************/
void Game::moveMenu()
{
   std::cout << "You're currently in "
             << locator->getLocationName()
             << "\nKey's in territory: "
             << locator->getKey()
             << "\nVisa in territory: "
             << locator->getVisa()
             << "\n---------------------------------"
             << "\nBackpack items"
             << "\nCash: $" << items.cash
             << "\nKeys: " << items.keys
             << "\nVisa: " << items.visa
             << "\nTeam size: " << userTeam.size() << " warriors"
             << "\n---------------------------------"
             << "\n\nExploration keys"
             << "\n[w] Move Up [s] Move Down [a] Move Left [d] Move Right"
             << "\n\nEntry and Exit keys"
             << "\n[e] Enter space [q] Quit"
             << std::endl;
}
/*******************************************************************************
**  Moves the locator pointer to new spaces based on user selection
*******************************************************************************/
void Game::move(int &exit, int &enter)
{
   int choice;

   moveMenu();
   choice = getch("wasdeq");
   if (choice == 'w') //move up
   {
      if (locator->getTop() != nullptr)
      {
         locator = locator->getTop();
         items.cash -= 1000;
      }
   }
   else if (choice == 's') //move down
   {
      if (locator->getBottom() != nullptr)
      {
         locator = locator->getBottom();
         items.cash -= 1000;
      }
   }
   else if (choice == 'a') //move left
   {
      if (locator->getLeft() != nullptr)
      {
         locator = locator->getLeft();
         items.cash -= 1000;

      }
   }
   else if (choice == 'd') //move right
   {
      if (locator->getRight() != nullptr)
      {
         locator = locator->getRight();
         items.cash -= 1000;
      }
   }
   else if (choice == 'e') //enter a space
   {
      enter = 1;
   }
   else if (choice == 'q') //quit game
   {
      exit = 2;
   }

}

/*******************************************************************************
**  Used in mercenaryShop space to create a marketplace to purchase fighters
*******************************************************************************/
void Game::mShop()
{
   int answer, quantity, cost;
   do
   {
      clearScreen(50);
      std::cout << "Cash Balance: $" << items.cash
                << "\nKeys: " << items.keys
                << "\nTeam size: " << userTeam.size() << " warriors"
                << "\n\n\nWelcome to the Mercenary Shop"
                << "\n\nPlease select the fighter you want to hire"
                << "\n1. GRU Spetsnaz Soldier $10,000"
                << "\n2. Chinese Special Operative $20,000"
                << "\n3. SAS operative $ 50,000"
                << "\n4. Navy Seal $100,000"
                << "\n5. Leave War Shop"
                << std::endl;
      answer = maxMinIntOnly(1, 5);

      if (answer != 5)
      {
         int prices[4] = {10000, 20000, 50000, 100000};
         std::cout << "How many would you like to hire? ";
         quantity = maxMinIntOnly(1, 100);
         if (items.cash >= prices[answer - 1] * quantity)
         {
            items.cash -= prices[answer - 1] * quantity;
            for (int i = 0; i < quantity; i++)
            {
               userTeam.push(locator->buyFighter(answer, cost));
            }
         }
         else
         {
            std::cout << "You can't afford that"
                      << "\nEnter [c] to continue";
            getch("c");
         }
      }
   }
   while (answer != 5);
}
/*******************************************************************************
**  This function is activated when a user chooses to enter all spaces
**  except the mercenaryShop. User can fight or buy a visa.  User loses or
**  makes money when they lose or win. If user see's the army they are facing
**  is too strong, they can choose to pay the army for safe passage instead of
**  fighting them. The cost will be random.
*******************************************************************************/
void Game::warSpace()
{
   int bribe = rand() % 100000 + 1;
   int choice, buy = 0;
   std::cout << "\nA team of " << enemyFighters->size() << " warriors "
             << std::endl;
   printTeam(*enemyFighters);
   std::cout << "\n-------awaits-----------------------------------------------"
             << "\n\nYour team of " << userTeam.size() << " warriors"
             << std::endl;
   printTeam(userTeam);

   if (locator->getVisa() == 1)
   {
      std::cout << "\n\nIf your here to buy a visa then there will be peace"
                << "\nIf not, you better be ready to fight!"
                << "\nEnter [b] to buy key or [s] for something else "
                << std::endl << std::endl;
      buy = getch("bs");
      if (buy == 'b')
      {
         std::cout << "You purchase a visa for $" << rand() % 50000
                   << " dollars"
                   << std::endl;
         items.visa++;
         locator->setVisa(0);
      }
   }
   if (buy != 'b')
   {
      std::cout << "\n\nWhat will it be? Fight or Flight?"
                << "\nThey demand a payment of "
                << bribe
                << " to pass without fighting"
                << "\n[p] Pay fee"
                << "\n[f] Fight"
                << std::endl;
      choice = getch("pf");
      if (choice == 'p')
      {
         items.cash -= bribe;
      }
      else
      {
         //training only for cash. Dont fight to kill. Make copy of userTeam;
         clearScreen(60);
         fight(userTeam, *enemyFighters);
      }
   }

}
/*******************************************************************************
**  Initiates the game into a while loop that wont stop until either the
**  player wins, loses or quits.
*******************************************************************************/
void Game::play()
{
   items.cash = 600000;
   int choice = 1, enterRoom = 0;
   do
   {
      if (locator->getLocationName() == "War Shop" && enterRoom == 1)
      {
         clearScreen(60);
         enterRoom = 0;
         mShop();
      }
      else if (locator->getLocationName() == "Champion's League" && enterRoom
         == 1)
      {
         clearScreen(50);
         if (items.keys == 5 && !userTeam.empty())
         {
            clearScreen(60);
            champLeague->destroyTeam();
            enterRoom = 0;
            champLeague->buildTeam(userTeam.size());
            enemyFighters = champLeague->getTeam();
            warSpace();
            std::cout << "Enter [c] to continue";
            getch("cC");
         }
         else
         {
            std::cout << "You're not powerful enough to fight the champion"
                      << "\nYou must have 5 keys to enter and at least 1 "
                         "warrior"
                      << "\nEnter [c] to continue"
                      << std::endl;
            getch("cC");
            enterRoom = 0;
         }
      }

      else if (locator->getLocationName() != "War Shop" &&
         locator->getLocationName() != "Champion's League" &&
         enterRoom == 1)
      {
         clearScreen(60);
         bool bribeOfficer = payEntry(items.cash);
         if (!userTeam.empty() && bribeOfficer)
         {
            if ((locator->getLocationName() == "Europe" ||
               locator->getLocationName() == "West World") && items.visa == 1)
            {
               enemyTeam->destroyTeam();
               enterRoom = 0;
               enemyTeam->buildTeam(userTeam.size());
               enemyFighters = enemyTeam->getTeam();
               warSpace();
               std::cout << "Enter [c] to continue";
               getch("cC");
               enterRoom = 0;
            }
            else if (locator->getLocationName() == "East World" ||
               locator->getLocationName() == "Americas" ||
               locator->getLocationName() == "Asia")
            {
               enemyTeam->destroyTeam();
               enterRoom = 0;
               enemyTeam->buildTeam(userTeam.size());
               enemyFighters = enemyTeam->getTeam();
               warSpace();
               std::cout << "Enter [c] to continue";
               getch("cC");
               enterRoom = 0;
            }
            else
            {
               std::cout << "You need a visa to enter this territory!"
                         << "\nExplore the territories until you find one that"
                         << " can provide you with a visa" << std::endl;
               int fine = rand() % 100000 + 1;
               std::cout << "You've been fined $" << fine
                         << " for trying to enter this territory illegaly"
                         << std::endl;
               items.cash -= fine;
               std::cout << "Enter [c] to continue";
               getch("cC");
               enterRoom = 0;
            }
         }
         else
         {
            clearScreen(60);
            std::cout << "Make sure you have at least 1 warrior and that you "
                         "pay bribes to enter territory" << std::endl;
            std::cout << "Enter [c] to continue";
            getch("cC");
            enterRoom = 0;
         }
      }

      if (choice == 1)
      {
         clearScreen(60);
         printMap();
         move(choice, enterRoom);
      }
      if (items.cash <= 0 || (items.cash < 10000 && userTeam.empty()))
      {
         clearScreen(60);
         for (int i = 0; i < 25; i++)
         {
            std::cout << "You ran out of money. GAME OVER." << std::endl;
         }
         choice = 2;
      }
      if (items.keys == 6)
      {
         clearScreen(50);
         printCup();
         for (int i = 0; i < 10; i++)
         {
            std::cout << "CONGRATULATIONS!!! You are the new world champion"
                      << std::endl;
         }
         choice = 2;
      }
   }
   while (choice != 2);
}

/*******************************************************************************
**  Function to randomly decide which fighter will strike first
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
**  Function initiates fight sequence between two fighters in army. While
**  loop exits when one of the armies is out of fighters.
*******************************************************************************/
void Game::fight(std::queue<Fighter *> &uTeam, std::queue<Fighter *> enemy)
{
   clearScreen(50);
   int battle = 1, t1Points = 0, t2Points = 0, rounds = 0;
   int money = 0;
   int bonus = 0;

   std::cout << "\nEnemy Team Size: " << enemy.size() << std::endl;
   std::cout << "Your Team Size: " << userTeam.size() << std::endl;
   std::cout << "------------------------------------------------------------"
                "-------------------"
             << std::endl;
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

                   << "\n------------------------------------------------------"
                      "-------------------------"
                   << std::endl;

         delete uTeam.front();//activate if you want to fight to death
         uTeam.pop(); //loser is removed from team1 stack
         t2Points++; //point added to team2
         battle++;//increment total battles
         rounds = 0;//reset rounds
         money -= 3000;
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
         std::cout
            << "------------------------------------------------------------"
               "-------------------"
            << std::endl;
         uTeam.front()->harden();
         Fighter *fighterBack = uTeam.front();
         uTeam.push(fighterBack);
         uTeam.pop();
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
            std::cout << "\nYou and Enemy team Tie! " << t2Points
                      << " to "
                      << t1Points << std::endl << std::endl;
         }
            //team B wins
         else if (t2Points > t1Points)
         {
            std::cout << "\nEnemy Wins " << t2Points << " to " << t1Points
                      << std::endl << std::endl;
            //enemy took a key from you
            if (items.keys >= 1 && locator->getLocationName() != "Champion's "
                                                                 "League")
            {
               std::cout << "Enemy has taken one of your keys" << std::endl;
               items.keys--;
               //enemy takes key
               locator->setKey(1);
            }

         }
            //team A wins
         else if (t1Points > t2Points)
         {
            std::cout << "\nYou Win " << t1Points << " to " << t2Points
                      << std::endl << std::endl;
            if (locator->getKey() >= 1)
            {
               bonus = rand() % 100000 + 1;
               items.cash += bonus;
               std::cout << "You took a key, $"
                         << money << " dollars in fight pay, and "
                         << bonus << " dollars from the enemy's coffers!"
                         << std::endl;
               items.keys++;
               //take key from enemy
               locator->setKey(-1);
            }

            else
            {
               std::cout << "You already took the key from this zone"
                         << std::endl;
            }
         }
      }
   }
   while (!(uTeam.empty() || enemy.empty())); //kill loop if team empty
   std::cout << "Cash Balance: " << items.cash;
   items.cash += (money + bonus);
   std::cout << "\nYou earned: " << money + bonus
             << "\nNew Cash Balance: "
             << items.cash
             << std::endl;
   std::cout << "\nEnemy Team Size: " << enemy.size()
             << "\nYour Team Size: " << userTeam.size() << std::endl;
   //printTeam(userTeam);

}
/*******************************************************************************
**  prints all the fighters in an army
*******************************************************************************/
void Game::printTeam(std::queue<Fighter *> q)
{
   int count = 0;
   std::queue<Fighter *> q2;
   q2 = q;
   while (!q.empty())
   {
      count++;
      std::cout << q.front()->getName() << " ";
      q.pop();

      //print no more than 20 numbers per line
      if (count % 5 == 0)
      {
         std::cout << std::endl;
      }
   }
   std::cout << std::endl;
}
/*******************************************************************************
**  Prints a trophy and a "you win" message when the user wins
*******************************************************************************/
void Game::printCup()
{
   int count = 0;
   char map[24][90];

   //set the white spaces
   for (int x = 0; x < 24; x++)
   {
      for (int y = 0; y < 90; y++)
      {
         map[x][y] = ' ';
      }
      count++;
   }
   std::vector<std::pair<int, int>> points;
   points.emplace_back(1, 12);//Y
   points.emplace_back(1, 18);
   points.emplace_back(2, 15);
   points.emplace_back(3, 15);
   points.emplace_back(4, 15);
   points.emplace_back(1, 21);//O
   points.emplace_back(1, 24);
   points.emplace_back(1, 27);
   points.emplace_back(2, 21);
   points.emplace_back(2, 27);
   points.emplace_back(3, 21);
   points.emplace_back(3, 27);
   points.emplace_back(4, 21);
   points.emplace_back(4, 24);
   points.emplace_back(4, 27);
   points.emplace_back(1, 30);//U
   points.emplace_back(2, 30);
   points.emplace_back(3, 30);
   points.emplace_back(4, 30);
   points.emplace_back(4, 33);
   points.emplace_back(4, 36);
   points.emplace_back(1, 36);
   points.emplace_back(2, 36);
   points.emplace_back(3, 36);
   points.emplace_back(1, 54);//W
   points.emplace_back(2, 54);
   points.emplace_back(3, 54);
   points.emplace_back(4, 54);
   points.emplace_back(3, 57);
   points.emplace_back(2, 60);
   points.emplace_back(3, 63);
   points.emplace_back(4, 66);
   points.emplace_back(1, 66);
   points.emplace_back(2, 66);
   points.emplace_back(3, 66);
   points.emplace_back(1, 69);//I
   points.emplace_back(2, 69);
   points.emplace_back(3, 69);
   points.emplace_back(4, 69);
   points.emplace_back(1, 72);//N
   points.emplace_back(2, 72);
   points.emplace_back(3, 72);
   points.emplace_back(4, 72);
   points.emplace_back(2, 75);
   points.emplace_back(3, 78);
   points.emplace_back(4, 81);
   points.emplace_back(3, 81);
   points.emplace_back(2, 81);
   points.emplace_back(1, 81);
   points.emplace_back(6, 33);//champions cup
   points.emplace_back(6, 36);
   points.emplace_back(6, 39);
   points.emplace_back(6, 42);
   points.emplace_back(6, 45);
   points.emplace_back(6, 48);
   points.emplace_back(6, 51);
   points.emplace_back(6, 54);
   points.emplace_back(6, 57);
   points.emplace_back(7, 33);
   points.emplace_back(8, 33);
   points.emplace_back(9, 33);
   points.emplace_back(10, 33);
   points.emplace_back(7, 57);
   points.emplace_back(8, 57);
   points.emplace_back(9, 57);
   points.emplace_back(10, 57);
   points.emplace_back(11, 36);
   points.emplace_back(12, 39);
   points.emplace_back(13, 42);
   points.emplace_back(11, 54);
   points.emplace_back(12, 51);
   points.emplace_back(13, 48);
   points.emplace_back(14, 48);
   points.emplace_back(15, 48);
   points.emplace_back(16, 48);
   points.emplace_back(17, 48);
   points.emplace_back(18, 48);
   points.emplace_back(14, 42);
   points.emplace_back(15, 42);
   points.emplace_back(16, 42);
   points.emplace_back(17, 42);
   points.emplace_back(18, 42);
   points.emplace_back(18, 39);
   points.emplace_back(18, 36);
   points.emplace_back(19, 36);
   points.emplace_back(18, 51);
   points.emplace_back(18, 54);
   points.emplace_back(19, 54);
   points.emplace_back(19, 39);
   points.emplace_back(19, 42);
   points.emplace_back(19, 45);
   points.emplace_back(19, 48);
   points.emplace_back(19, 51);

   //set borders
   for (unsigned int i = 0; i < points.size(); i++)
   {
      map[points[i].first][points[i].second] = '#';
   }


   //print map
   for (int i = 0; i < 24; i++)
   {
      std::cout << std::endl;
      for (int c = 0; c < 90; c++)
         std::cout << map[i][c];
   }
   std::cout << std::endl;

}
/*******************************************************************************
**  Prints the map for the user to see and navigate in linked spaces
*******************************************************************************/
void Game::printMap()
{
   int count = 0;
   char map[24][90];

   //set the white spaces
   for (int x = 0; x < 24; x++)
   {
      for (int y = 0; y < 90; y++)
      {
         map[x][y] = ' ';
      }
      count++;
   }

   std::vector<std::pair<int, int>> points;
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

   if (locator->getLocationName() == "West World")
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

   if (locator->getLocationName() == "War Shop")
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

   if (locator->getLocationName() == "East World")
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
   map[18][9] = 'W';
   map[18][12] = 'E';
   map[18][15] = 'S';
   map[18][18] = 'T';

   map[11][36] = 'S';
   map[11][39] = 'H';
   map[11][42] = 'O';
   map[11][45] = 'P';

   map[4][66] = 'E';
   map[4][69] = 'A';
   map[4][72] = 'S';
   map[4][75] = 'T';

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
   for (int i = 0; i < 24; i++)
   {
      std::cout << std::endl;
      for (int c = 0; c < 90; c++)
         std::cout << map[i][c];
   }
   std::cout << std::endl;
}

/*******************************************************************************
**  Default destuctor empties user army and deletes all memory allocated for
**  the 6 spaces
*******************************************************************************/
Game::~Game()
{
   //remove front node until the list is empty
   while (!userTeam.empty())
   {
      delete userTeam.front();
      userTeam.pop();
   }

   delete mercenaryShop;
   delete west;
   delete east;
   delete asiaTrain;
   delete americasTrain;
   delete europeTrain;
   delete champLeague;
   delete enemyTeam;

}



