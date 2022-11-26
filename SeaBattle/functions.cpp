#include "functions.h"
#include <iostream>
#include <Windows.h>

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

void main_menu()
{
	int user_choise_main_menu;
	std::cout << "Game Sea Battle\n\n";

	std::cout << "1. Start game user vs computer." << std::endl;
	std::cout << "2. Start game computer vs computer." << std::endl;
	std::cout << "3. Exit." << std::endl;
	std::cin >> user_choise_main_menu;
	user_vs_computer_menu(user_choise_main_menu);

}

void user_vs_computer_menu(int pvc_or_cvc)
{
	if (pvc_or_cvc == 3)
		std::cout << "Good bye!";
	else if (pvc_or_cvc == 2)
	{
		start_the_game(pvc_or_cvc, 1);
	}
	else {
		int user_choise_user_vs_computer_menu;
		std::cout << "1. Random ship shaffle." << std::endl;
		std::cout << "2. User choose where ships will be stand." << std::endl;
		std::cin >> user_choise_user_vs_computer_menu;
		system("CLS");
		start_the_game(pvc_or_cvc, user_choise_user_vs_computer_menu);
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
	srand(time(NULL));
	int cheking_count_of_boats=0;
	int cheking_count_of_destroyers = 0;

	//battleship
	int btlshp = 0;
	int cruiser = 0;
	btlshp = rand() % 3 +1;
	cruiser = rand() % 2 + 1;
	if (btlshp == 1)
	{
		battlefield[0][9] = 'L';
		battlefield[0][8] = 'L';
		battlefield[0][7] = 'L';
		battlefield[0][6] = 'L';
	}
	else if (btlshp == 2)
	{
		battlefield[9][9] = 'L';
		battlefield[9][8] = 'L';
		battlefield[9][7] = 'L';
		battlefield[9][6] = 'L';
	}
	else if (btlshp == 3)
	{
		battlefield[0][0] = 'L';
		battlefield[1][0] = 'L';
		battlefield[2][0] = 'L';
		battlefield[3][0] = 'L';
	}

	//adding cruisers
	if (btlshp == 1)
	{
		if (cruiser == 1)
		{
			battlefield[0][0] = 'C';
			battlefield[0][1] = 'C';
			battlefield[0][2] = 'C';

			battlefield[9][0] = 'C';
			battlefield[8][0] = 'C';
			battlefield[7][0] = 'C';
		}
		else if (cruiser == 2)
		{
			battlefield[9][9] = 'C';
			battlefield[8][9] = 'C';
			battlefield[7][9] = 'C';

			battlefield[1][0] = 'C';
			battlefield[1][1] = 'C';
			battlefield[1][2] = 'C';
		}
		
	}
	else if (btlshp == 2)
	{
		if (cruiser == 1)
		{
			battlefield[0][9] = 'C';
			battlefield[1][9] = 'C';
			battlefield[2][9] = 'C';

			battlefield[9][0] = 'C';
			battlefield[9][1] = 'C';
			battlefield[9][2] = 'C';
		}
		else if (cruiser == 2)
		{
			battlefield[5][0] = 'C';
			battlefield[6][0] = 'C';
			battlefield[7][0] = 'C';

			battlefield[3][7] = 'C';
			battlefield[3][8] = 'C';
			battlefield[3][9] = 'C';
		}

	}
	else if (btlshp == 3)
	{
		if (cruiser == 1)
		{
			battlefield[3][9] = 'C';
			battlefield[4][9] = 'C';
			battlefield[5][9] = 'C';

			battlefield[0][3] = 'C';
			battlefield[0][4] = 'C';
			battlefield[0][5] = 'C';
		}
		else if (cruiser == 2)
		{
			battlefield[5][0] = 'C';
			battlefield[6][0] = 'C';
			battlefield[7][0] = 'C';

			battlefield[9][1] = 'C';
			battlefield[9][2] = 'C';
			battlefield[9][3] = 'C';
		}
	}

	
	//adding destroyers
	while (cheking_count_of_destroyers != 6)
	{
		int x = 0;
		int y = 0;
		x = 2 + rand() % (7-2);
		Sleep(50);
		y = 2 + rand() % (7-2);
		//std::cout << "X " << x << " Y " << y << std::endl;
		if (battlefield[x][y] == '_' && battlefield[x+1][y] == '_' 
			&& battlefield[x - 1][y] == '_' 
			&& battlefield[x - 1][y-1] == '_'
			&& battlefield[x - 1][y] == '_'
			&& battlefield[x + 1][y - 1] == '_'
			&& battlefield[x+1][y+2] == '_'
			&& battlefield[x + 2][y - 1] == '_'
			&& battlefield[x + 2][y] == '_'
			&& battlefield[x + 2][y + 1] == '_'
			&& battlefield[x + 1][y + 1] == '_'
			&& battlefield[x][y + 1] == '_'
			&& battlefield[x - 1][y + 1] == '_'
			&& battlefield[x][y - 1] == '_'
			&& cheking_count_of_destroyers != 4)
		{
			battlefield[x][y] = 'D';
			battlefield[x + 1][y] = 'D';
			cheking_count_of_destroyers+=2;
			Sleep(75);
			//system("CLS");
			//draw_field(battlefield);
		}
		else if (battlefield[x][y] == '_' && battlefield[x][y + 1] == '_'
			&& battlefield[x - 1][y] == '_'
			&& battlefield[x - 1][y - 1] == '_'
			&& battlefield[x][y - 1] == '_'
			&& battlefield[x + 1][y - 1] == '_'
			&& battlefield[x + 1][y] == '_'
			&& battlefield[x + 1][y + 1] == '_'
			&& battlefield[x + 1][y + 2]
			&& battlefield[x][y + 2] == '_'
			&& battlefield[x - 1][y + 2] == '_'
			&& battlefield[x - 1][y + 1] == '_')
		{
			battlefield[x][y] = 'D';
			battlefield[x][y+1] = 'D';
			cheking_count_of_destroyers += 2;
			Sleep(546);
			//system("CLS");
			//draw_field(battlefield);
		}
	}

	//adding boats
	while (cheking_count_of_boats != 4)
	{
		int x, y;
		x = rand() % 8 + 1;
		Sleep(50);
		y = rand() % 8 + 1;
		if (battlefield[x][y] == '_' && battlefield[x - 1][y] == '_'
			&& battlefield[x - 1][y - 1] == '_'
			&& battlefield[x][y - 1] == '_'
			&& battlefield[x + 1][y - 1] == '_'
			&& battlefield[x + 1][y] == '_'
			&& battlefield[x + 1][y + 1] == '_'
			&& battlefield[x][y + 1] == '_')
		{
			battlefield[x][y] = 'B';
			cheking_count_of_boats++;
			Sleep(574);
			//system("CLS");
			//draw_field(battlefield);
		}
	}
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

bool isWin(char** battlefield)
{
	int win = 0;
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			if (battlefield[x][y] == 'X')
			{
				win++;
			}
		}
	}
	if (win == 20)
		return true;
	else
		return false;
}


