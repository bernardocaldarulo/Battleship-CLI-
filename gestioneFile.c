#include "gestioneFile.h"

/**
 * @brief Funzione che visualizza il contenuto di un file aperto in lettura al percorso specificato.
 *  In caso di errore durante l'apertura del file, l'errore verrà gestito comunicandolo a video.
 *
 * @param filename percorso al file di cui visualizzare il contenuto
 * @return esito che indica se l'appertura del file è avvenuta con successo (esito=1) oppure se si è verificato un errore (esito=-1).
 */
int visualizzareContenutoFile(char * filename){
    FILE * fp;
    int esito;

    if((fp=fopen(filename, "r"))!=NULL){
        char c;
		while((c=getc(fp))!=EOF){
			printf("%c", c);
		}
        esito=1;
		fclose(fp);
	}else{
        gestioneErroriFile(filename, strerror(errno));
		esito = -1;
	}
    return esito;
}


/**
 * @brief Procedura che presenta ai giocatori il menu di Help del gioco,
 *  il quale consiste nella visualizzazione della descrizione e regole del gioco. Inoltre, se si intende proseguire, della legenda.
 *
 */
void help(){
    char scelta;

    system("cls");
    if(visualizzareContenutoFile(FILENAME_TITOLO_HELP)==1){
        if(visualizzareContenutoFile(FILENAME_REGOLE)==1){
            //scelta che consente all'utente di tornare al menu oppure proseguire stampando a video la legenda
            do{
                fflush(stdin);
                printf("\nScelta: ");
                scelta=getchar();
                fflush(stdin);
            }while(scelta!='0' && scelta!='1');

            if(scelta=='1'){
                system("cls");
                if(visualizzareContenutoFile(FILENAME_TITOLO_HELP)==1){
                    if(visualizzareContenutoFile(FILENAME_LEGENDA)==1){
                        //scelta che consente all'utente di tornare al menu di gioco
                        do{
                            fflush(stdin);
                            printf("\n<-- Premere 0 per tornare al Menu Principale: ");
                            scelta=getchar();
                            fflush(stdin);
                        }while(scelta!='0');
                    }
                }
            }
        }
    }

    return;
}

/**
 * @brief Procedura che presenta ai giocatori il menu dei Crediti del gioco.
 *
 */
void crediti(){
    char scelta;

    system("cls");
    if(visualizzareContenutoFile(FILENAME_TITOLO_CREDITI)==1){
        if(visualizzareContenutoFile(FILENAME_CREDITI)==1){
            //scelta che consente all'utente di tornare al menu di gioco
            do{
                fflush(stdin);
                printf("\n<-- Premere 0 per tornare al Menu Principale: ");
                scelta=getchar();
                fflush(stdin);
            }while(scelta!='0');
        }
    }

    return;
}

/**
 * @brief Proedura che stampa a video l'errore eventuale conseguente al tentativo di apertura di un file.
 *
 * @param filename percorso del file la cui apertura ha generato errore
 * @param errore stringa di errore
 * @note il parametro errore è bene che sia sostituito con strerror(errno)
 */
void gestioneErroriFile(char * filename, char * errore){
    printf("Impossibile aprire il file %s: %s", filename, strerror(errno));
    return;
}

/**
 * @brief Funzione che salva la miglior giocata sul filename specificato
 *
 * @param migliorGiocata miglior giocata da salvare su file
 * @param filenameSalvataggio percorso al file su cui salvare la migliorGiocata
 * @return int esito=-1 se non è stato possibile aprire il file in cui è salvata la miglior giocata.ù
 */
/*
* Si decide di salvare la miglior giocata si su file binario per evitare possibili modifiche non permesse alla miglior giocata.
*/
int salvareMigliorGiocata(int migliorGiocata, char * filenameSalvataggio){
    FILE * fileSalvataggio;
    int esito;
    if((fileSalvataggio=fopen(filenameSalvataggio, "wb"))!=NULL){
        esito=fwrite(&migliorGiocata, sizeof(int), 1, fileSalvataggio);
        fclose(fileSalvataggio);
	}else{
        gestioneErroriFile(filenameSalvataggio, strerror(errno));
		esito = -1;
	}

    return esito;
}

/**
 * @brief funzione che legge la miglior giocata da file al filename specificato.
 *
 * @param filenameSalvataggio percorso del file binario dal quale leggere la miglior giocata
 * @return int migliorGiocata>0 (se esiste ed è stata letta), migliorGiocata-1 (se non è stato possibile leggere da file e/o perché non esiste).
 */
int leggereMigliorGiocata(char * filenameSalvataggio){
    int migliorGiocata;
    FILE * fileSalvataggio;
    fileSalvataggio = fopen(filenameSalvataggio, "rb");

    if(fileSalvataggio!=NULL){
        fread(&migliorGiocata, sizeof(int), 1, fileSalvataggio);
        fclose(fileSalvataggio);
    }else{
        migliorGiocata = -1;    //se non è stato possibile aprire il file (non esiste ancora una giocata migliore, cioè non si è ancora conclusa una partita fissando il primo record)
    }

    return migliorGiocata;
}
