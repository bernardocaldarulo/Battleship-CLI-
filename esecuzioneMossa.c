#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>      //per consertirci l'utilizzo della toupper()
#include "esecuzioneMossa.h"

/**
 * @brief Funzione che mostra il menu delle mosse, permettendo al giocatore di selezionare quella che preferisce.
 *  Per effetto di eseguireMossa(), se la mossa selezionata non è eseguibile allora ne sarà richiesto l'inserimento. Infatti menuMosse non è efficiente da sola.
 *
 * @return int mossa selezionata
 */
char menuMosse(){
    char mossa;

	if(visualizzareContenutoFile(FILENAME_MENU_MOSSE)==1){
        do{
            printf("\nMossa: ");
            mossa=getchar();
            fflush(stdin);
        }while(mossa!='1' && mossa!='2' && mossa!='3' && mossa!='4');
    }else{
        mossa='0';   //Errore nell'apertura del file, sara gestito da visualizzareContenutoFile()
    }
    return mossa;
}

/**
 * @brief Funzione che effettua un colpo nella tabellaDifesa di giocatoreDifensore, specificandone la coordinata.
 *
 * @param giocatoreAttaccante giocatore che effettua il colpo
 * @param giocatoreDifensore giocatore che riceve il colpo
 * @param p partita di cui i giocatori fanno parte, in cui registrare il colpo
 * @param r riga in cui effettuare l'attacco
 * @param c colonna in cui effettuare l'attacco
 * @return partita con il colpo registrato
 */
partita colpo(giocatore giocatoreAttaccante, giocatore giocatoreDifensore, partita p, int r, int c){
    int i;
    int j;
    int idNave;
    int idNaveNegato;

    idNave=leggereTabellaDifesa(giocatoreDifensore, r, c);  //Contenuto di tabellaDifesa [r][c]

    if(idNave==ACQUA_DIFESA){   //Se il quadretto [r][c] è vuoto
        giocatoreAttaccante=scrivereTabellaMosse(giocatoreAttaccante, MANCATO_MOSSE, r, c); //L'attaccante registra il mancato
        giocatoreDifensore=scrivereTabellaDifesa(giocatoreDifensore, MANCATO_DIFESA, r, c); //Il difensore registra il mancato
    }else{
        if(idNave>=2){  //Se il quadretto [r][c] contiene una nave
            idNaveNegato = idNave * (-1);   //La nave sarà colpita, quindi ne sarà negato l'id
            giocatoreDifensore=scrivereTabellaDifesa(giocatoreDifensore, idNaveNegato, r, c);   //Il difensore registra il colpo subito

            //Se la nave è completamente affondata
            if(calcolareNumeroFrammentiNonColpiti(giocatoreDifensore, idNave)==0){
                i=1;
                while(i<=DIM_GIOCO){
                    j=1;
                    while(j<=DIM_GIOCO){
                        if(leggereTabellaDifesa(giocatoreDifensore, i, j)==idNaveNegato){
                            giocatoreAttaccante=scrivereTabellaMosse(giocatoreAttaccante, COLPITO_AFFONDATO, i, j); //L'attaccante registra la nave avversaria come affondata.
                        }
                        j++;
                    }
                    i++;
                }
            }else{
                giocatoreAttaccante=scrivereTabellaMosse(giocatoreAttaccante, COLPITO, r, c);   //L'attaccante registra il colpo effettuato
            }
        }
    }

    //Vengono aggiornati i giocatori (in particolare, le loro tabelle) in partita
    p=scrivereGiocatore(p, giocatoreAttaccante);
    p=scrivereGiocatore(p, giocatoreDifensore);

    return p;
}

/**
 * @brief Funzione che consente al giocatore di effettuare un colpo, specificandone il centro.
 *
 * @note Il colpo semplice e' usato per colpire un solo quadretto della tabella dell'avversario.
 * @param g giocatore che intende effettuare l'attacco
 * @param p partita di cui fanno parte g e il giocatore difensore
 * @return partita con il colpo semplice registrato
 */
