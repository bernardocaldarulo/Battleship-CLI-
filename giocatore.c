#include <stdio.h>
#include <stdlib.h>
#include "giocatore.h"
#include "colori.h"

/**
 * @brief Funzione di accesso in scrittura al campo id del record giocatore.
 *
 * @param g giocatore di cui impostare il campo id
 * @param id valore da impostare nel campo id di g
 * @return giocatore con il campo id impostato
 */
giocatore scrivereIdGiocatore(giocatore g, int id){
    g.id=id;
    return g;
}

/**
 * @brief Funzione di accesso in lettura al campo id del record giocatore.
 *
 * @param g giocatore di cui leggere il campo id
 * @return int campo letto del record g
 */
int leggereIdGiocatore(giocatore g){
    int id;
    id=g.id;
    return id;
}

/**
 * @brief Funzione di accesso in scrittura al campo tabellaDifesa in riga r e colonna c del record giocatore.
 *
 * @param g giocatore di cui impostare in campo tabellaDifesa il valore di idNave in [r][c]
 * @param idNave contenuto del quadretto di tabellaDifesa da impostare
 * @param r indice di riga in cui scrivere idNave
 * @param c indice di colonna in cui scrivere idNave
 * @return giocatore giocatore con il campo tabellaDifesa in riga r e colonna c impostato
 */
giocatore scrivereTabellaDifesa(giocatore g, int idNave,int r, int c){
    g.tabellaDifesa[r][c]=idNave;
    return g;
}

/**
 * @brief Funzione di accesso in lettura al campo tabellaDifesa in riga r e colonna c del record giocatore.
 *
 * @param g giocatore di cui leggere il campo tabellaDifesa[r][c]
 * @param r indice di riga di cui leggere il campo tabellaDifesa
 * @param c indice di colonna di cui leggere il campo tabellaDifesa
 * @return int valore letto in riga r e colonna c di tabellaDifesa
 */
int leggereTabellaDifesa(giocatore g, int r, int c){
    int idNave;
    idNave=g.tabellaDifesa[r][c];
    return idNave;
}

/**
 * @brief Funzione di accesso in scrittura al campo tabellaMosse in riga r e colonna c del record giocatore.
 *
 * @param g giocatore di cui impostare in campo tabellaMosse il valore di carattere in [r][c]
 * @param carattere contenuto del quadretto di tabellaMosse
 * @param r indice di riga in cui scrivere carattere
 * @param c indice di colonna in cui scrivere carattere
 * @return giocatore con il campo tabellaMosse in riga r e colonna c impostato
 */
giocatore scrivereTabellaMosse(giocatore g, char carattere, int r, int c){
    g.tabellaMosse[r][c]=carattere;
    return g;
}

/**
 * @brief Funzione di accesso in lettura al campo tabellaMosse in riga r e colonna c del record giocatore.
 *
 * @param g giocatore di cui leggere il campo tabellaMosse[r][c]
 * @param r indice di riga di cui leggere il campo tabellaMosse
 * @param c indice di colonna di cui leggere il campo tabellaMosse
 * @return char valore letto in riga r e colonna c di tabellaDifesa
 */
char leggereTabellaMosse(giocatore g, int r, int c){
    char mossa;
    mossa=g.tabellaMosse[r][c];
    return mossa;
}

/**
 * @brief Funzione di accesso in scrittura al campo richiesteRadarEffettuate del record giocatore.
 *
 * @param g giocatore di cui impostare il campo richiesteRadarEffettuate
 * @param richiesteRadarEffettuate valore da impostare nel campo richiesteRadarEffettuate di g
 * @return giocatore con il campo richiesteRadarEffettuate impostato
 */
giocatore scrivereRichiesteRadarEffettuate(giocatore g, int richiesteRadarEffettuate){
    g.richiesteRadarEffettuate=richiesteRadarEffettuate;
    return g;
}

