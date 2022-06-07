#include "giocarePartita.h"

/**
 * @brief Funzione che inizializza la tabella delle mosse del giocatore g specificato
 *
 * @param g giocatore di cui si vuole inizializzare la tabella delle mosse
 * @return giocatore con la tabella delle mosse inizializzata
 */
giocatore inizializzareTabellaMosse(giocatore g){
    int i;
    int j;
    i=1;
    while(i<=DIM_GIOCO){
        j=1;
        while(j<=DIM_GIOCO){
            g=scrivereTabellaMosse(g,ACQUA_MOSSE,i,j);
            j++;
        }
        i++;
    }
    return g;
}

/**
 * @brief Funzione che inizializza la tabella di difesa del giocatore g specificato
 *
 * @param g giocatore di cui si vuole inizializzare la tabella di difesa
 * @return giocatore con la tabella di difesa inizializzata
 */
giocatore inizializzareTabellaDifesa(giocatore g){
    int i;
    int j;
    i=1;
    while(i<=DIM_GIOCO){
        j=1;
        while(j<=DIM_GIOCO){
            g=scrivereTabellaDifesa(g,ACQUA_DIFESA,i,j);
            j++;
        }
        i++;
    }

    return g;
}

/**
 * @brief Funzioni che posiziona nella tabella difesa del giocatore g una nave avente coordinate di inizio e fine,
 *  e un identificativo positivo (la nave quando viene posizionata non è colpita).
 * Finché saranno inseriti valori di posizionamento non validi, ne sarà richiesto l'inserimento.
 *
 * @param g giocatore nella cui tabella di difesa posizionare la nave nelle coordinate specificate
 * @param dimensione dimensione della nave
 * @param idNave l'id della nave da posizionare
 * @return giocatore con la nave posizionata
 */
giocatore posizionareNave(giocatore g, int dimensione, int idNave){
    int esitoDimensione;
    int esitoDiagonale;
    int esitoSovrapposizione;

    int rInizio;
    int rFine;
    int cInizio;
    int cFine;

    int orizzontale;
    int r;
    int c;
    int inizio;
    int fine;

    int i;
    int j;

    do{
        if(dimensione==1){  // se la dimensione della nave è uguale a 1, allora chiediamo all'utente di inserire solo una riga e una colonna
            printf("\nCoordinate:\n");
            rInizio=richiedereRiga();
            cInizio=richiedereColonna();
            rFine=rInizio;
            cFine=cInizio;
        }else{
            printf("\nCoordinate di inizio:\n");
            rInizio=richiedereRiga();
            cInizio=richiedereColonna();
            printf("\ncoordinate di fine:\n");
            rFine=richiedereRiga();
            cFine=richiedereColonna();
        }

        esitoDimensione = verificareDimensione(rInizio,cInizio,rFine,cFine,dimensione);
        esitoDiagonale = verificareDiagonale(rInizio,cInizio,rFine,cFine);
        esitoSovrapposizione = verificareSovrapposizione(g, rInizio, cInizio, rFine, cFine);
    }while(esitoDimensione==0 || esitoDiagonale==1 || esitoSovrapposizione==1 || esitoDimensione==-1 || esitoDiagonale==-1 || esitoSovrapposizione==-1);

    /*
    *   Il flusso procede solo se si sono inserite coordinate di inizio e fine tali da aver passato i controlli di
    *   ripetto della dimensione richiesta, di posizionamento non in diagonale e di posizionamento non sovrapposto.
    */

    /*
    *  Poichè l'utente è libero di inserire le coordinate limite della nave liberamente (ES. (1,a)(1,b) è equivalente a (1,b)(1,a))
    *  Ricerchiamo mediante le coordinate (rInizio,cInizio) e (rFine,cFine) l'orientamento della nave. Ricerchiamo in oltre la coordinata limite "più piccola" e "più grande"
    *  in modo da effettuare i cicli di inserimento nella tabella difesa del giocatore solo per incrementi.
    */
    if(rInizio==rFine){//se la nave verrà posizionata in orizzontale (e quindi la riga relativa alla nave rimane fissa)
        if(cInizio<cFine){
            inizio=cInizio;// comporrà la coordinata (r,inizio)
            fine=cFine;    // comporrà la coordinata (r,fine)
        }else{
            inizio=cFine;  // comporrà la coordinata (r,inizio)
            fine=cInizio;  // comporrà la coordinata (r,fine)
        }
        r=rInizio;      //salviamo il contenuto di rInizio in r
        orizzontale=1;  //  indica che la nave verrà posizionata in orizzontale
    }else{ // se la nave verrà posizionata in verticale (e quindi la colonna relativa alla nave rimane fissa)
        if(rInizio<rFine){
            inizio=rInizio; // comporrà la coordinta (inizio,c)
            fine=rFine;     // comporrà la coordinta (fine,c)
        }else{
            inizio=rFine;   // comporrà la coordinta (inizio,c)
            fine=rInizio;   // comporrà la coordinta (fine,c)
        }
        c=cInizio;      //salviamo il contenuto di cInizio in c
        orizzontale=0;  //indica che la nave verrà posizionata in verticale
    }

    if(orizzontale==1){ // se la nave deve essere posizionata in orizzontale, allora nel ciclo incrementiamo solo la colonna (j) facendola arrivare a fine
        j=inizio;
        while(j<=fine){
            g=scrivereTabellaDifesa(g,idNave,r,j);
            j++;
        }
    }else{   // se la nave deve essere posizionata in verticale, allora nel ciclo incrementiamo solo la riga (i) facendola arrivare a fine
        i=inizio;
        while(i<=fine){
            g=scrivereTabellaDifesa(g,idNave,i,c);
            i++;
        }
    }
    return g;
}