bool user_make_shot(char** enemybattlefield, char** emptybatlefield)
{
	char row;
	int y, x;
	std::cout << "Enter row (A,B,C etc.) ->";
	std::cin >> row;
	std::cout << "Enter colomn (1,2,3 etc.) ->";
	std::cin >> y;
	if (y == 0)
		y = 9;
	else
		y--;
	x = text_to_number(&row);

if(enemybattlefield[y][x] == '_')
	{
		enemybattlefield[y][x] = '*';
		emptybatlefield[y][x] = '*';
		return false;
	}
	else if (enemybattlefield[y][x] == '*' || enemybattlefield[y][x] == 'X')
	{
		std::cout << "You already shot to this cell!\n";
		return true;
	}
	else
	{
		enemybattlefield[y][x] = 'X';
		emptybatlefield[y][x] = 'X';
		return true;
	}
	
}

bool computer_make_stupid_shot(char** enemybattlefield)
{
	srand(time(NULL));
	int x = 0;
	int y = 0;
	bool isMakeShot = false;
	
	while (isMakeShot == false)
	{
		x = 0 + rand() % 10;
		y = 0 + rand() % 10;
		if (enemybattlefield[x][y] == '_')
		{
			enemybattlefield[x][y] = '*';
			isMakeShot = true;
			return false;
		}
		else if(enemybattlefield[x][y] == '*' || enemybattlefield[x][y] == 'X')
		{
			isMakeShot = false;
		}
		else
		{
			enemybattlefield[x][y] = 'X';
			isMakeShot = true;
			return true;
		}
	}
	
}