/**
 * @brief Funzione di accesso in lettura al campo richiesteRadarEffettuate del record giocatore.
 *
 * @param g giocatore di cui leggere il campo richiesteRadarEffettuate
 * @return int campo letto del record g
 */
int leggereRichiesteRadarEffettuate(giocatore g){
    int richiesteRadarEffettuate;
    richiesteRadarEffettuate=g.richiesteRadarEffettuate;
    return richiesteRadarEffettuate;
}

/**
 * @brief Funzione di accesso in scrittura al campo bombardamentiAereoSparati del record giocatore.
 *
 * @param g giocatore di cui impostare il campo bombardamentiAereoSparati
 * @param bombardamentiAereoSparati valore da impostare nel campo bombardamentiAereoSparati di g
 * @return giocatore con il campo bombardamentiAereoSparati impostato
 */
giocatore scrivereBombardamentiAereoSparati(giocatore g, int bombardamentiAereoSparati){
    g.bombardamentiAereoSparati=bombardamentiAereoSparati;
    return g;
}

/**
 * @brief Funzione di accesso in lettura al campo bombardamentiAereoSparati del record giocatore.
 *
 * @param g giocatore di cui leggere il campo bombardamentiAereoSparati
 * @return int campo letto del record g
 */
int leggereBombardamentiAereoSparati(giocatore g){
    int bombardamentiAereoSparati;
    bombardamentiAereoSparati=g.bombardamentiAereoSparati;
    return bombardamentiAereoSparati;
}

/**
 * @brief Funzione di accesso in scrittura al campo colpiLungoRaggioSparati del record giocatore.
 *
 * @param g giocatore di cui impostare il campo colpiLungoRaggioSparati
 * @param colpiLungoRaggioSparati valore da impostare nel campo colpiLungoRaggioSparati di g
 * @return giocatore con il campo colpiLungoRaggioSparati impostato
 */
giocatore scrivereColpiLungoRaggioSparati(giocatore g, int colpiLungoRaggioSparati){
    g.colpiLungoRaggioSparati=colpiLungoRaggioSparati;
    return g;
}

/**
 * @brief Funzione di accesso in lettura al campo colpiLungoRaggioSparati del record giocatore.
 *
 * @param g giocatore di cui leggere il campo colpiLungoRaggioSparati
 * @return int campo letto del record g
 */
int leggereColpiLungoRaggioSparati(giocatore g){
    int colpiLungoRaggioSparati;
    colpiLungoRaggioSparati=g.colpiLungoRaggioSparati;
    return colpiLungoRaggioSparati;
}

/**
 * @brief Procedura che stampa a video il contenuto di tabellaMosse del giocatore g specificato.
 *
 * @param g giocatore da cui leggere il contenuto di tabellaMosse
 */
