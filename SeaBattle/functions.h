#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#include <iostream>

//field functions

char** make_battlefield();

void delete_battlefield(char** battlefield);

void user_places_ships(char** battlefield);

void computer_places_ships(char** battlefield);


void draw_field(char** battlefield);

//menu functions

void main_menu(char ** battlefield);

void user_vs_computer_menu();

#endif