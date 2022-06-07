#ifndef PARTITA_H
#define PARTITA_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>      //per consertirci l'utilizzo della toupper()
#include "giocatore.h"
#include "gestioneFile.h"

/**
 * @brief Record di dati che rappresenta la partita.
 * Campi: turnoPartita, turnoGiocatore, giocatore1, giocatore2.
 */
typedef struct{
    int turnoPartita;       //indica il numero di turni effettuati sino a quel momento in quella partita. Viene incrementato a ogni cambio di turnoGiocatore
    int turnoGiocatore;     //indica l’id del giocatore che possiede il turno
    giocatore giocatore1;   //rappresenta il primo giocatore
    giocatore giocatore2;   //rappresenta il secondo giocatore
}partita;

partita scrivereTurnoPartita(partita p, int turnoPartita);
int leggereTurnoPartita(partita p);

partita scrivereTurnoGiocatore(partita p, int turnoGiocatore);
int leggereTurnoGiocatore(partita p);

partita scrivereGiocatore(partita p, giocatore g);
giocatore leggereGiocatore(partita p, int id);

int menuSalvataggio(partita p);
int salvarePartita(partita p, char * filenameSalvataggio);
partita caricarePartita(FILE * fileSalvataggio);

#endif /* PARTITA_H_ */
