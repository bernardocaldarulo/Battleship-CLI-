#ifndef GIOCATORE_H_
#define GIOCATORE_H_

#include <stdio.h>
#include <stdlib.h>
#include "definizioni.h"

/*
    Con l'obittivo di sfruttare evidenti vantaggi dovuti alla gestione delle tabelle, il contenuto delle tabelle sarà gestito da i=1 e j=1,
     non i=0 e j=0 come solitamente si sceglie di fare.
    I vantaggi: dopo l'inserimento delle coordinate da tastiera non sarà necessario decrementare gli indici acquisiti.
     Inoltre, ciò rende un grado maggiore di astrazione per i programmatori.
    La conseguenza è che la dimensione delle tabelle sarà (DIM_GIOCO+1) x (DIM_GIOCO+1), DIM_GIOCO=17, da i=1 e j=1, poiché non saranno occupate la riga=0 e colonna=0.
     Così facendo si utilizzano i quadretti da riga 1 a riga 17.
    Infatti, se la dimensione delle tabelle fosse (DIM_GIOCO) x (DIM_GIOCO), DIM_GIOCO=16, da i=0 e j=0, potremmo utilizzare solo i quadretti delle tablle da riga 0 a riga 15.
*/
/**
 * @brief Record di dati che rappresenta un giocatore.
 * Campi: id, nome, tabellaMosse, tabellaDifesa, richiesteRadarEffettuate, bombardamentiAereoSparati, colpiLungoRaggioSparati.
 */
typedef struct{
    int id;                                         //indica l'identificativo univoco del giocatore
    char tabellaMosse[DIM_GIOCO+1][DIM_GIOCO+1];    //rappresenta il campo da gioco da attacca, in cui il nemico ha posizionato le proprie navi
    int tabellaDifesa[DIM_GIOCO+1][DIM_GIOCO+1];    //rappresenta il campo da gioco da difendere, in cui posizionare le proprie navi
    int richiesteRadarEffettuate;                   //indica il numero di richieste radar effettuate
    int bombardamentiAereoSparati;                  //indica il numero di bombardamenti aereo effettuati
    int colpiLungoRaggioSparati;                    //indica il numero di colpi a lungo raggio effettuati
}giocatore;

giocatore scrivereIdGiocatore(giocatore g, int id);
int leggereIdGiocatore(giocatore g);

giocatore scrivereTabellaDifesa(giocatore g, int idNave,int r, int c);
int leggereTabellaDifesa(giocatore g, int r, int c);

giocatore scrivereTabellaMosse(giocatore g, char carattere, int r, int c);
char leggereTabellaMosse(giocatore g, int r, int c);

giocatore scrivereRichiesteRadarEffettuate(giocatore g, int richiesteRadarEffettuate);
int leggereRichiesteRadarEffettuate(giocatore g);

giocatore scrivereBombardamentiAereoSparati(giocatore g, int bombardamentiAereoSparati);
int leggereBombardamentiAereoSparati(giocatore g);

giocatore scrivereColpiLungoRaggioSparati(giocatore g, int colpiLungoRaggioSparati);
int leggereColpiLungoRaggioSparati(giocatore g);

void stampareTabellaMosse(giocatore g);
void stampareTabellaDifesa(giocatore g);
void stampareTabelleGiocatore(giocatore g);

#endif /* GIOCATORE_H_ */
