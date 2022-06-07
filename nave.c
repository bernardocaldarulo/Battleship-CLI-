#include "nave.h"

/**
 * @brief Funzione che richiede un indice di riga. E' principalmente utilizzata per posizionare una nave nella tabella difesa del giocatore.
 *
 * @return int riga>0 and riga<=DIM_GIOCO
 */
int richiedereRiga(){
    int riga;
    char ch;
    int i;
    char cifre[2];  //[2] con due cifre perché il campo da gioco avrà DIM_GIOCO sicuramente rappresentabile in una o due cifre
    i=0;

    do{
        fflush(stdin);
        printf("Riga: ");
        ch=getchar();

        if(ch=='\n'){
            riga=-1;    //inserimento vuoto
        }else{
            riga=1;
        }

        while(ch!='\n' && i<2 && riga==1){  //i<2, quindi se il numero ha più di due cifre sarà troncato alle prime due cifre
            //prendiamo il corrispettivo di ch in tabella ascii in modo da escludere l'inserimento di caratteri che non sono cifre
            if((int)ch>=48 && (int)ch<=57){ //se ciascuna cifra inserita è numerica
                cifre[i]=ch;
            }else{
                riga=-1;
            }

            ch=getchar();
            i++;
        }

        if(riga==1){
            sscanf(cifre, "%d", &riga);    //conversione da cifre (caratteri) in riga (intero)
        }
        fflush(stdin);
    }while (riga <= 0 || riga > DIM_GIOCO);    //la riga inserita dovrà rispettare i limiti del campo di gioco
    return riga;
}

/**
 * @brief Funzione che richiede un indice di colonna. E' principalmente utilizzata per posizionare una nave nella tabella difesa del giocatore.
 *
 * @return int colonna>0 and colonna<=DIM_GIOCO
 */
int richiedereColonna(){
    int colonnaConvertita;
    char colonna;
    do{
        fflush(stdin);
        printf("Colonna: ");
        //scanf(" %c", &colonna);
        colonna = getchar();
        fflush(stdin);
        /*
        * convertireColonnaInNumero() associa al valore di colonna fornito, la sua posizione all'interno dell'alfabeto.
        * Infatti, l'utilizzo di caratteri per rappresentare la colonna è solo un'astrazione,
        *   mentre in memoria l'indice di colonna è numerico (compatibilmente con una matrice).
        */
        colonnaConvertita=convertireColonnaInNumero(colonna);
    }while (colonnaConvertita <= 0 || colonnaConvertita > DIM_GIOCO);   //la colonna inserita dovrà rispettare i limiti del campo di gioco
    return colonnaConvertita;
}

/**
 * @brief Funzione che associa al valore di colonna fornito, la sua posizione all'interno dell'alfabeto.
 *
 * @param colonna valore di colonna, di una qualunque tabella
 * @return int pos La funzione restituisce il valore numerico associato ala colonna fornita. pos=-1 nel caso in cui il carattere fornito non sia valido.
 */
