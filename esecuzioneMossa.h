#ifndef ESECUZIONEMOSSA_H_
#define ESECUZIONEMOSSA_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>      //per consertirci l'utilizzo della toupper()
#include "partita.h"
#include "nave.h"

char menuMosse();
partita colpo(giocatore giocatoreAttaccante, giocatore giocatoreDifensore, partita p, int r, int c);
partita colpoSemplice(giocatore g, partita p);
partita colpoLungoRaggio(giocatore g, partita p);
partita scansioneRadar(giocatore g, partita p);
partita bombardamentoAereo(giocatore g, partita p);
partita eseguireMossa(giocatore g, partita p);

#endif /* ESECUZIONEMOSSA_H_ */