/**
 * @brief Funzione che posiziona nella tabella difesa del giocatore g tutte le navi (in numero pari a MAX_MAVI).
 * Le caratteristiche delle navi saranno generate autoaticaente dal sistema e presentate al giocatore.
 *
 * @param g giocatore nella cui tabella di difesa posizionare tutte le navi
 * @return partita con tutte le navi posizionate in tabellaDifesa
 */
/*
*   Numero e Dimensione delle navi: 1 nave da 5 caselle, 2 navi da 4 caselle, 3 navi da 3 caselle, 4 navi da 2 caselle e 5 navi da 1 caselle.
*   Viene sfruttata la relazione che intercorre fra la quantità di navi e la loro dimensione.
*   Si osserva infatti che il numero di navi viene incrementato di uno e il numero di caselle associato viene decrementato di uno ad ogni cambio di dimensione di nave.
*   Esempio: i=1 n=5  chiedo 1 navi da 5
*            i=2 n=4  chiedo 2 navi da 4
*            i=3 n=3  chiedo 3 navi da 3
*            i=4 n=2  chiedo 4 navi da 2
*            i=5 n=1  chiedo 5 navi da 1.
*   Un vanaggio che questa soluzione presenta è che si tratta di un meccanismo dinamico,
*       ed è flessibile in caso di cambiamento di MAX_DIM_NAVE coerentemente ad un possibile cambiamento di DIM_GIOCO.
*/
partita posizionareTutteLeNavi(partita p, giocatore g){
    int nNavi;      //numero di navi di una certa dimensione da inserire
    int id;         //ad ogni nave sarà associato un id differente
    int count;      //conta il numero di navi di una certa dimensione inserite
    int dimNave;    //numero di quadretti (caselle) associate a nNavi
    int stop;   //determina se la visualizzazione del titolo del gioco è andata a buon fine

    nNavi=1;
    id=2;   //id=1 (mancato) e id=0 (acqua) sono configurazioni riservate
    dimNave = MAX_DIM_NAVE;
    stop=0;


    while(nNavi<=MAX_DIM_NAVE && stop==0){  //per ogni tipo di nave
        count=1;    //resetto il contatore di navi inserite
        while(count<=nNavi && stop==0){   //mentre ci sono ancora navi da inserire, di quella diemensione
            system("cls");
            if(visualizzareContenutoFile(FILENAME_TITOLO_GIOCO)==1){
                stampareTabelleGiocatore(g);
                //printf("\nInserire %d navi da %d celle. \n", (nNavi-count), dimNave); altra possibile stampa
                printf("\nInserire la %d^ nave da %d celle", count, dimNave);
                g = posizionareNave(g, dimNave, id);
            }else{
                stop=1;
            }

            id++;   //incremento l'id
            count++;    //incremento il contatore di navi inserite
        }
        nNavi++;    //il numero di navi viene incrementato di uno
        dimNave--;  // numero di caselle associato a nNavi viene decrementato di uno
    }

    system("cls");
    if(visualizzareContenutoFile(FILENAME_TITOLO_GIOCO)==1){
        stampareTabelleGiocatore(g);
    }
    p = scrivereGiocatore(p, g);    //aggiorno la partita con il giocatore le cui navi sono state inserite
    return p;
}

