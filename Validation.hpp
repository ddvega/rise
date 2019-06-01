/*******************************************************************************
** Program:       Fantasy Combat Tournament Project 4
** Author:        David Vega
** Date:          5/15/19
** Description:   Validation functions used to validate integers, doubles and
                  strings in various parts of the program
*******************************************************************************/
//validation.hpp

#ifndef VALIDATION_HPP
#define VALIDATION_HPP

#include <iostream>
#include <string>
#include <fstream>

int maxMinIntOnly(int, int);
bool digitOnly(std::string);
void startOrQuit();
void clearScreen(int);
void charOnly();
std::string wordOnly();
std::string wordOrDigit();
void destroy2dArray(char **ptr, int size);
#endif