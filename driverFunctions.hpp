/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 02/03/2019
 * Description: Header file for driver functions.
***************************************************************/
#include "Character.hpp"

#include <string>

#ifndef DRIVERFUNCTIONS_HPP
#define DRIVERFUNCTIONS_HPP

void printDetails(Character *&attacker, Character *&defender, int damage, int newSP);
void playerAttack(Character *&attacker, Character *&defender);
bool charactersAlive(Character *&p1, Character *&p2);
void clearScreen();
void assignCharPointer(std::string, std::string, Character *&);
bool keepPlaying();
bool isInteger(std::string);
void randomOrder(Character *&p1, Character *&p2);
int random(int, int);

#endif