/**
 * @brief Funzione che decreta il vinctore, se è possibile, fra i due in scontro.
 *
 * @param giocatoreDifensore giocatore che in quel momento è difensore
 * @param giocatoreAttaccante giocatore che in quel momento è attaccante
 * @return int giocatoreVincitore=0 (non ha vinto nessuno dei due), altrimenti giocatoreVincitore=1 (vince giocatore1) o giocatoreVincitore=2 (vince giocatore2)
 */
int decretareVincitore(giocatore giocatoreDifensore, giocatore giocatoreAttaccante){
    int giocatoreVincitore;
    giocatoreVincitore=0;

    if(verificarePresenzaFrammentiNavi(giocatoreDifensore)==0){ //se il giocatore che difende non ha più navi (o suoi frammenti) non colpiti
        giocatoreVincitore=leggereIdGiocatore(giocatoreAttaccante); //vince l'attaccante
        if(giocatoreVincitore==ID_GIOCATORE1){
            printf("\nHa vinto il giocatore %d!!\n",ID_GIOCATORE1);
        }else if(giocatoreVincitore==ID_GIOCATORE2){
            printf("\nHa vinto il giocatore %d!!\n",ID_GIOCATORE2);
        }
        system("pause");
    }

    return giocatoreVincitore;  //viene restituito l'id del vincitore
}

/**
 * @brief Funzione che inizializza tutti i campi del record partita.
 *
 * @return partita con tutti i campi inizializzati
 */
partita nuovaPartita(){
    partita p;
    giocatore g1;
    giocatore g2;

    p = scrivereTurnoPartita(p, VALORE_INIZIALE_CAMPI_TURNO);
    p = scrivereTurnoGiocatore(p, VALORE_INIZIALE_CAMPI_TURNO);

    g1 = scrivereIdGiocatore(g1, ID_GIOCATORE1);
    g2 = scrivereIdGiocatore(g2, ID_GIOCATORE2);

    g1 = inizializzareTabellaDifesa(g1);
    g2 = inizializzareTabellaDifesa(g2);

    g1 = inizializzareTabellaMosse(g1);
    g2 = inizializzareTabellaMosse(g2);

    g1 = scrivereRichiesteRadarEffettuate(g1, VALORE_INIZIALE_CAMPI_MOSSE);
    g2 = scrivereRichiesteRadarEffettuate(g2, VALORE_INIZIALE_CAMPI_MOSSE);

    g1 = scrivereBombardamentiAereoSparati(g1, VALORE_INIZIALE_CAMPI_MOSSE);
    g2 = scrivereBombardamentiAereoSparati(g2, VALORE_INIZIALE_CAMPI_MOSSE);

    g1 = scrivereColpiLungoRaggioSparati(g1, VALORE_INIZIALE_CAMPI_MOSSE);
    g2 = scrivereColpiLungoRaggioSparati(g2, VALORE_INIZIALE_CAMPI_MOSSE);

    p = scrivereGiocatore(p, g1);
    p = scrivereGiocatore(p, g2);

    p = posizionareTutteLeNavi(p,g1);
    printf("\nNavi posizionate correttamente. Premere INVIO per passare al giocatore 2 ...");
    getchar();
    fflush(stdin);

    p = posizionareTutteLeNavi(p,g2);
    printf("\nNavi posizionate correttamente. Premere INVIO per giocare ...");
    getchar();
    fflush(stdin);
    return p;
}

