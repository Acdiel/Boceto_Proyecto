#ifndef Laberinto_h
#define Laberinto_h
#include "list.h"
#include "Map.h"

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

int is_equal_int(void * key1, void * key2);

int lower_than_int(void * key1, void * key2);

int is_equal_string(void * key1, void * key2);

int lower_than_string(void * key1, void * key2);

Jugador* crearJugador(int * vida, int * daño, char * objetos);

Caballero* crearCaballero(int * vida, int * daño, char * objetos);

Ninja* crearNinja(int * vida, int * daño, char * objetos);

Monstruo* crearMonstruo(int * vida, int * daño);

void agregarJugador(List * list, int * vida, int * daño, char * objetos);

void agregarCaballero(List * list, int * vida, int * daño, char * objetos);

void agregarNinja(List * list, int * vida, int * daño, char * objetos);

void BuscarCancionxNombre(List* list, char* nombre);

Usuario* crearUsuario(char* nick);

void agregarUsuario(Map *usuario);

void registroUsuario(Map * usuario);



#endif /* Laberinto_h*/