/* @file battleship.c
 *  @brief Progetto: Battleship (CLI).
 *  @brief Laboratorio di Informatica @ Uniba Informatica A-L 21-22.

 *  @author Caldarulo Bernardo
 *  @author Chiarito Pierluigi
 *  @author Leonetti Davide
 */

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>	//per consertirci l'utilizzo della SetConsoleTitleA()
#include "giocarePartita.h"
#include "definizioni.h"

int main(void) {
	SetConsoleTitleA("BATTLESHIP - Battaglia Navale");
	menuPrincipale();

	printf("\n");
	system("pause");
	return EXIT_SUCCESS;
}