partita colpoSemplice(giocatore g, partita p){
    giocatore giocatoreAttaccante;
    giocatore giocatoreDifensore;
    char carattere; //elemento in tabellaMosse [r][c]
    int r;
    int c;

    //Determina chi è il giocatore attaccante e chi quello difensore. Il giocatore g fornito in input è di certo attaccante
    if(leggereIdGiocatore(g)==ID_GIOCATORE1){
        giocatoreAttaccante = leggereGiocatore(p,ID_GIOCATORE1);    //equivalente a giocatoreAttaccante=g;
        giocatoreDifensore = leggereGiocatore(p,ID_GIOCATORE2);
    }else{
        giocatoreAttaccante = leggereGiocatore(p,ID_GIOCATORE2);
        giocatoreDifensore = leggereGiocatore(p,ID_GIOCATORE1);
    }

    //richiesta delle coordinate [r][c] in cui effettuare il colpo semplice
    do{
        r = richiedereRiga();
        c = richiedereColonna();
        carattere = leggereTabellaMosse(giocatoreAttaccante,r,c);
    }while(carattere == MANCATO_MOSSE || carattere==COLPITO || carattere==COLPITO_AFFONDATO);//per evitare di effettuare un colpo semplice in una cella gia' colpita

    p = colpo(giocatoreAttaccante, giocatoreDifensore, p, r,c); //registro il colpo in partita
    return p;
}

/**
 * @brief Funzione che consente al giocatore di effettuare un colpo a lungo raggio solo dopo aver inserito la riga e la colonna
 *
 * @note Il colpo a largo raggio puo' essere usato al massimo 3 volte per partita ed e' usato a colpire una cella specificata e l'intorno di raggio 1 da essa, per un totale di 9 caselle.
 * @param g giocatore che intende effettuare l'attacco
 * @param p partita di cui fanno parte g e il giocatore difensore
 * @return partita con il colpo lungo raggio registrato
 */
partita colpoLungoRaggio(giocatore g, partita p){
    giocatore giocatoreAttaccante;
    giocatore giocatoreDifensore;
    int r;
    int c;
    int i;
    int j;
    int idAttaccante;   //per memorizzare l'id del giocatore attaccante, così da non dover rifare l'if per ottenerlo
    int idDifensore;    //per memorizzare l'id del giocatore difendore, così da non dover rifare l'if ottenerlo

    //Determina chi è il giocatore attaccante e chi quello difensore. Il giocatore g fornito in input è di certo attaccante
    if(leggereIdGiocatore(g)==ID_GIOCATORE1){
        giocatoreAttaccante = leggereGiocatore(p,ID_GIOCATORE1);    //equivalente a giocatoreAttaccante=g;
        giocatoreDifensore = leggereGiocatore(p,ID_GIOCATORE2);
        idAttaccante = ID_GIOCATORE1;
        idDifensore = ID_GIOCATORE2;
    }else{
        giocatoreAttaccante = leggereGiocatore(p,ID_GIOCATORE2);
        giocatoreDifensore = leggereGiocatore(p,ID_GIOCATORE1);
        idAttaccante = ID_GIOCATORE2;
        idDifensore = ID_GIOCATORE1;
    }

    r = richiedereRiga();
    c = richiedereColonna();
    i=r-1;               //i colpi partono dalla riga precedente a quella indicata dall'utente(r)
    while(i<=r+1){       //l colpi termina nella riga successiva a quella indicata dall'utente(r)
        j=c-1;           //i colpi partono dalla colonna precedente a quella indicata dall'utente(c)
        while(j<=c+1){   //i colpi terminano nella colonna successiva a quella indicata dall'utente(c)
            if(i>=1 && i<=DIM_GIOCO  && j>=1 && j<=DIM_GIOCO){  // nel caso in cui l'indice di riga (i) oppure l'indice di colonna (j) escono fuori dal campo, non si effettua alcun colpo
                p = colpo(giocatoreAttaccante, giocatoreDifensore, p, i,j);
                giocatoreAttaccante = leggereGiocatore(p,idAttaccante);
				giocatoreDifensore = leggereGiocatore(p,idDifensore);
            }
            j++;
        }
        i++;
    }

    //aggiorniamo il numero di colpi a lungo raggio sparati in giocatore attaccante
    giocatoreAttaccante = scrivereColpiLungoRaggioSparati(giocatoreAttaccante,leggereColpiLungoRaggioSparati(giocatoreAttaccante)+1);
    p = scrivereGiocatore(p,giocatoreAttaccante);
    return p;
}

