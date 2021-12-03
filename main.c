#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "laberinto.h"
#include "Map.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

const char *get_csv_field (char * tmp, int k) {
  int open_mark = 0;
  char* ret=(char*) malloc (1000*sizeof(char));
  int ini_i=0, i=0;
  int j=0;
  while(tmp[i+1]!='\1'){

    if(tmp[i]== '\"'){
        open_mark = 1-open_mark;
        if(open_mark) ini_i = i+1;
        i++;
        continue;
    }

    if(open_mark || tmp[i]!= ','){
        if(k==j) ret[i-ini_i] = tmp[i];
        i++;
        continue;
    }

    if(tmp[i]== ','){
      if(k==j) {
        ret[i-ini_i] = 0;
        return ret;
      }
      j++; ini_i = i+1;
    }

    i++;
  }

  if(k==j) {
      ret[i-ini_i] = 0;
      return ret;
  }


  return NULL;
}

int main(void) {

   // MAPA CON CLAVE USUARIO //
Map* usuario = createMap(is_equal_string);
setSortFunction(usuario, lower_than_string);

  int vida;
  int daño;
  char objetos[30];
  char accion;
  char personaje[20];
  char linea[1024];  
  char Personaje_Principal;
  char Caballero;
  char Ninja;
  int contra;

  Jugador* nuevo;
  
  List * listaJugador;
  listaJugador = createList();

  List *result = createList();
  


  int op=10;

    while (op!=0) 
    {   
    printf("\n"); 
		printf(ANSI_COLOR_RED "       👻 Laberinto del Terror 2 👻       " ANSI_COLOR_RESET "\n");
    printf("--------------------------------------------\n");
    printf(ANSI_COLOR_BLUE " 1. Registrarse                           \n");
    printf( " 2. Iniciar Sesion                        \n");
		printf( " 3. Elegir Personaje                      \n");
		printf( " 4. Comenzar el Juego                    "ANSI_COLOR_RESET "\n");
    printf("--------------------------------------------\n");
    printf("| ⏬ Indica la opción ⏬                   |\n");
    printf("-------------------------------------------\n");
		printf("👉 "); scanf("%d", &op);
    printf("\n");

    FILE * dibujo =  fopen("dibujo.txt", "r");
    FILE * personajes =  fopen("personajes.txt", "r");

switch (op) 
    {
      case 1:

        agregarUsuario(usuario);

      break;

      case 2:

       registroUsuario(usuario);

          break;

      case 3:
    printf("--------------------------------------------\n");  
		printf("|       🧙‍♂️  Elige el Personaje 🧙‍♂️        |\n");
    printf("--------------------------------------------\n");

    while(fgets(linea,1024,personajes)!=NULL){
    printf("%s",linea);
    }

   printf("\n");
   printf("\n¿Cual escoges?: "); scanf("%s", personaje);


      break;

      

   case 4:

while(fgets(linea,1024,dibujo)!=NULL){
  printf("%s",linea);
}

printf("\n");
printf("SE PUEDE APRECIAR COMO UN MUCHACHO CAMINA PERDIDO POR EL BOSQUE");
printf("\n");
printf("EL MUCHACHO ENCUENTRA UNA ESCALERA EN MEDIO DEL CAMINO Y LA USA PARA BAJAR");
printf("\n");
printf("\n");
printf("\nAL BAJAR SE ENCUENTRA 2 CAMINOS PARA AVANZAR(A SU DERECHA Y EN FRENTE, Y UNA HABITACION A LA IZQUIERDA).");
printf(ANSI_COLOR_RED" ⚠ AL PARECER ESTA EN UN LABERINTO ⚠"ANSI_COLOR_RESET "\n");
printf("\n");

if (strcmp("Personaje_Principal",personaje)==0){
agregarJugador(listaJugador,&vida,&daño,objetos);
}

if (strcmp("Caballero",personaje)==0){
agregarCaballero(listaJugador,&vida,&daño,objetos);
}

if (strcmp("Ninja",personaje)==0){
agregarNinja(listaJugador,&vida,&daño,objetos);
}

printf("\n");
printf("\n¿QUE HACE?: "); scanf("%s",&accion);

}
    }
}