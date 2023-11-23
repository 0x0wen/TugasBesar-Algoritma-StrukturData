#ifndef COMMAND_UTAS_H
#define COMMAND_UTAS_H

#include "../global.h"
#include "../General/sentenceMachine.h"
#include "../General/wordmachine.h"
void CREATE_UTAS(int IDKicau);
void SAMBUNG_UTAS(int IDUtas, int index);
void HAPUS_UTAS(int IDUtas, int index);
void CETAK_UTAS(int IDUtas);

#endif