/**
 * @brief Funzione che consente al giocatore di effettuare una scansione radar, specificandone il centro.
 *
 * @note La scansione radar ha un massimo di 3 utilizzi e scopre se nella cella specificata e nell'intorno di raggio 1 da essa ci sono delle navi (o parti di esse).
 * @param g giocatore che intende effettuare l'attacco
 * @param p partita di cui fanno parte g e il giocatore difensore
 * @return partita con la scansione radar registrata
 */
partita scansioneRadar(giocatore g, partita p){
    giocatore giocatoreAttaccante;
    giocatore giocatoreDifensore;
    int r;
    int c;
    int i;
    int j;
    int idNave;

    //Determina chi è il giocatore attaccante e chi quello difensore. Il giocatore g fornito in input è di certo attaccante
    if(leggereIdGiocatore(g)==ID_GIOCATORE1){
        giocatoreAttaccante = leggereGiocatore(p,ID_GIOCATORE1);
        giocatoreDifensore = leggereGiocatore(p,ID_GIOCATORE2);
    }else{
        giocatoreAttaccante = leggereGiocatore(p,ID_GIOCATORE2);
        giocatoreDifensore = leggereGiocatore(p,ID_GIOCATORE1);
    }

    r = richiedereRiga();
    c = richiedereColonna();

    i=r-1;             //la scansione parte dalla riga precedente a quella indicata dall'utente(r)
    while(i<=r+1){     //la scansione termina nella riga successiva a quella indicata dall'utente(r)
        j=c-1;         //la scansione inizia nella colonna precedente a quella indicata dall'utente(c)
        while(j<=c+1){ // la scansione termina nella colonna successiva a quella indicata dall'utente(c)
            if(i>=1 && i<=DIM_GIOCO && j>=1 && j<=DIM_GIOCO){ // nel caso in cui l'indice di riga (i) oppure l'indice di colonna (j) escono fuori dal campo, non si effettua alcuna ricerca
                idNave = leggereTabellaDifesa(giocatoreDifensore, i, j);
                if(idNave>=2){
                    giocatoreAttaccante = scrivereTabellaMosse(giocatoreAttaccante, RADAR_POSITIVO, i,j);
                }else if(idNave==0){
                    giocatoreAttaccante = scrivereTabellaMosse(giocatoreAttaccante, RADAR_NEGATIVO, i,j);
                }
            }
            j++;
        }
        i++;
    }

    //aggiorniamo il numero di richieste radar effettuate in giocatore attaccante
    giocatoreAttaccante = scrivereRichiesteRadarEffettuate(giocatoreAttaccante,leggereRichiesteRadarEffettuate(giocatoreAttaccante)+1);
    p = scrivereGiocatore(p,giocatoreAttaccante);   //aggiorno la partia
    return p;
}

/**
 * @brief Funzione che consente al giocatore di effettuare un bombardamento aereo. Ha effetto su una riga o su una colonna.
 *
 * @note Il bombardamento aereo puo' essere usato dal giocatore solo dopo MIN_BOMBARDAMENTO_AEREO turni, una sola volta per partita.
 * @param g giocatore che intende effettuare l'attacco
 * @param p partita di cui fanno parte g e il giocatore difensore
 * @return partita con il bombardamento aereo registrato
 */