int convertireColonnaInNumero(char colonna){
    int pos;
    int trovato;
    pos=0;
    trovato=0;
    const char ALFABETO[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    /*
    * La funzione toupper() prende un carattere (maiuscolo o minuscolo) e lo converte in un carattere maiuscolo.
    * Se l'argomento passato alla funzione toupper() è un carattere già maiuscolo,
    *   restituisce lo stesso carattere passato alla funzione.
    * La necessità di tale operazione nasce dalla possibilità che l'utente inserisca una lettera maiuscola o minuscola come indice di colonna.
    */
    colonna = toupper(colonna);
    //ricerca del carattere nell'alfabeto
    while(pos<DIM_GIOCO && trovato==0){
        if(ALFABETO[pos]==colonna){
            trovato=1;
        }
        pos++;
    }
    if(trovato==0){
        pos = -1; //nel caso di colonna non alfabetica, pos=-1.
    }

    return pos;
}

/**
 * @brief Funzione che verifica se la dimensione della nave è stata rispettata dalle coordinate di inizio e fine specificate.
 *
 * @param rInizio riga della coordinata di inizio
 * @param cInizio colonna della coordinata di inizio
 * @param rFine riga della coordinata di fine
 * @param cFine colonna della coordinata di fine
 * @param dimensione dimensione della nave
 * @return int esito=0 (dimensione non rispettata), esito=1 (dimensione rispettata), esito=-1 (parametri non validi)
 */
int verificareDimensione(int rInizio, int cInizio, int rFine, int cFine, int dimensione){
    int esito;

    //le righe e le colonne dovranno rispettare i limiti imposti dal campo di gioco
    if(rInizio>0 && cInizio>0 && rFine>0 && cFine>0 && dimensione>0 && rInizio<=DIM_GIOCO && cInizio<=DIM_GIOCO && rFine<=DIM_GIOCO && cFine<=DIM_GIOCO && dimensione<=MAX_DIM_NAVE){
        //è applicato il valore assoluto mediante abs() poiché non è possibile conoscere la relazione d'ordine fra le righe o le colonne.
        if((abs(rInizio-rFine)+1)==dimensione || (abs(cInizio-cFine)+1)==dimensione){
            esito=1;
        }else{
            esito=0;
        }
    }else{
        esito=-1;
    }

    return esito;
}

/**
 * @brief Funzione che verifica se la se la nave verrebbe posizionata in diagonale, in base alle coordinate di inizio e fine specificate.
 *
 * @param rInizio riga della coordinata di inizio
 * @param cInizio colonna della coordinata di inizio
 * @param rFine riga della coordinata di fine
 * @param cFine colonna della coordinata di fine
 * @return int esito=0 (diagonale non verificata), esito=1 (diagonale verificata), esito=-1 (parametri non validi)
 */
int verificareDiagonale(int rInizio, int cInizio, int rFine, int cFine){
    int esito;
    //le righe e le colonne dovranno rispettare i limiti imposti dal campo di gioco
    if(rInizio>0 && cInizio>0 && rFine>0 && cFine>0 && rInizio<=DIM_GIOCO && cInizio<=DIM_GIOCO && rFine<=DIM_GIOCO && cFine<=DIM_GIOCO){
        //i due possibili orientamenti sono orizzontale e verticale, ciò implica che rimanga ferma la riga (orizzontale) oppure la colonna (verticale)
        if(rInizio==rFine || cInizio==cFine){
            esito=0;
        }else{
            esito=1;
        }
    }else{
        esito=-1;   //nel caso in cui non si rispettino i limiti di gioco
    }
    return esito;
}

/**
 * @brief Funzione che verifica se la se nave la nave verrebbe posizionata sovrapponendosi (anche parzialmente) ad altre navi, in base alle coordinate di inizio e fine specificate.
 *
 * @param g giocatore di cui si vuole verificare la sovrapposizione della nave che si intende inserire nella rispettiva tabella di difesa
 * @param rInizio riga della coordinata di inizio
 * @param cInizio colonna della coordinata di inizio
 * @param rFine riga della coordinata di fine
 * @param cFine colonna della coordinata di fine
 * @return int esito = 0 (non si verifica alcuna sovrapposizione), esito = 1 (si verifica una sovrapposizione), anche parzialmente sullo spazio di raggio 1 di altre navi

 */
int verificareSovrapposizione(giocatore g, int rInizio, int cInizio, int rFine, int cFine){
    int esito;  //determina il verificarsi o meno di una sovrapposizione ad altre navi rispetto a quella da inserire, rappresentata tramite coordInizio e coordFine avente dimensione specificata
    int inizio; //indica la riga (se la nave si troverebbe in verticale) o la colonna (se la nave si trovasse in orizzontale) della coordinata iniziale della nave
    int fine;   //indica la riga (se la nave si troverebbe in verticale) o la colonna (se la nave si trovasse in orizzontale) della coordinata finale della nave
    int r;  //rappresenta la riga di inizio effettiva della nave
    int c;  //rappresenta la colonna di inizio effettiva della nave
    int orizzontale;    //indica se la nave sarà posizionata in maniera orizzontale (o meno)  in tabellaDifesa
    int i;
    int j;
    int idNave; //rappresenta il contenuto del quadretto in riga r e colonna c di tabellaDifesa
    esito=0;

    /*
    * MECCANISMO DI FUNZIONAMENTO: viene individuato l'orientamento della nave.
    *   Essendo l'utente libero di inserire le coordinate limite della nave in qualunque ordine (ES. (1,a)(1,c) è equivalente a (1,c)(1,a)),
    *   è necessario gestire entrambe le possibilità:
    *   cioè che si inserisca prima quella iniziale e poi la finale, o viceversa. Per rendere il codice funzionante in entrambi i casi,
    *   senza doverlo replicare con lievi modifiche, è necessario ricercare la coordinata limite di "inizio" più piccola.
    */
    //le righe e le colonne dovranno rispettare i limiti imposti dal campo di gioco
    if(rInizio>0 && cInizio>0 && rFine>0 && cFine>0 && rInizio<=DIM_GIOCO && cInizio<=DIM_GIOCO && rFine<=DIM_GIOCO && cFine<=DIM_GIOCO){
        if(rInizio==rFine){    //poiche la riga rimane fissa,l'ordinamento della nave è orizzontale
            if(cInizio<cFine){  //ricerca della colonna più piccola e più grande, poiché si è deciso di proseguire per incrementi nel ciclo successivo
                inizio=cInizio; // comporrà la coordinata (r,inizio)
                fine=cFine;     // comporrà la coordinata (r,fine)
            }else{
                inizio=cFine;   // comporrà la coordinata (r,inizio)
                fine=cInizio;   // comporrà la coordinata (r,fine)
            }
            r=rInizio;          //salviamo il contenuto di rInizio in r
            orizzontale=1;      //indica che l'utente ha intenzione di posizionare la nave in orizzontale
        }else{                  //poiche la colonna rimane fissa e quindi l'ordinamento della nave è verticale
            if(rInizio<rFine){  //ricerca della riga più piccola e più grande, poiché si è deciso di proseguire per incrementi nel ciclo successivo
                inizio=rInizio; // comporrà la coordinata (c,inizio)
                fine=rFine;     // comporrà la coordinata (c,fine)
            }else{
                inizio=rFine;   // comporrà la coordinata (c,inizio)
                fine=rInizio;   // comporrà la coordinata (c,fine)
            }
            c=cInizio;          //salviamo il contenuto di cInizio in c
            orizzontale=0;      //indica che l'utente ha intenzione di posizionare la nave in verticale
        }

        /* Poichè è possibile posizionare una nave solo se nel raggio di 1 del suo perimetro non è presente un' altra nave,
        *  è necessario controllare nel caso in cui la nave deve essere posta in orizzontale(quindi la riga relativa alla nave è fissa) che,
        *  nelle celle della sotto-matrice di coordinate (r-1,inizio-1) --> (r+1,fine+1), non sia presente una nave.
        */

        if(orizzontale==1){ //se l'ordinamento della nave è orizzontale
            i=r-1;  //i controlli partono dalla riga precedente a r
            while(i<=r+1 && esito==0){  //i controlli finiscono nella riga successiva rispetto a r
                j=inizio-1; //i controlli partono dalla colonna precedente a inizio(colonna più "piccola")
                while(j<=fine+1 && esito==0){   //i controlli finiscono nella colonna successiva a fine(colonna più "grande")
                    if((j>0 && j<=DIM_GIOCO) && (i>0 && i<=DIM_GIOCO)){ //nel caso in cui gli indici escono fuori dal campo, non si effettua alcun controllo
                        idNave = leggereTabellaDifesa(g,i,j);
                        /*if(idNave==0 && esito==0){
                            esito=0;
                        }else{
                            esito=1;
                        }*/

                        if(idNave!=0){
                            esito=1;
                        }
                    }
                    j++;
                }
                i++;
            }
        }else{  //se l'ordinamento della nave è verticale

        /* Poichè è possibile posizionare una nave solo se nel raggio di 1 del suo perimetro non è presente un' altra nave,
        *  è necessario controllare nel caso in cui la nave deve essere posta in verticale(quindi la colonna relativa alla nave è fissa) che,
        *  nelle celle della sotto-matrice di coordinate (inizio-1,c-1) --> (fine+1,c+1), non sia presente una nave.
        */
            i=inizio-1;// i controlli partono dalla riga precedente a inizio(riga più "piccola")
            while (i<=fine+1 && esito==0){ // i controlli finiscono nella riga successiva a fine(riga più "grande")
                j=c-1; //i controlli partono dalla colonna precedente a c
                while(j<=c+1 && esito==0){ // i controlli finiscono nella colonna successiva a c
                    if((j>0 && j<=DIM_GIOCO) && (i>0 && i<=DIM_GIOCO)){ //nel caso in cui gli indici escono fuori dal campo, non si effettua alcun controllo
                        idNave=leggereTabellaDifesa(g,i,j);
                        /*if(idNave==0 && esito==0){
                            esito=0;
                        }else{
                            esito=1;
                        }*/

                        if(idNave!=0){
                            esito=1;
                        }
                    }
                    j++;
                }
                i++;
            }
        }
    }else{
        esito=-1;
    }
    return esito;
}

/**
 * @brief Funzione che calcola il numero di frammenti non colpiti di una nave specificata tramite idNave.
 *
 * @param g giocatore nella cui tabella difesa ricercare una nave avente idNave
 * @param idNave identificativo della nave da ricercare
 * @return int frammentiNonColpiti
 */
int calcolareNumeroFrammentiNonColpiti(giocatore g , int idNave){
    int i;
    int j;
    int frammentiNonColpiti;
    frammentiNonColpiti=0;

    i=1;
    while(i<=DIM_GIOCO){
        j=1;
        while(j<=DIM_GIOCO){
            if(leggereTabellaDifesa(g,i,j)==idNave){
                frammentiNonColpiti++;  //incremento il numero di frammenti non colpiti della nave
            }
            j++;
        }
        i++;
    }

    return frammentiNonColpiti;
}

/**
 * @brief Funzione che verifica la presenza di frammenti di navi all'intero della tabella di difesa del giocatore,
 *  al fine di determinare se vi sono state affondate tutte le navi o meno.
 *
 * @param g giocatore di cui determinare se vi sono state affondate tutte le navi o meno
 * @return int esito=1 (ci sono ancora frammenti di navi da colpire), esito=0 (il giocatore ha perso)
 */
int verificarePresenzaFrammentiNavi(giocatore g){
    int i;
    int j;
    int esito;
    i=1;
    esito=0;
    //Ricorda: idNave=0 acqua, idNave=1 colpo mancato, id>=2 frammento di nave, id<=-2 frammento di nave colpito.
    while(i<=DIM_GIOCO && esito==0){
        j=1;
        while(j<=DIM_GIOCO && esito==0){
            if(leggereTabellaDifesa(g,i,j)>=2){ //se c'è almeno un frammmento l'esito è 1
                esito=1;
            }
            j++;
        }
        i++;
    }
    return esito;
}