void stampareTabellaMosse(giocatore g){
    const char ALFABETO[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int i;
    int j;
    i=1;
    printf("%*c", 4, ' ');  //Analogamente a printf("    "). Scrive 4-1 caratteri vuoti, e aggiunge un carattere a scelta (' ', uno spazio).

    while(i<=DIM_GIOCO){
        printf("%c",ALFABETO[i-1]);
        printf("%c",' ');
        i++;
    }
    printf("\n");

    i=1;
    while (i<=DIM_GIOCO){

        if(i<10){
            printf("0%d ",i);
        }else{
            printf("%d ",i);
        }
        j=1;
        printf("%c",SEPARATORE);
        while(j<=DIM_GIOCO){
            printf("%c",leggereTabellaMosse(g,i,j));
            printf("%c",SEPARATORE);
            j++;
        }
        printf("\n");
        i++;
    }
    return;
}

/**
 * @brief Procedura che stampa a video il contenuto di tabellaDifesa del giocatore g specificato.
 *
 * @param g giocatore da cui leggere il contenuto di tabellaDifesa
 */
void stampareTabellaDifesa(giocatore g){
    const char ALFABETO[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int idNave;
    int i;
    int j;
    i=1;
    idNave=0;
    printf("%*c", 4, ' ');  //scrive 4-1 caratteri vuoti, e aggiunge un carattere a scelta (' ', uno spazio)

    while(i<=DIM_GIOCO){
        printf("%c",ALFABETO[i-1]);
        printf("%c",' ');
        i++;
    }

    printf("\n");
    i=1;

    while (i<=DIM_GIOCO){
        if(i<10){
            printf("0%d ",i);
        }else{
            printf("%d ",i);
        }
        j=1;
        printf("%c",SEPARATORE);
        while(j<=DIM_GIOCO){
            idNave = leggereTabellaDifesa(g, i, j);

            //Per favorire la leggibilità i seguenti if non sono in cascata else-if
            if(idNave==ACQUA_DIFESA){
                printf("%c", ACQUA_MOSSE);
            }
            if(idNave==MANCATO_DIFESA){
                printf("%c", MANCATO_MOSSE);
            }
            if(idNave<-1){
                printf("%c", COLPITO_AFFONDATO);
            }
            if(idNave>1){
                printf("%c", NAVE);
            }

            printf("%c", SEPARATORE);
            j++;
        }
        printf("\n");
        i++;
    }

    return;
}

/**
 * @brief Procedura che stampa a video il contenuto di tabellaDifesa e di tabellaMosse del giocatore g specificato.
 *
 * @param g giocatore da cui leggere il contenuto di tabellaDifesa e di tabellaMosse
 */
void stampareTabelleGiocatore(giocatore g){
    const char ALFABETO[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int idNave;
    int i;
    int j;
    i=1;
    idNave=0;
    char c;

    printf("\nGIOCATORE %d\n",leggereIdGiocatore(g));
    printf("TABELLA DIFESA");
    printf("\t\t\t\t\tTABELLA MOSSE\n");
    printf("%*c", 4, ' ');  //scrive 4-1 caratteri vuoti, e aggiunge un carattere a scelta (' ', uno spazio)

    while(i<=DIM_GIOCO){
        printf("%c",ALFABETO[i-1]);
        printf("%c",' ');
        i++;
    }

    printf("\t\t    ");
    i=1;
    while(i<=DIM_GIOCO){
        printf("%c",ALFABETO[i-1]);
        printf("%c",' ');
        i++;
    }

    printf("\n");
    i=1;

    while (i<=DIM_GIOCO){
        if(i<10){
            printf("0%d ",i);
        }else{
            printf("%d ",i);
        }
        j=1;
        printf("%c",SEPARATORE);
        while(j<=DIM_GIOCO){
            idNave = leggereTabellaDifesa(g, i, j);

            //Per favorire la leggibilità i seguenti if non sono in cascata else-if
            if(idNave==ACQUA_DIFESA){
                printf("%c", ACQUA_MOSSE);
            }
            if(idNave==MANCATO_DIFESA){
                printf("%c", MANCATO_MOSSE);
            }
            if(idNave<-1){
            	red();
                printf("%c", COLPITO_AFFONDATO);
                reset();
            }
            if(idNave>1){
                printf("%c", NAVE);
            }

            printf("%c", SEPARATORE);
            j++;
        }

        //inizio stampa della riga di tabella mosse
        printf("\t\t");

        if(i<10){
            printf("0%d ",i);
        }else{
            printf("%d ",i);
        }
        j=1;
        printf("%c",SEPARATORE);
        while(j<=DIM_GIOCO){
        	c = leggereTabellaMosse(g,i,j);
        	if(c==RADAR_POSITIVO){
        		cyan();
        	}
        	if(c==COLPITO){
        		yellow();
        	}
        	if(c==COLPITO_AFFONDATO){
        		green();
        	}
            printf("%c",c);
            reset();
            printf("%c",SEPARATORE);
            j++;
        }
        printf("\n");
        i++;
    }

    return;
}
