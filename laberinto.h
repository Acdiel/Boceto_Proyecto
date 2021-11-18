#ifndef Laberinto_h
#define Laberinto_h
#include "list.h"

typedef struct{
  int vida;
  int daño;
  char objetos[30];
}Jugador;

typedef struct{
  int vida;
  int daño;
}Monstruo;

Jugador* crearJugador(int * vida, int * daño, char * objetos);

Monstruo* crearMonstruo(int * vida, int * daño);

void agregarJugador(List * list, int * vida, int * daño, char * objetos);

void agregarMonstruo(List * list, int * vida, int * daño);

void BuscarCancionxNombre(List* list, char* nombre);

#endif /* Laberinto_h*/