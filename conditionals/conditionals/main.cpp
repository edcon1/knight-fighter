#include <iostream>
#include <random>
#include <ctime>
#include "idle_clicker_helper.h"

//Knight one : Francis
	int knightOneHealth = 1000;
	int knightOneDamage = 15;


	bool hasShownWinner = false;
	bool keepRunning = true;
	

	//Knight Two : Peter
	int knightTwoHealth = 1000;
	int knightTwoDamage = 15;


	void draw(bool attackWhich)
	{
		if(knightOneHealth > 0 && knightTwoHealth > 0)
		{
				system("cls");
				std::cout << "your Health: " << knightOneHealth << std::endl;
				std::cout << "Knight two's Health: " << knightTwoHealth << std::endl;
		}
		

		else if (knightTwoHealth <= 0 && hasShownWinner == false)
		{
			std::cout << "Player One Wins!!" << std::endl; //changed for "win's" to "wins"
			hasShownWinner = true;
		}
	}
	


int doAttack(int currentHealth, int amountOfDamage, int multiplier)
{
	int totalDamage = std::pow(amountOfDamage, multiplier);
	
	int finalHealth = currentHealth - totalDamage;

	return (finalHealth);
}

void handleKey(char c)
{
	bool attackWhichKnight = 0; //added "attackWhichKnight" boolean to tell the program which health to display

	if (c == 'q')
	{
		std::cout << "should quit" << std::endl;
		keepRunning = false;
	}

	if (c == 'a')
	{
		std::cout << "Player One has taken damamage" << std::endl;
		knightOneHealth = doAttack(knightOneHealth, knightTwoDamage, 1);
		attackWhichKnight = true;
		draw(attackWhichKnight); //the boolean gets inserted into the "draw" function
	}
	
	if (c == 'l')
	{
		std::cout << "Player Two Has Taken Damage" << std::endl;
		knightTwoHealth = doAttack(knightTwoHealth, knightOneDamage, 1);
		attackWhichKnight = false;
		draw(attackWhichKnight);
	}

}

int main()
{
	srand((unsigned int)time(nullptr));

	

	AsyncKeyboard::setupKeyboard(handleKey);

	while (keepRunning)
	{

	}

	AsyncKeyboard::shutdown();



	system("pause");
	return 0;
}