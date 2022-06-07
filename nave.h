#ifndef NAVE_H_
#define NAVE_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  //per consertirci l'utilizzo della toupper()
#include "giocatore.h"

int richiedereRiga();
int richiedereColonna();
int convertireColonnaInNumero(char colonna);
int verificareDimensione(int rInizio, int cInizio, int rFine, int cFine, int dimensione);
int verificareDiagonale(int rInizio, int cInizio, int rFine, int cFine);
int verificareSovrapposizione(giocatore g, int rInizio, int cInizio, int rFine, int cFine);
int calcolareNumeroFrammentiNonColpiti(giocatore g, int idNave);
int verificarePresenzaFrammentiNavi(giocatore g);

#endif /* PARTITA_H_ */