partita bombardamentoAereo(giocatore g, partita p){
    giocatore giocatoreAttaccante;
    giocatore giocatoreDifensore;
    int riga;
    int colonna;
    int i;
    int j;
    char scelta;
    int idAttaccante;   //per memorizzare l'id del giocatore attaccante, così da non dover rifare l'if per ottenerlo
    int idDifensore;    //per memorizzare l'id del giocatore difendore, così da non dover rifare l'if ottenerlo

    //Determina chi è il giocatore attaccante e chi quello difensore. Il giocatore g fornito in input è di certo attaccante
    if(leggereIdGiocatore(g)==ID_GIOCATORE1){
        giocatoreAttaccante = leggereGiocatore(p,ID_GIOCATORE1);
        giocatoreDifensore = leggereGiocatore(p,ID_GIOCATORE2);
        idAttaccante = ID_GIOCATORE1;
        idDifensore = ID_GIOCATORE2;
    }else{
        giocatoreAttaccante = leggereGiocatore(p,ID_GIOCATORE2);
        giocatoreDifensore = leggereGiocatore(p,ID_GIOCATORE1);
        idAttaccante = ID_GIOCATORE2;
        idDifensore = ID_GIOCATORE1;
    }

    if(visualizzareContenutoFile(FILENAME_MENU_BOMBARDAMENTO)==1){
        do{
            fflush(stdin);
            printf("\nScelta: ");
            scelta = getchar();
            fflush(stdin);
            scelta=toupper(scelta); //al fine di ridurre il numero di proposizioni congiunte nella condizione del do-while
        }while(scelta!='R' && scelta !='C');

        //Per favorire la leggibilità i seguenti if non sono in cascata else-if
        if(scelta=='R'){//se il giocatore ha scelto di bombardare tutta la riga
            riga = richiedereRiga();
            j=1;
            while(j<=DIM_GIOCO){
                p = colpo(giocatoreAttaccante, giocatoreDifensore, p, riga, j); //registro il colpo e aggiorno i giocatori con le tabelle aggiornate
                giocatoreAttaccante = leggereGiocatore(p,idAttaccante);
				giocatoreDifensore = leggereGiocatore(p,idDifensore);
                j++;
            }
        }
        if(scelta=='C'){//se il giocatore attaccante ha scelto di bombardare tutta la colonna
            colonna = richiedereColonna();
            i=1;
            while(i<=DIM_GIOCO){
                p = colpo(giocatoreAttaccante, giocatoreDifensore, p, i, colonna); //registro il colpo e aggiorno i giocatori con le tabelle aggiornate
                giocatoreAttaccante = leggereGiocatore(p,idAttaccante);
				giocatoreDifensore = leggereGiocatore(p,idDifensore);
                i++;
            }
        }

        //aggiorniamo il numero di bombardamenti aeero sparati in giocatore attaccante
        giocatoreAttaccante = scrivereBombardamentiAereoSparati(giocatoreAttaccante,leggereBombardamentiAereoSparati(giocatoreAttaccante)+1);
        p = scrivereGiocatore(p,giocatoreAttaccante);
    }
    return p;
}

/**
 * @brief Funzione che permette di eseguire una mossa, scegliendola tra le possibili in quel turno realizazbili.
 *
 * @param g giocatore che intende effettuare l'attacco
 * @param p partita di cui fanno parte g e il giocatore difensore
 * @return partita con la mossa registrata
 */
partita eseguireMossa(giocatore g, partita p){
    char mossa; //indica la mossa selezionata, la cui esecuzione è presieduta da una verifica
    int eseguibile; //determina se la mossa è eseguibile o meno

    do{
        eseguibile=1;
        mossa=menuMosse();  //la mossa viene scelta fra le possibili

        //Per favorire la leggibilità i seguenti if non sono in cascata else-if
        if(mossa=='1'){
            p=colpoSemplice(g, p);
        }

        if(mossa=='2'){
            if(leggereColpiLungoRaggioSparati(g)<MAX_COLPI_LUNGO_RAGGIO){   //se non si è supeato il limite max di colpi a lungo raggio effettuabili
                p=colpoLungoRaggio(g,p);
            }else{
                eseguibile=0;
            }
        }

        if(mossa=='3'){
            if(leggereRichiesteRadarEffettuate(g)<MAX_RADAR){   //se non si è supeato il limite max di scansioni radar effettuabili
                p=scansioneRadar(g, p);
            }else{
                eseguibile=0;
            }
        }

        if(mossa=='4'){
            //se si è in turno tale da poter effettuare il bombardamento aereo E non si è superato il limite max di bombardamenti aereo effettuabili
             if(leggereTurnoPartita(p)>MIN_BOMBARDAMENTO_AEREO && leggereBombardamentiAereoSparati(g)<MAX_BOMBARDAMENTO_AEREO){
                p=bombardamentoAereo(g,p);
             }else{
                eseguibile=0;
            }
        }
    }while(eseguibile==0);   //finché la mossa non è eseguibile, viene richiesto l'inserimento di una mossa

    return p;
}
