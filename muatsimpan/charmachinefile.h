#ifndef __CHAR_MACHINE_FILE_H__
#define __CHAR_MACHINE_FILE_H__


#include "../General/boolean.h"
#include "../General/charmachine.h"
#include <stdio.h>

#define MARK_FILE '\n'

/* Char Engine State*/
extern char currentCharFile;
extern boolean eotFile;

void STARFILE(char namaFile[]);

void ADVFILE();

void ENDFILE();

#endif