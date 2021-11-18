#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"list.h"
#include"laberinto.h"


Jugador* crearJugador(int * vida, int * daño, char * objetos){
  Jugador* nuevo = (Jugador*) malloc(sizeof(Jugador));
  nuevo->vida=1;
  nuevo->daño=1;
  strcpy(nuevo->objetos,"0");
  return nuevo;
}

void agregarJugador(List * list, int * vida, int * daño, char * objetos){
    Jugador* nuevo = crearJugador(vida,daño,objetos);
    if(list->head==NULL)pushFront(list,nuevo);
    else pushBack(list,nuevo);
    printf("*Jugador creado con exito*");
    printf("\n");
    printf("❤ Vida: %d", nuevo->vida);
    printf("\n");
    printf("⚔ Daño: %d", nuevo->daño);
    printf("\n");
    printf("💼 Objetos: %s", nuevo->objetos);
    printf("\n");
}

