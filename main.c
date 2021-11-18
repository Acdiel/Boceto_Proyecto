#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "laberinto.h"

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

  int vida;
  int daño;
  char objetos[30];
  char accion;
  char personaje[20];
  char linea[1024];  

  Jugador* nuevo;
  
  List * listaJugador;
  listaJugador = createList();

  int op=10;

    while (op!=0) 
    {   
    printf("\n");
    printf("--------------------------------------------\n");  
		printf("|        ✔  Bienvenido al Menú ✔           |\n");
    printf("--------------------------------------------\n");
		printf("| 1. Elegir Personaje                      |\n");
		printf("| 2. Comenzar el Juego                     |\n");
    printf("| ⏬ Indica la opción ⏬                   |\n");
    printf("-------------------------------------------\n");
		printf("👉 "); scanf("%d", &op);
    printf("\n");

    FILE * dibujo =  fopen("dibujo.txt", "r");
    FILE * caballero =  fopen("caballero.txt", "r");

switch (op) 
    {

      case 1:
    printf("--------------------------------------------\n");  
		printf("|       🧙‍♂️  Elige el Personaje 🧙‍♂️        |\n");
    printf("--------------------------------------------\n");

    while(fgets(linea,1024,caballero)!=NULL){
    printf("%s",linea);
    }

   printf("\n");
   printf("\n¿Cual escoges?: "); scanf("%s", personaje);


      break;

      

   case 2:

while(fgets(linea,1024,dibujo)!=NULL){
  printf("%s",linea);
}

printf("\n");
printf("SE PUEDE APRECIAR COMO UN MUCHACHO CAMINA PERDIDO POR EL BOSQUE");
printf("\n");
printf("EL MUCHACHO ENCUENTRA UNA ESCALERA EN MEDIO DEL CAMINO Y LA USA PARA BAJAR");
printf("\n");
printf("\n");
printf("\nAL BAJAR SE ENCUENTRA 2 CAMINOS PARA AVANZAR(A SU DERECHA Y EN FRENTE, Y UNA HABITACION A LA IZQUIERDA). ⚠ AL PARECER ESTA EN UN LABERINTO ⚠\n");
printf("\n");

agregarJugador(listaJugador,&vida,&daño,objetos);
printf("\n");
printf("\n¿QUE HACE?: "); scanf("%s",&accion);

}
    }
}