/**
 * @brief Procedura che gestisce il gioco di una partita
 * @note se la partita è nuova, è necessario che venga inizializzata. (se ne occupa giocarePartita())
 * @note se la partita è caricata, è necessario che esista. (se ne occupa giocarePartita())
 *
 * @param p partita nuova o caricata da salvataggio
 */
void gioco(partita p){
    giocatore giocatoreAttaccante;
    giocatore giocatoreDifensore;
    int turnoPartita;
    int turnoGiocatore;
    int esito;  //esito della ricerca di un giocatoreVincitore (0 se non ha vinto nessuno, 1 o 2 se ha vinto il giocatore1 o giocatore2)
    int idAttaccante;   //per memorizzare l'id del giocatore attaccante, così da non dover rifare l'if per ottenerlo
    int idDifensore;    //per memorizzare l'id del giocatore difendore, così da non dover rifare l'if ottenerlo
    int migliorGiocataPrecedente;

    do{
        turnoPartita = leggereTurnoPartita(p);
        turnoGiocatore = leggereTurnoGiocatore(p);

        if(turnoGiocatore==ID_GIOCATORE1){
            giocatoreAttaccante=leggereGiocatore(p,ID_GIOCATORE1);
            giocatoreDifensore=leggereGiocatore(p,ID_GIOCATORE2);
            turnoGiocatore = ID_GIOCATORE2;
            idAttaccante = ID_GIOCATORE1;
            idDifensore = ID_GIOCATORE2;
        }else{
            giocatoreAttaccante=leggereGiocatore(p,ID_GIOCATORE2);
            giocatoreDifensore=leggereGiocatore(p,ID_GIOCATORE1);
            turnoGiocatore = ID_GIOCATORE1; //si memorizza il giocatore che dopo avrà il turno
            idAttaccante = ID_GIOCATORE2;
            idDifensore = ID_GIOCATORE1;
        }

        system("cls");

        if(visualizzareContenutoFile(FILENAME_TITOLO_GIOCO)==1){
            printf("\nTurno %d, tocca al:",turnoPartita);
            stampareTabelleGiocatore(giocatoreAttaccante);
            //stampareTabelleGiocatore(giocatoreDifensore); // solo per debug
            p=eseguireMossa(giocatoreAttaccante,p); //l'attaccante effettua la mossa

            //aggiorno i giocatori con tabelle con l'esito della mossa registrato
            giocatoreAttaccante = leggereGiocatore(p, idAttaccante);
            giocatoreDifensore = leggereGiocatore(p, idDifensore);

            turnoPartita++; //incremento il numero di turni effettuati nella partita
            p = scrivereTurnoPartita(p,turnoPartita);   //lo aggiorno
            p = scrivereTurnoGiocatore(p,turnoGiocatore);   //cammbio il turno all'altro giocatore

            system("cls");
            if(visualizzareContenutoFile(FILENAME_TITOLO_GIOCO)==1){
                printf("\nTurno %d, tocca al:",turnoPartita-1);
                stampareTabelleGiocatore(giocatoreAttaccante);
                //stampareTabelleGiocatore(giocatoreDifensore); // solo per debug
                esito = decretareVincitore(giocatoreDifensore, giocatoreAttaccante);    //cerco un vincitore, se esiste

                if(esito==0){   //se non esiste ancora un vincitore, si è liberi di scegliere fra le opzioni di salvataggio possibili
                    esito=menuSalvataggio(p);
                }else{
                    migliorGiocataPrecedente = leggereMigliorGiocata(FILENAME_SALVATAGGIO_MILGLIOR_GIOCATA);
                    if(migliorGiocataPrecedente!=-1){   //se esiste una miglior giocata
                        if((turnoPartita-1)<migliorGiocataPrecedente){   //se si è battuto il record
                            if(salvareMigliorGiocata(turnoPartita-1,FILENAME_SALVATAGGIO_MILGLIOR_GIOCATA)==1){
                                printf("\nHai battuto il record precedente di %d, con %d turni!\n", migliorGiocataPrecedente, (turnoPartita-1));
                                system("pause");
                            }
                        }
                    }else{  //se non esiste ancora una miglior giocata (cioè non si è mai giocata una partita)
                        if(salvareMigliorGiocata(turnoPartita-1,FILENAME_SALVATAGGIO_MILGLIOR_GIOCATA)==1){
                            printf("\nHai segnato il primo record, con %d turni!\n", (turnoPartita-1));
                            system("pause");
                        }
                    }
                }
            }
        }else{
            esito=-1;   //in modo da uscire dal ciclo e non far proseguire la partita
        }

    }while(esito==0);   //finché non ha ancora vinto uno dei due giocatori

    return;
}

