#include <iostream>
#include <random>
#include <ctime>
#include "idle_clicker_helper.h"
void calculator()
{
	int numberOne = 0;
	int numberTwo = 0;
	char operation = 0;

	int result;

	std::cout << "enter first number: ";
	std::cin >> numberOne;

	std::cout << "enter second number: ";
	std::cin >> numberTwo;

	std::cout << "enter operation you would like to do: ";
	std::cin >> operation;

	
	switch (operation)
	{
	case '+':
	{
		result = numberOne + numberTwo;
		std::cout << "answer: " << result << std::endl;
		//do something
		break;
	}
	case '-':
	{
		result = numberOne - numberTwo;
		std::cout << "answer: " << result << std::endl;
		//do something
		break;
	}
	default:
	{
		//Tell user it is a invalid operation
	}
	}
	system("pause");
}

	//calculator


	//Knight one : Francis
	int knightOneHealth = 1000;
	int knightOneDamage = 15;


	bool hasShownWinner = false;
	bool keepRunning = true;
	

	//Knight Two : Peter
	int knightTwoHealth = 1000;
	int knightTwoDamage = 15;


	void draw()
	{
		if(knightOneHealth > 0 && knightTwoHealth > 0)
		{
			system("cls");
			std::cout << "your Health " << knightOneHealth << std::endl;
		}
	

		else if (knightTwoHealth <= 0 && hasShownWinner == false)
		{
			std::cout << "Player One Win's!!" << std::endl;
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
	if (c == 'q')
	{
		std::cout << "should quit" << std::endl;
		keepRunning = false;
	}

	if (c == 'a')
	{
		std::cout << "Player One has taken damamage" << std::endl;
		knightOneHealth = doAttack(knightOneHealth, knightTwoDamage, 1);
	}
	draw();
	if (c == 'l')
	{
		std::cout << "Player Two Has Taken Damage" << std::endl;
		knightTwoHealth = doAttack(knightTwoHealth, knightOneDamage, 1);
	}
	draw();
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