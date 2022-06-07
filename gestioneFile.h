#ifndef GESTIONEFILE_H_
#define GESTIONEFILE_H_

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>      //per strerror(errno) in gestioneErroriFile()
#include <string.h>     //per strerror(errno) in gestioneErroriFile()
#include "definizioni.h"


int visualizzareContenutoFile(char * filename);
void help();
void crediti();
void gestioneErroriFile(char * filename, char * errore);

int salvareMigliorGiocata(int migliorGiocata, char * filenameSalvataggio);
int leggereMigliorGiocata(char * filenameSalvataggio);

#endif /* GESTIONEFILE_H_ */
