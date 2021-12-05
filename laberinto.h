#ifndef Laberinto_h
#define Laberinto_h
#include "list.h"
#include "Map.h"

typedef struct{
  int vida;
  int daño;
}Jugador;

typedef struct{
  int vida;
  int daño;
}Caballero;

typedef struct{
  int vida;
  int daño;
}Ninja;

typedef struct{
  int vida;
  int daño;
}Monstruo;

typedef struct{
  int vida;
  int daño;
}Monstruo2;

typedef struct{
  int vida;
  int daño;
}Monstruo3;

int is_equal_int(void * key1, void * key2);

int lower_than_int(void * key1, void * key2);

int is_equal_string(void * key1, void * key2);

int lower_than_string(void * key1, void * key2);

Jugador* crearJugador(int * vida, int * daño);

Caballero* crearCaballero(int * vida, int * daño);

Ninja* crearNinja(int * vida, int * daño);

Monstruo* crearMonstruo(int * vida, int * daño);

Monstruo2* crearMonstruo2(int * vida, int * daño);

Monstruo3* crearMonstruo3(int * vida, int * daño);

void agregarMonstruo(List * listaMonstruo, int * vida, int * daño);

void agregarMonstruo2(List * listaMonstruo, int * vida, int * daño);

void agregarMonstruo3(List * listaMonstruo, int * vida, int * daño);

void agregarJugador(List * list, int * vida, int * daño);

void agregarCaballero(List * list, int * vida, int * daño);

void agregarNinja(List * list, int * vida, int * daño);

void BuscarCancionxNombre(List* list, char* nombre);

Usuario* crearUsuario(char* nick);

void agregarUsuario(Map *usuario);

void registroUsuario(Map * usuario);



#endif /* Laberinto_h*/