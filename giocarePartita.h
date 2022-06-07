#ifndef GIOCAREPARTITA_H_
#define GIOCAREPARTITA_H_

#include <stdio.h>
#include <stdlib.h>
#include "nave.h"
#include "partita.h"
#include "esecuzioneMossa.h"

giocatore inizializzareTabellaMosse(giocatore g);
giocatore inizializzareTabellaDifesa(giocatore g);
giocatore posizionareNave(giocatore g, int dimensione, int idNave);
partita posizionareTutteLeNavi(partita p, giocatore g);

int decretareVincitore(giocatore giocatoreDifensore, giocatore giocatoreAttaccante);
partita nuovaPartita();
void gioco(partita p);
void giocarePartita();
void menuPrincipale();

#endif /* GIOCAREPARTITA_H_ */
