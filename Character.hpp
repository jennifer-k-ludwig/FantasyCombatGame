/***************************************************************
 * Name: Jennifer Ludwig
 * Date: 02/03/2019
 * Description: Header file for Character class.
***************************************************************/
#include <string>

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character
{
	protected:
		int attackRoll,
			defenseRoll,
			armor,
			strengthPoints;
		std::string type, attackDieType, defenseDieType;
	public:
		//Constructor
		Character();
		//Destructor
		virtual ~Character();
		//Setters
		void setAttackRoll(int);
		void setDefenseRoll(int);
		void setArmor(int);
		void setStrengthPoints(int);
		void setType(std::string);
		void setAttackDieType(std::string);
		void setDefenseDieType(std::string);
		//Getters
		int getAttackRoll();
		int getDefenseRoll();
		int getArmor();
		int getStrengthPoints();
		std::string getType();
		std::string getAttackDieType();
		std::string getDefenseDieType();
		//Methods
		virtual int attack()= 0;
		virtual int defense(int)= 0;
		int random(int, int);
		int rollDie(int, int);
};

#endif