void start_the_game(int pvc_or_cvc, int shipshaffle)
{
	if (pvc_or_cvc == 1)
	{
		//making 2 fields
		char** first_battlefield = make_battlefield();

		char** second_battlefield = make_battlefield();

		char** empty_battlefield = make_battlefield();

		bool is_user_got_shot = false;
		bool is_computer_got_shot = false;

		//second field anyway shaffle by computer
		computer_places_ships(second_battlefield);

		//first field shaffeled by user or computer?
		if (shipshaffle == 1)
			computer_places_ships(first_battlefield);
		else if (shipshaffle == 2)
			user_places_ships(first_battlefield);
		while (true)
		{
			std::cout << "It is your ships position:\n";
			draw_field(first_battlefield);
			std::cout << std::endl << std::endl;
			std::cout << "Your shots, * - missings, X - on target:\n";
			draw_field(empty_battlefield);

			if (!is_computer_got_shot)
			{
				is_user_got_shot = user_make_shot(second_battlefield, empty_battlefield);
				if (isWin(second_battlefield))
				{
					std::cout << "User win!\n";
					break;
				}
				Sleep(1000);
			}
			if (!is_user_got_shot)
			{
				is_computer_got_shot = computer_make_stupid_shot(first_battlefield);
				if (isWin(first_battlefield))
				{
					std::cout << "Computer win!\n";
					break;
				}
			}
			system("CLS");
		}

	}
	else if (pvc_or_cvc == 2)
	{
		char** first_battlefield = make_battlefield();

		char** second_battlefield = make_battlefield();

		bool is_first_got_shot = false;
		bool is_second_got_shot = false;

		computer_places_ships(first_battlefield);
		computer_places_ships(second_battlefield);

		while (true)
		{
			std::cout << "It is 1 computer ships position:\n";
			draw_field(first_battlefield);
			std::cout << std::endl << std::endl;
			std::cout << "It is 2 computer ships position:\n";
			draw_field(second_battlefield);

			if (!is_second_got_shot)
			{
				is_first_got_shot = computer_make_stupid_shot(second_battlefield);
				if (isWin(second_battlefield))
				{
					system("CLS");
					std::cout << "It is 1 computer ships position:\n";
					draw_field(first_battlefield);
					std::cout << std::endl << std::endl;
					std::cout << "It is 2 computer ships position:\n";
					draw_field(second_battlefield);
					std::cout << "Computer 1 win!\n";
					break;
				}
				Sleep(100);
			}

			if (!is_first_got_shot)
			{

				is_second_got_shot = computer_make_stupid_shot(first_battlefield);
				if (isWin(first_battlefield))
				{
					system("CLS");
					std::cout << "It is 1 computer ships position:\n";
					draw_field(first_battlefield);
					std::cout << std::endl << std::endl;
					std::cout << "It is 2 computer ships position:\n";
					draw_field(second_battlefield);
					std::cout << "Computer 2 win!\n";
					break;
				}
				Sleep(100);
			}
			system("CLS");
		}
	}	
}