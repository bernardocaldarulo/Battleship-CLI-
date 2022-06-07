#ifndef COLORI_H_
#define COLORI_H_

#include <stdio.h>
#include <stdlib.h>

#define ANSI_COLOR_RED "\x1b[31;1m"
#define ANSI_COLOR_GREEN "\x1b[32;1m"
#define ANSI_COLOR_YELLOW "\x1b[33;1m"
#define ANSI_COLOR_CYAN "\x1b[36;1m"
#define ANSI_COLOR_RESET "\x1b[0m"

void red ();
void green();
void yellow();
void cyan();
void reset ();

#endif /* COLORI_H_ */
