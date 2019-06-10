/*******************************************************************************
** Program:       Fantasy Combat Tournament Project 4
** Author:        David Vega
** Date:          5/15/19
** Description:   Validation functions used to validate integers, doubles and
                  strings in various parts of the program
*******************************************************************************/
//validation.cpp

#include "Validation.hpp"

/*******************************************************************************
**  validates input by forcing user to enter integers between a certain range
*******************************************************************************/
int maxMinIntOnly(int min, int max)
{
   bool error;
   std::string targetTemp;
   int intTemp;

   //https://www.systutorials.com/131/convert-string-to-int-and-reverse/
   std::cout << "--> ";
   std::getline(std::cin, targetTemp);
   error = digitOnly(targetTemp);
   intTemp = std::atoi(targetTemp.c_str());
   while (error || intTemp < min || intTemp > max || targetTemp.empty())
   {
      std::cout << "Enter integer between " << min << " and " << max << ": ";
      std::getline(std::cin, targetTemp);
      error = digitOnly(targetTemp);
      intTemp = std::atoi(targetTemp.c_str());
   }
   return intTemp;
}
/*******************************************************************************
**  Validates input that only digits are used, including '-' when i = 0
*******************************************************************************/
bool digitOnly(std::string a)
{
   int size = a.length();
   for ( int i = 0; i < size; i++)
   {
      if (i == 0)
      {
         /*https://www.daniweb.com/programming/software-development/threads/
         383256/using-isdigit-to-validate-user-input-c*/
         if (!(isdigit(a[i])) && a[i] != '-')
         {
            return true;
         }
      }
      else if (!(isdigit(a[i])))
      {
         return true;
      }
   }
   return false;
}
/*******************************************************************************
*              Clears the screen
*******************************************************************************/
void clearScreen(int n)
{
   for (int i = 0; i < n; i++)
   {
      std::cout << std::endl;
   }
}
/*******************************************************************************
**  This function prompts the user to enter a char from a string
*******************************************************************************/
int getch(std::string rules)
{
   //http://www.cplusplus.com/forum/unices/106185/
   struct termios oldt, newt;
   int ch;
   bool present = false;
   int size = rules.length();

   do
   {
      tcgetattr(STDIN_FILENO, &oldt);
      newt = oldt;
      newt.c_lflag &= ~(ICANON | ECHO);
      tcsetattr(STDIN_FILENO, TCSANOW, &newt);
      ch = getchar();
      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

      for (int i = 0; i < size; i++)
      {
         if (rules[i] == ch)
         {
            present = true;
         }
      }
   }
   while (!present);

   return ch;
}