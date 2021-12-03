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
    printf(ANSI_COLOR_RED"❤ Vida: %d"ANSI_COLOR_RESET, nuevo->vida);
    printf("\n");
    printf(ANSI_COLOR_BLUE"⚔ Daño: %d"ANSI_COLOR_RESET, nuevo->daño);
    printf("\n");
    printf(ANSI_COLOR_YELLOW"💼 Objetos: %s"ANSI_COLOR_RESET, nuevo->objetos);
    printf("\n");
}

Caballero* crearCaballero(int * vida, int * daño, char * objetos){
  Caballero* nuevo2 = (Caballero*) malloc(sizeof(Caballero));
  nuevo2->vida=5;
  nuevo2->daño=1;
  strcpy(nuevo2->objetos,"0");
  return nuevo2;
}

void agregarCaballero(List * list, int * vida, int * daño, char * objetos){
    Caballero* nuevo2 = crearCaballero(vida,daño,objetos);
    if(list->head==NULL)pushFront(list,nuevo2);
    else pushBack(list,nuevo2);
    printf("*Jugador creado con exito*");
    printf("\n");
    printf("❤ Vida: %d", nuevo2->vida);
    printf("\n");
    printf("⚔ Daño: %d", nuevo2->daño);
    printf("\n");
    printf("💼 Objetos: %s", nuevo2->objetos);
    printf("\n");
}

Ninja* crearNinja(int * vida, int * daño, char * objetos){
  Ninja* nuevo3 = (Ninja*) malloc(sizeof(Ninja));
  nuevo3->vida=2;
  nuevo3->daño=3;
  strcpy(nuevo3->objetos,"0");
  return nuevo3;
}

void agregarNinja(List * list, int * vida, int * daño, char * objetos){
    Ninja* nuevo3 = crearNinja(vida,daño,objetos);
    if(list->head==NULL)pushFront(list,nuevo3);
    else pushBack(list,nuevo3);
    printf("*Jugador creado con exito*");
    printf("\n");
    printf("❤ Vida: %d", nuevo3->vida);
    printf("\n");
    printf("⚔ Daño: %d", nuevo3->daño);
    printf("\n");
    printf("💼 Objetos: %s", nuevo3->objetos);
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
