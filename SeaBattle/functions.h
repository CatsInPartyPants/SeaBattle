#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#include <iostream>

//field functions

char** make_battlefield();

void delete_battlefield(char** battlefield);

void user_places_ships(char** battlefield);

void computer_places_ships(char** battlefield);

int text_to_number(char* row);

void draw_field(char** battlefield);

//menu functions

void main_menu();

void user_vs_computer_menu(int pvc_or_cvc);

//game functions

bool isWin(char** battlefield);

void start_the_game(int pvc_or_cvc, int shipshaffle);

bool user_make_shot(char** enemybattlefield, char** emptybatlefield);

bool computer_make_stupid_shot(char** enemybattlefield);


#endif