/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 02/03/2019
 * Description: Main file for Fantasy Combat Game.
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

int main()
{
	do
	{
		clearScreen();
		srand( time(NULL) );

		Character *player1 = nullptr;
		Character *player2 = nullptr;
		std::string 
			selection1, 
			prompt1  = "Player 1: ", 
			selection2, 
			prompt2 = "Player 2: ";

		std::cout << ":: Fantasy Combat Game ::\n";
		std::cout << "Choose two characters from the list below (by number).\n";
		std::cout << "1. Vampire\n";
		std::cout << "2. Barbarian\n";
		std::cout << "3. Blue Men\n";
		std::cout << "4. Medusa\n";
		std::cout << "5. Harry Potter\n\n";
	
		assignCharPointer(prompt1, selection1, player1);
		assignCharPointer(prompt2, selection2, player2);

		int round = 0;
	
		do
		{
	//		clearScreen();
			std::cout << "Round " << ++round << std::endl;
	
			randomOrder(player1, player2);
	
			std::cout << "Press enter to continue..." << std::endl;
			std::cin.ignore();
		
		} while (charactersAlive(player1, player2));

		delete player1;
		player1 = nullptr;

		delete player2;
		player2 = nullptr;

	} while (keepPlaying());
	
	return 0;
}



