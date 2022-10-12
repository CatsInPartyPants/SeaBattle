#include "functions.h"
#include <iostream>

void draw_field(char** battlefield)
{
	

	char letters[10]{ 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'K' };
	int numbers[10]{ 1,2,3,4,5,6,7,8,9,0 };

	//print row of letters
	std::cout << "  ";
	for (int i = 0; i < 10; i++)
	{
		std::cout << letters[i] << " ";
	}

	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
	{
		std::cout << numbers[i] << "|";
		for (int j = 0; j < 10; j++)
		{
			std::cout << battlefield[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void main_menu(char **battlefield)
{
	int user_choise_main_menu;
	std::cout << "Game Sea Battle\n\n";

	std::cout << "1. Start game user vs computer." << std::endl;
	std::cout << "2. Start game computer vs computer." << std::endl;
	std::cout << "3. Exit." << std::endl;
	std::cin >> user_choise_main_menu;

	switch (user_choise_main_menu)
	{
	case 1:
		system("CLS");
		user_vs_computer_menu();
		break;
	case 2:
		system("CLS");
		break;
	case 3:
		system("CLS");
		break;
	default:
		break;
	}

}

void user_vs_computer_menu()
{
	int user_choise_user_vs_computer_menu;
	std::cout << "1. Random ship shaffle." << std::endl;
	std::cout << "2. User choose where ships will be stand." << std::endl;
	std::cin >> user_choise_user_vs_computer_menu;
	switch (user_choise_user_vs_computer_menu)
	{
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}
}


char** make_battlefield()
{
	char** battlefield = new char* [10];

	for (int i = 0; i < 10; i++)
	{
		battlefield[i] = new char[10];
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			battlefield[i][j] = '_';
		}
	}
	return battlefield;
}

void delete_battlefield(char** battlefield)
{
	for (int i = 0; i < 10; i++)
	{
		delete battlefield[i];
	}
	delete[] battlefield;
}