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
*                 validates input by forcing user to enter integers between a
*                 certain range
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
*                Validates input that only digits are used, including '-' when i
 *               = 0
*******************************************************************************/
bool digitOnly(std::string a)
{
   for (unsigned int i = 0; i < a.length(); i++)
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
*              This function asks the user to proceed or quit and validates that
               only those two options are selected. //https://www.geeksforgeeks
               .org/exit-vs-_exit-c-cpp/
*******************************************************************************/
void startOrQuit()
{
   int answer;
   std::cout << std::endl;
   std::cout << "1. Play game" << std::endl;
   std::cout << "2. Exit game" << std::endl;
   answer = maxMinIntOnly(1, 2);

   if (answer == 2)
   {
      std::cout << std::endl;
      int exit_code = 1;
      std::cout << "Thank's for your time. Goodbye." << std::endl;
      std::cout << std::endl;
      _Exit(exit_code);
   }
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
**  This function validates that digits and special characters are not used.
*******************************************************************************/
bool charOnly(std::string a)
{
   char banned[11] = {'.', '/', '$', '/', '@', '!', '&', '*', '%',
                      ';', '^'};
   if (a.length() > 30)
   {
      std::cout << "Keep it to 30 characters or less. Try again: ";
      return true;
   }
   for (unsigned int i = 0; i < a.length(); i++)
   {
      for (int j = 0; j < 11; j++)
      {
         if (isdigit(a[i]) || a[i] == banned[j])
         {
            std::cout << "no digits or special characters. Try again: ";
            return true;
         }
      }
   }
   return false;
}

/*******************************************************************************
**  This function validates input by ensuring that words are entered
*******************************************************************************/
std::string wordOnly()
{
   bool error = false;
   std::string target;

   std::cout << "-> ";
   std::getline(std::cin, target);
   error = charOnly(target);

   while (error || target == "")
   {
      std::cout << "Error! try again -> ";
      std::getline(std::cin, target);
      error = charOnly(target);
   }
   return target;
}

/*******************************************************************************
**  This function validates input by ensuring that words are entered
*******************************************************************************/
std::string wordOrDigit()
{
   std::string target;
   std::cout << "Enter Character Name: ";
   std::getline(std::cin, target);

   while (target.length() < 1 || target.length() > 20)
   {
      std::cout << "Enter name between 1 and 20 characters: ";
      std::getline(std::cin, target);
   }

   return target;
}
/*******************************************************************************
**  This function deallocates memory by destroying the 2d array. The
**  following resource was used: https://thispointer.com/allocating-and
**  -deallocating-2d-arrays-dynamically-in-c-and-c/
*******************************************************************************/
void destroy2dArray(char **ptr, int size)
{
   for (int i = 0; i < size; i++)
      delete[] ptr[i];
   delete[] ptr;
}
/*******************************************************************************
**  This function deallocates memory by destroying the 2d array. The
**
*******************************************************************************/
int getch(std::string rules)
{
   struct termios oldt, newt;
   int ch;
   bool present = false;

   do
   {
      tcgetattr(STDIN_FILENO, &oldt);
      newt = oldt;
      newt.c_lflag &= ~(ICANON | ECHO);
      tcsetattr(STDIN_FILENO, TCSANOW, &newt);
      ch = getchar();
      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

      for (int i = 0; i < rules.length(); i++)
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