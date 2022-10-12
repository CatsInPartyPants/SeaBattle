#include <iostream>
#include "functions.h"

int main()
{
    char** battlefield = make_battlefield();

    main_menu(battlefield);

    delete_battlefield(battlefield);

   
}