/**
 * @brief Procedura che permette di giocare una partita, scegliendo se iniziarne una nuova oppure caricare quella precedentemente salvata.
 *
 */
void giocarePartita(){
    partita p;
    char scelta;
    int esistenzaSalvataggio;
    esistenzaSalvataggio = 1;

    system("cls");
    if(visualizzareContenutoFile(FILENAME_TITOLO_GIOCO)==1){
        if(visualizzareContenutoFile(FILENAME_MENU_GIOCAREPARTITA)==1){
            do{
                fflush(stdin);
                printf("\nScelta: ");
                scelta=getchar();
                fflush(stdin);
            }while(scelta!='0' && scelta!='1' && scelta!='2');

            if(scelta=='1'){    //Se iniziare una nuova partita
                p = nuovaPartita();
            }else if(scelta=='2'){  //Se caricare la partita precedentemente salvata (se esiste)
                FILE * fileSalvataggio;
                fileSalvataggio = fopen(FILENAME_SALVATAGGIO_PARTITA, "rb");
                if(fileSalvataggio!=NULL){
                    p = caricarePartita(fileSalvataggio);
                    fclose(fileSalvataggio);
                }else{
                    printf("Nessuna partita salvata.\n");
                    esistenzaSalvataggio = 0;
                    system("pause");
                }
            }

            if(scelta=='1' || (scelta=='2' && esistenzaSalvataggio==1)){
                gioco(p);   //la partita viene giocata
            }
        }
    }
    return;
}

/**
 * @brief Procedura che gestisce il menu principale del gioco. Permette di giocare una partita (nuova o salvata), consultare l'help, la classifica e i crediti del gioco.
 *
 */
void menuPrincipale(){
    char scelta;
    int migliorGiocata;
    do{
        system("cls");
        if(visualizzareContenutoFile(FILENAME_TITOLO_GIOCO)==1){
            migliorGiocata = leggereMigliorGiocata(FILENAME_SALVATAGGIO_MILGLIOR_GIOCATA);
            if(migliorGiocata!=-1){ //se non esiste ancora una miglior giocata (cioè non si è mai giocata una partita)
                printf("Miglior giocata: %d tentativi\n\n", migliorGiocata);
            }

            if(visualizzareContenutoFile(FILENAME_MENU_PRINCIPALE)==1){
                do{
                    fflush(stdin);
                    printf("\nScelta: ");
                    scelta=getchar();
                    fflush(stdin);
                }while(scelta!='0' && scelta!='1' && scelta!='2' && scelta!='3');

                //Per favorire la leggibilita' i seguenti if non sono in cascata else-if
                if(scelta=='1'){
                    giocarePartita();
                }

                if(scelta=='2'){
                    help();
                }

                if(scelta=='3'){
                    crediti();
                }

            }
        }
    }while(scelta!='0');

    return;
}
