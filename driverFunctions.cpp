/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 02/03/2019
 * Description: Implementation file for driver functions.
***************************************************************/
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "driverFunctions.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>
#include <algorithm>

/***************************************************************
 * Function Name: void playerAttack 
 * Parameters: Character *&attacker, Character *&defender
 * Description: Carrys out one attack. 
***************************************************************/

void playerAttack(Character *&attacker, Character *&defender)
{
	int damage = defender->defense(attacker->attack());
	int newSP = defender->getStrengthPoints() - damage;

	printDetails(attacker, defender, damage, newSP);

	defender->setStrengthPoints(newSP);
}


/***************************************************************
 * Function Name: bool charactersAlive 
 * Parameters: Character *&p1, Character *&p2
 * Description: Checks if both characters are alive. If so, 
 * 		returns true, if not, returns false. 
***************************************************************/

bool charactersAlive(Character *&p1, Character *&p2)
{
	if (p1->getStrengthPoints() > 0 && p2->getStrengthPoints() > 0)
		return true;
	else
	{
		if (p1->getStrengthPoints() < 1)
			std::cout << p1->getType() << " is dead.\n\n";
		else if (p2->getStrengthPoints() < 1)
			std::cout << p2->getType() << " is dead.\n\n";
		return false;
	}
}
/***************************************************************
 * Function Name: void printDetails 
 * Parameters: Character *&attacker, Character *&defender, int damage, int newSP
 * Description: Prints details for each attack.
***************************************************************/

void printDetails(Character *&attacker, Character *&defender, int damage, int newSP)
{
	std::cout << "Attacker type: " << attacker->getType() << std::endl;
	std::cout << "Dice roll (" << attacker->getAttackDieType() << "): " << attacker->getAttackRoll() << std::endl;
	std::cout << std::endl;
	
	std::cout << "Defender type: " << defender->getType() << std::endl;
	std::cout << "Dice roll (" << defender->getDefenseDieType() << "): " << defender->getDefenseRoll() << std::endl;
	std::cout << "Armor: " << defender->getArmor() << std::endl;
	std::cout << "Damage: " << damage << std::endl;
	std::cout << "Strength points: " << defender->getStrengthPoints() << std::endl;
	std::cout << "New strength points: " << newSP << std::endl;
	std::cout << std::endl;
}

/***************************************************************
 * Function Name: void clearScreen
 * Parameters: None
 * Description: Clears screen by inserting 100 lines.
***************************************************************/

void clearScreen()
{
	std::cout << std::string(100, '\n');
}


/***************************************************************
 * Function Name: void assignCharPointer
 * Parameters: int selection, Character *&pointer
 * Description: Assigns memory location to pointer based on 
 * 		player's selection.
***************************************************************/

void assignCharPointer(std::string prompt, std::string selection, Character *&pointer)
{
	bool choiceInvalid = true;

	while (choiceInvalid)
	{
		std::cout << prompt;
		std::getline(std::cin, selection);

		if (isInteger(selection))
		{
			if (std::stoi(selection) == 1)
			{	pointer = new Vampire; choiceInvalid = false; }
			else if (std::stoi(selection) == 2)
			{	pointer = new Barbarian; choiceInvalid = false; }
			else if (stoi(selection) == 3)
			{	pointer = new BlueMen; choiceInvalid = false; }
			else if (std::stoi(selection) == 4)
			{	pointer = new Medusa; choiceInvalid = false; }
			else if (std::stoi(selection) == 5)
			{	pointer = new HarryPotter; choiceInvalid = false; }			
			else
				std::cout << "Please enter a number from the menu above.\n";	
		}
		else
			std::cout << "Please enter a number from the menu above.\n";	
 	} 
}

/***************************************************************
 * Function Name: bool keepPlaying
 * Parameters: N/A
 * Description: Asks user if they would like to keep playing.
***************************************************************/

bool keepPlaying()
{
	std::string choice;
	bool choiceInvalid = true;

	std::cout << "1. Play again" << std::endl;
	std::cout << "2. Exit the game" << std::endl;

	while (choiceInvalid)
	{
		std::cout << "\nPlease enter a number from the menu above: ";	
		std::getline(std::cin, choice);

		if (isInteger(choice))
		{
			if (std::stoi(choice) == 1)
			{	return true; }
			else if (std::stoi(choice) == 2)
				return false;
			else
				std::cout << "Please enter 1 or 2.\n";
		}
		else
			std::cout << "Please enter 1 or 2.\n";
 	} 

	return false;
}

/***************************************************************
 * Function Name: bool isInteger
 * Parameters: std::string
 * Description: Returns false string is empty, returns true if
 * 		string length is 1 and the first char of string
 * 		is a digit, returns false if first char of 
 * 		string is - and the second char is not a digit,
 * 		and checks if the rest of the string is a digit.
 * Source: Phi Luu
***************************************************************/

bool isInteger(std::string s)
{
	if (s.empty())
		return false;

	if (s.length() == 1 && isdigit(s[0]))
		return true;

	if (s[0] != '-' && !isdigit(s[0]))
		return false;

	return (std::all_of(s.begin() + 1, s.end(), ::isdigit));
}

/***************************************************************
 * Function Name: void randomOrder
 * Parameters: Character *&p1, Character *&p2
 * Description: Orders the attacks randomly. 
***************************************************************/

void randomOrder(Character *&p1, Character *&p2)
{
	int goesFirst = random(1, 2);

	if (goesFirst == 1)
	{
		std::cout << "\n:: Attack #1 ::\n";
		playerAttack(p1, p2);
		std::cout << ":: Attack #2 ::\n";
		playerAttack(p2, p1);
	}
	else if (goesFirst == 2)
	{
		std::cout << "\n:: Attack #1 ::\n";
		playerAttack(p2, p1);
		std::cout << ":: Attack #2 ::\n";
		playerAttack(p1, p2);
	}			
}

/***************************************************************
 * Function Name: int random
 * Parameters: int low, int high
 * Description: Returns random number between low and high.
***************************************************************/

int random(int low, int high)
{
	return low + rand() % ((high + 1) - low);
}
