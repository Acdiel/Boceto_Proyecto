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
  char objetos[30];
}Caballero;

typedef struct{
  int vida;
  int daño;
  char objetos[30];
}Ninja;

typedef struct{
  int vida;
  int daño;
}Monstruo;

Jugador* crearJugador(int * vida, int * daño, char * objetos);

Caballero* crearCaballero(int * vida, int * daño, char * objetos);

Ninja* crearNinja(int * vida, int * daño, char * objetos);

Monstruo* crearMonstruo(int * vida, int * daño);

void agregarJugador(List * list, int * vida, int * daño, char * objetos);

void agregarCaballero(List * list, int * vida, int * daño, char * objetos);

void agregarNinja(List * list, int * vida, int * daño, char * objetos);

void BuscarCancionxNombre(List* list, char* nombre);

#endif /* Laberinto_h*/