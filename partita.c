#include "partita.h"

/**
 * @brief Funzione di accesso in scrittura al campo turnoPartita del record partita.
 *
 * @param p partita di cui impostare il campo turnoPartita
 * @param turnoPartita valore da impostare nel campo turnoPartita di p
 * @return partita con il campo turnoPartita impostato
 */
partita scrivereTurnoPartita(partita p, int turnoPartita){
    p.turnoPartita = turnoPartita;
    return p;
}

/**
 * @brief Funzione di accesso in lettura al campo turnoPartita del record partita.
 *
 * @param p partita di cui leggere il campo turnoPartita
 * @return turnoPartita campo letto del record p
 */
int leggereTurnoPartita(partita p){
    int turnoPartita;
    turnoPartita = p.turnoPartita;
    return turnoPartita;
}

/**
 * @brief Funzione di accesso in scrittura al campo turnoGiocatore del record partita.
 *
 * @param p partita di cui impostare il campo turnoGiocatore
 * @param turnoGiocatore valore da impostare nel campo turnoGiocatore di p
 * @return partita con il campo turnoGiocatore impostato
 */
partita scrivereTurnoGiocatore(partita p, int turnoGiocatore){
    p.turnoGiocatore=turnoGiocatore;
    return p;
}

/**
 * @brief Funzione di accesso in lettura al campo turnoGiocatore del record partita.
 *
 * @param p partita di cui leggere il campo turnoGiocatore
 * @return turnoGiocatore campo letto del record p
 */
int leggereTurnoGiocatore(partita p){
    int turnoGiocatore;
    turnoGiocatore=p.turnoGiocatore;
    return turnoGiocatore;
}

/**
 * @brief Funzione di accesso in scrittura al campo giocatore1 o giocatore 2 del record partita, a seconda del valore del campo g.id.
 *        Esempio: se g.id=1, sarà impostato il giocatore1. Se g.id=2, sarà impostato il giocatore2.
 *
 * @param p partita di cui impostare il campo giocatore1 o giocatore2
 * @param g giocatore da impostare nel campo giocaotore1 o giocatore2 di p
 * @note E' importante che il campo g.id sia avvalorato!
 * @return partita con campo giocatore1 o giocatore2 impostato
 */
/*
 *  Per evitare di relizzare due, praticamente uguali, funzioni di accesso (sia in scrittura che in lettura) al campo giocatore 1 e giocatore2,
 *      si preferisce la seguente soluzione: una generica funzione di accesso, che cambia comportamento a seconda del campo g.id impostato.
 *  Pertanto, è importante che il campo g.id sia avvalorato!
 *  Inoltre, tale soluzione predispone più semplicemente possibilità di prevedere più di due giocatori (es. gioco a squadre).
 *  Si realizzi lo stesso principio per la funzione di accesso in lettura.
*/
partita scrivereGiocatore(partita p, giocatore g){
    if(leggereIdGiocatore(g)==ID_GIOCATORE1){
        p.giocatore1 = g;
    }else{
        p.giocatore2 = g;
    }
    return p;
}

/**
 * @brief Funzione di accesso in lettura al campo giocatore1 o giocatore 2 del record partita, a seconda del valore del campo g.id.
 *        Esempio: se g.id=1, sarà impostato il giocatore1. Se g.id=2, sarà impostato il giocatore2.
 *
 * @param p partita di cui leggere il campo giocatore1 o giocatore2
 * @param id del giocatore da leggere del record p
 * @return giocatore letto dal campo giocaotore1 o giocatore2 di p
 */
giocatore leggereGiocatore(partita p, int id){
    giocatore g;
    if(id==ID_GIOCATORE1){
        g = p.giocatore1;
    }else{
        g = p.giocatore2;
    }
    return g;
}

/**
 * @brief Funzione che gestisce le opzioni di salvataggio (salvare, non salvare, salva ed esci, torna al menu principale).
 *
 * @param p partita di cui si discute il salvataggio
 * @return int esito=0 (salvare / non salvare), esito=-1 (salva ed esci / torna al menu principale)
 */
int menuSalvataggio(partita p){
    char scelta;
    int esito;
    esito=0;

    if(visualizzareContenutoFile(FILENAME_MENU_SALVATAGGIO_PARTITA)==1){
        do{
            printf("\nSCELTA: ");
            scelta=getchar();
            fflush(stdin);
            scelta=toupper(scelta); //al fine di ridurre il numero di proposizioni congiunte nella condizione del do-while
        }while(scelta!='S'&& scelta!='N' && scelta!='E' && scelta!='T');


        if(scelta=='S'){    //salvare
            if(salvarePartita(p, FILENAME_SALVATAGGIO_PARTITA)==1){
                printf("La partita e' stata salvata correttamente!!");
            }else{
                printf("problema durante il salvataggio della partita");
                system("pause");
            }
        }

        if(scelta=='E'){    //salva ed esci
            if(salvarePartita(p, FILENAME_SALVATAGGIO_PARTITA)==1){
                printf("La partita e' stata salvata correttamente!!");
            }else{
                printf("problema durante il salvataggio della partita");
                system("pause");
            }
            esito=-1;
        }

        if(scelta=='T'){    //torna al menu principale (esci)
            esito=-1;
        }
    }
    return esito;
}

/**
 * @brief Funzione che salva la partita specificata nel file al filename indicato.
 *
 * @param p partita da salvare
 * @param filenameSalvataggio percorso del file binario in cui salvare
 * @note Il file se non esiste già viene creato, altrimenti viene sovrascritto.
 * @return int esito del salvataggio (1 se partita salvata) (-1 errore nel salvataggio)
 */
int salvarePartita(partita p, char * filenameSalvataggio){
    FILE * fileSalvataggio;
    int esito;

    if((fileSalvataggio=fopen(filenameSalvataggio, "wb"))!=NULL){
        esito=fwrite(&p, sizeof(partita), 1, fileSalvataggio);
        fclose(fileSalvataggio);
	}else{
        gestioneErroriFile(filenameSalvataggio, strerror(errno));
		esito = -1;
	}

    return esito;
}

/**
 * @brief Funzione che carica la partita predentemente salvata specificata nel file al filename indicato.
 *
 * @param fileSalvataggio percorso del file binario dal quale caricare la partita
 * @note I controlli sull'apertura del file vanno fatti prima di attivare la funzione.
 * @return partita da caricare
 */
//Il fileSalvataggio è da aprire fuori, per non restituire due output (esito e partita oppure partita!=NULL o partita=NULL).
partita caricarePartita(FILE * fileSalvataggio){
    partita p;
	fread(&p, sizeof(partita), 1, fileSalvataggio);
    return p;
}
