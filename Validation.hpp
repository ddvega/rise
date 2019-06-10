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
void clearScreen(int);
int getch(std::string);
#endif
