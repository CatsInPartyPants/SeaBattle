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
		user_vs_computer_menu(battlefield);
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

void user_vs_computer_menu(char** battlefield)
{
	int user_choise_user_vs_computer_menu;
	std::cout << "1. Random ship shaffle." << std::endl;
	std::cout << "2. User choose where ships will be stand." << std::endl;
	std::cin >> user_choise_user_vs_computer_menu;
	switch (user_choise_user_vs_computer_menu)
	{
	case 1:
		system("CLS");
		computer_places_ships(battlefield);
		break;
	case 2:
		system("CLS");
		user_places_ships(battlefield);
		break;
	default:
		system("CLS");
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

void user_places_ships(char** battlefield)
{
	char row;
	int y, x;
	std::cout << "You can place:\n" << std::endl;
	std::cout << "4 boats (letter B, 1 cell), for example B:\n" << std::endl;
	std::cout << "3 destroyers (letter D, 2 cells), for example DD:\n" << std::endl;
	std::cout << "2 cruisers (letter C, 3 cells), for example CCC:\n" << std::endl;
	std::cout << "1 battleship (letter L, 4 cells), for example LLLL:\n\n" << std::endl;
	draw_field(battlefield);
	
	//placing boats
	for(int i = 4; i > 0; i--)
	{
		std::cout << "First of all, lets put 4 boats on the map, enter row (A,B,C etc.)\n then enter colomn(1,2,3 etc.) "
			<< "where the boat will be placed : \n" << std::endl;
		std::cout << "Boats left: " << i << std::endl;
		std::cin >> row;
		std::cin >> y;
		if (y == 0)
			y = 9;
		else
			y--;
		x = text_to_number(&row);
		if (battlefield[y][x] == '_')
		{
			battlefield[y][x] = 'B';
		}
		system("CLS");
		draw_field(battlefield);
	}

	//placing destroyers
	system("CLS");
	std::cout << "Now you need to place 3 destroyers (destroyers are in 2 cells):" << std::endl;
	draw_field(battlefield);
	for (int i = 6; i > 0; i--)
	{
		std::cout << "Destroyers cells left: " << i << std::endl;
		std::cin >> row;
		std::cin >> y;
		if (y == 0)
			y = 9;
		else
			y--;
		x = text_to_number(&row);
		if (battlefield[y][x] == '_')
		{
			battlefield[y][x] = 'D';
		}
		draw_field(battlefield);
	}

	//placing cruisers
	system("CLS");
	std::cout << "Place 2 cruisers (cruisers are in 3 cells):" << std::endl;
	draw_field(battlefield);
	for (int i = 6; i > 0; i--)
	{
		std::cout << "Cruiser cells left: " << i << std::endl;
		std::cin >> row;
		std::cin >> y;
		if (y == 0)
			y = 9;
		else
			y--;
		x = text_to_number(&row);
		if (battlefield[y][x] == '_')
		{
			battlefield[y][x] = 'C';
		}
		draw_field(battlefield);
	}

	//placing battleship
	system("CLS");
	std::cout << "Place 1 battleship (battleship is in 4 cells):" << std::endl;
	draw_field(battlefield);
	for (int i = 4; i > 0; i--)
	{
		std::cout << "Battleship cells left: " << i << std::endl;
		std::cin >> row;
		std::cin >> y;
		if (y == 0)
			y = 9;
		else
			y--;
		x = text_to_number(&row);
		if (battlefield[y][x] == '_')
		{
			battlefield[y][x] = 'L';
		}
		draw_field(battlefield);
	}

}

void computer_places_ships(char** battlefield)
{
	//HERE
}

int text_to_number(char* row)
{
	int x = 0;
	if (*row == 'A' || *row == 'a')
		x = 0;
	else if (*row == 'B' || *row == 'b')
		x = 1;
	else if (*row == 'C' || *row == 'c')
		x = 2;
	else if (*row == 'D' || *row == 'd')
		x = 3;
	else if (*row == 'E' || *row == 'e')
		x = 4;
	else if (*row == 'F' || *row == 'f')
		x = 5;
	else if (*row == 'G' || *row == 'g')
		x = 6;
	else if (*row == 'H' || *row == 'h')
		x = 7;
	else if (*row == 'I' || *row == 'i')
		x = 8;
	else if (*row == 'K' || *row == 'k')
		x = 9;
	return x;
}