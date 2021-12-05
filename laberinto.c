#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"list.h"
#include"laberinto.h"
#include"Map.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


/*
  función para comparar claves de tipo string
  retorna 1 si son iguales
*/

int is_equal_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2)==0) return 1;
    return 0;
}

/*
  función para comparar claves de tipo string
  retorna 1 si son key1<key2
*/

int lower_than_string(void * key1, void * key2) {
    if(strcmp((char*)key1, (char*)key2) < 0) return 1;
    return 0;
}

/*
  función para comparar claves de tipo int
  retorna 1 si son iguales
*/

int is_equal_int(void * key1, void * key2) {
    if(*(int*)key1 == *(int*)key2) return 1;
    return 0;
}

/*
  función para comparar claves de tipo int
  retorna 1 si son key1<key2
*/

int lower_than_int(void * key1, void * key2) {
    if(*(int*)key1 < *(int*)key2) return 1;
    return 0;
}

Jugador* crearJugador(int * vida, int * daño){
  Jugador* nuevo = (Jugador*) malloc(sizeof(Jugador));
  nuevo->vida=1;
  nuevo->daño=1;
  return nuevo;
}

void agregarJugador(List * listaJugador, int * vida, int * daño){
    Jugador* nuevo = crearJugador(vida,daño);
    if(firstList(listaJugador)==NULL)pushFront(listaJugador,nuevo);
    else pushBack(listaJugador,nuevo);
    printf("*Jugador creado con exito*");
    printf("\n");
    printf(ANSI_COLOR_RED"❤ Vida: %d"ANSI_COLOR_RESET, nuevo->vida);
    printf("\n");
    printf(ANSI_COLOR_BLUE"⚔ Daño: %d"ANSI_COLOR_RESET, nuevo->daño);
    printf("\n");
}

Caballero* crearCaballero(int * vida, int * daño){
  Caballero* nuevo2 = (Caballero*) malloc(sizeof(Caballero));
  nuevo2->vida=5;
  nuevo2->daño=1;
  return nuevo2;
}

void agregarCaballero(List * listaJugador, int * vida, int * daño){
    Caballero* nuevo2 = crearCaballero(vida,daño);
    if(firstList(listaJugador)==NULL)pushFront(listaJugador,nuevo2);
    else pushBack(listaJugador,nuevo2);
    printf("*Jugador creado con exito*");
    printf("\n");
    printf(ANSI_COLOR_RED"❤ Vida: %d"ANSI_COLOR_RESET, nuevo2->vida);
    printf("\n");
    printf(ANSI_COLOR_BLUE"⚔ Daño: %d"ANSI_COLOR_RESET, nuevo2->daño);
    printf("\n");
}

Ninja* crearNinja(int * vida, int * daño){
  Ninja* nuevo3 = (Ninja*) malloc(sizeof(Ninja));
  nuevo3->vida=2;
  nuevo3->daño=3;
  return nuevo3;
}

void agregarNinja(List * listaJugador, int * vida, int * daño){
    Ninja* nuevo3 = crearNinja(vida,daño);
    if(firstList(listaJugador)==NULL)pushFront(listaJugador,nuevo3);
    else pushBack(listaJugador,nuevo3);
    printf("*Jugador creado con exito*");
    printf("\n");
    printf(ANSI_COLOR_RED"❤ Vida: %d"ANSI_COLOR_RESET, nuevo3->vida);
    printf("\n");
    printf(ANSI_COLOR_BLUE"⚔ Daño: %d"ANSI_COLOR_RESET, nuevo3->daño);
    printf("\n");

}

Monstruo* crearMonstruo(int * vida, int * daño){
  Monstruo* pelea1 = (Monstruo*) malloc(sizeof(Monstruo));
  pelea1->vida=1;
  pelea1->daño=1;
  return pelea1;
}

void agregarMonstruo(List * listaMonstruo, int * vida, int * daño){
    Monstruo* pelea1 = crearMonstruo(vida,daño);
    if(firstList(listaMonstruo)==NULL)pushFront(listaMonstruo,pelea1);
    else pushBack(listaMonstruo,pelea1);
    printf("*Monstruo creado con exito*");
    printf("\n");
    printf("❤ Vida: %d", pelea1->vida);
    printf("\n");
    printf("⚔ Daño: %d", pelea1->daño);
    printf("\n");
}

Monstruo2* crearMonstruo2(int * vida, int * daño){
  Monstruo2* pelea2 = (Monstruo2*) malloc(sizeof(Monstruo2));
  pelea2->vida=3;
  pelea2->daño=1;
  return pelea2;
}

void agregarMonstruo2(List * listaMonstruo, int * vida, int * daño){
    Monstruo2* pelea2 = crearMonstruo2(vida,daño);
    if(firstList(listaMonstruo)==NULL)pushFront(listaMonstruo,pelea2);
    else pushBack(listaMonstruo,pelea2);
    printf("*Monstruo2 creado con exito*");
    printf("\n");
    printf("❤ Vida: %d", pelea2->vida);
    printf("\n");
    printf("⚔ Daño: %d", pelea2->daño);
    printf("\n");
}

Monstruo3* crearMonstruo3(int * vida, int * daño){
  Monstruo3* pelea3 = (Monstruo3*) malloc(sizeof(Monstruo3));
  pelea3->vida=5;
  pelea3->daño=1;
  return pelea3;
}

void agregarMonstruo3(List * listaMonstruo, int * vida, int * daño){
    Monstruo3* pelea3 = crearMonstruo3(vida,daño);
    if(firstList(listaMonstruo)==NULL)pushFront(listaMonstruo,pelea3);
    else pushBack(listaMonstruo,pelea3);
    printf("*Monstruo3 creado con exito*");
    printf("\n");
    printf("❤ Vida: %d", pelea3->vida);
    printf("\n");
    printf("⚔ Daño: %d", pelea3->daño);
    printf("\n");
}

Usuario* crearUsuario(char* nick) {
  Usuario* u = (Usuario*) malloc (sizeof(Usuario));
	strcpy(u->nick, nick);
  return u;
}

void agregarUsuario(Map *usuario){

  Usuario *b=NULL;

  b = malloc(sizeof(Usuario));

  printf(ANSI_COLOR_YELLOW"______________________\n\n");
        printf("Preparando su registro\n");
        printf("______________________\n\n");
        printf("-Utilice un maximo de 20 caracteres contando espacios-\n\n");
        printf("Ingrese su Nick de usuario: "ANSI_COLOR_CYAN);

  scanf(" %[^\n]", b->nick);

  insertMap(usuario, b->nick, b);

}

void registroUsuario(Map * usuario){

  Usuario *b=NULL;

  char busca_Nombre[20];

  printf("Ingrese su Nick de usuario: ");
  scanf(" %[^\n]",busca_Nombre);

  b = firstMap(usuario);

  while (b!=NULL){

    if (strcmp(busca_Nombre,b->nick)==0){

      printf(ANSI_COLOR_GREEN"___________________________________\n");
          printf("\nHas iniciado sesion correctamente\n");
          printf("\nBienvenido %s\n",b->nick);
          printf("___________________________________\n\n");
          }
          else{
          printf(ANSI_COLOR_RED"______________________\n\n");
          printf("Este usuario no existe\n");
          printf("______________________\n\n\n\n");
          }

     break;
    
    
    b=nextMap(usuario);

  }


}
