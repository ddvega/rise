/*******************************************************************************
** Program:       Rise Project 4
** Author:        David Vega
** Date:          6/3/19
** Description:   Validation functions used to validate integers, doubles and
                  strings in various parts of the program
*******************************************************************************/
//validation.hpp

#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <termios.h>
#include <unistd.h>

int maxMinIntOnly(int, int);
bool digitOnly(std::string);
void startOrQuit();
void clearScreen(int);
void charOnly();
std::string wordOnly();
std::string wordOrDigit();
void destroy2dArray(char **ptr, int size);
int getch(std::string);
#endif
