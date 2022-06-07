#ifndef DEFINIZIONI_H_
#define DEFINIZIONI_H_

#define DIM_GIOCO 16                //indica la dimensione scelta delle tabelle di gioco
#define MAX_DIM_NAVE 5              //indica la massima diemensione delle navi da posizionare in tabella difesa
#define MAX_COLPI_LUNGO_RAGGIO 3    //indica il numero massimo di colpi a lungo raggio eseguibili
#define MAX_RADAR 3                 //indica il numero massimo di scansioni radar eseguibili
#define MAX_BOMBARDAMENTO_AEREO 1   //indica il numero massimo di colpi bombardamenti aereo eseguibili
#define MIN_BOMBARDAMENTO_AEREO 20  //indica il numero minimo di turniPartita (solo dopo aver compiuto 10 turniGiocatore) giocati per poter attivare un bombardamento aereo

#define VALORE_INIZIALE_CAMPI_TURNO 1   //indica il valore valore di inizializzazione dei campi della partita che indicano il numero di turno (giocatore e partita)
#define VALORE_INIZIALE_CAMPI_MOSSE 0   //indica il valore valore di inizializzazione dei campi del giocatore che indicano il numero di mosse limitate effettuate
#define ID_GIOCATORE1 1             //valore identificativo del primo giocatore
#define ID_GIOCATORE2 2             //valore identificativo del secondo giocatore

#define ACQUA_DIFESA 0              //indica il contenuto di un quadretto vuoto della tabella difesa
#define ACQUA_MOSSE '_'             //rappresenta il contenuto di un quadretto vuoto della tabella mosse. E' inoltre utilizzato per rappresentare un quadretto tabella in stampa a video
#define NAVE 'N'                    //rappresenta il contenuto di un quadretto occupato da una nave
#define MANCATO_MOSSE '*'           //rappresenta il contenuto di un quadretto vuoto una volta colpito
#define MANCATO_DIFESA 1            //indica il contenuto di un quadretto vuoto di tabellaDifesa una volta colpito
#define COLPITO 'x'                 //rappresenta il contenuto di un quadretto colpito. 
#define COLPITO_AFFONDATO 'X'       //rappresenta il contenuto di un quadretto colpito la cui nave Ã¨ interamente affondata, in tabella mosse. In tabella difesa non importa che sia interamente affondata.
#define RADAR_POSITIVO 'R'          //rappresenta il contenuto di un quadretto scansionato con esito positivo della tabella mosse
#define RADAR_NEGATIVO '/'          //rappresenta il contenuto di un quadretto scansionato con esito negativo della tabella mosse
#define SEPARATORE '|'              //rappresenta il carattere che separa un quadretto dallâ€™altro, per costruire la tabella che verrÃ  stampata a video

#define FILENAME_TITOLO_GIOCO 			"C:\\Users\\michi\\Desktop\\BERNARDO\\One Drive\\OneDrive - Università degli Studi di Bari\\UNIVERSITÀ\\1 ANNO\\1 SEMESTRE\\Programmazione\\.metadata\\battleship_a_colori\\src\\titoloGioco.txt"
#define FILENAME_TITOLO_HELP 			"C:\\Users\\michi\\Desktop\\BERNARDO\\One Drive\\OneDrive - Università degli Studi di Bari\\UNIVERSITÀ\\1 ANNO\\1 SEMESTRE\\Programmazione\\.metadata\\battleship_a_colori\\src\\titoloHelp.txt"
#define FILENAME_TITOLO_CREDITI 		"C:\\Users\\michi\\Desktop\\BERNARDO\\One Drive\\OneDrive - Università degli Studi di Bari\\UNIVERSITÀ\\1 ANNO\\1 SEMESTRE\\Programmazione\\.metadata\\battleship_a_colori\\src\\titoloCrediti.txt"

#define FILENAME_MENU_PRINCIPALE 		"C:\\Users\\michi\\Desktop\\BERNARDO\\One Drive\\OneDrive - Università degli Studi di Bari\\UNIVERSITÀ\\1 ANNO\\1 SEMESTRE\\Programmazione\\.metadata\\battleship_a_colori\\src\\menuPrincipale.txt"
#define FILENAME_MENU_GIOCAREPARTITA 	"C:\\Users\\michi\\Desktop\\BERNARDO\\One Drive\\OneDrive - Università degli Studi di Bari\\UNIVERSITÀ\\1 ANNO\\1 SEMESTRE\\Programmazione\\.metadata\\battleship_a_colori\\src\\menuGiocarePartita.txt"
#define FILENAME_MENU_MOSSE 			"C:\\Users\\michi\\Desktop\\BERNARDO\\One Drive\\OneDrive - Università degli Studi di Bari\\UNIVERSITÀ\\1 ANNO\\1 SEMESTRE\\Programmazione\\.metadata\\battleship_a_colori\\src\\menuMosse.txt"

#define FILENAME_REGOLE 				"C:\\Users\\michi\\Desktop\\BERNARDO\\One Drive\\OneDrive - Università degli Studi di Bari\\UNIVERSITÀ\\1 ANNO\\1 SEMESTRE\\Programmazione\\.metadata\\battleship_a_colori\\src\\regole.txt"
#define FILENAME_LEGENDA 				"C:\\Users\\michi\\Desktop\\BERNARDO\\One Drive\\OneDrive - Università degli Studi di Bari\\UNIVERSITÀ\\1 ANNO\\1 SEMESTRE\\Programmazione\\.metadata\\battleship_a_colori\\src\\legenda.txt"
#define FILENAME_CREDITI 				"C:\\Users\\michi\\Desktop\\BERNARDO\\One Drive\\OneDrive - Università degli Studi di Bari\\UNIVERSITÀ\\1 ANNO\\1 SEMESTRE\\Programmazione\\.metadata\\battleship_a_colori\\src\\crediti.txt"

#define FILENAME_MENU_SALVATAGGIO_PARTITA 		"C:\\Users\\michi\\Desktop\\BERNARDO\\One Drive\\OneDrive - Università degli Studi di Bari\\UNIVERSITÀ\\1 ANNO\\1 SEMESTRE\\Programmazione\\.metadata\\battleship_a_colori\\src\\menuSalvataggioPartita.txt"
#define FILENAME_SALVATAGGIO_PARTITA 			"C:\\Users\\michi\\Desktop\\BERNARDO\\One Drive\\OneDrive - Università degli Studi di Bari\\UNIVERSITÀ\\1 ANNO\\1 SEMESTRE\\Programmazione\\.metadata\\battleship_a_colori\\src\\salvataggioPartita.dat"
#define FILENAME_SALVATAGGIO_MILGLIOR_GIOCATA 	"C:\\Users\\michi\\Desktop\\BERNARDO\\One Drive\\OneDrive - Università degli Studi di Bari\\UNIVERSITÀ\\1 ANNO\\1 SEMESTRE\\Programmazione\\.metadata\\battleship_a_colori\\src\\salvataggioMigliorGiocata.dat"

#define FILENAME_MENU_BOMBARDAMENTO 	"C:\\Users\\michi\\Desktop\\BERNARDO\\One Drive\\OneDrive - Università degli Studi di Bari\\UNIVERSITÀ\\1 ANNO\\1 SEMESTRE\\Programmazione\\.metadata\\battleship_a_colori\\src\\menuBombardamento.txt"

#endif /* DEFINIZIONI_H_*/
