#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "laberinto.h"
#include "Map.h"

// CUANDO COMIENZE EL JUEGO, SACAR LOS STATS DE LOS MONSTRUOS QUE APARECEN EN PANTALLA

/* SI EL USUARIO ESCRIBE UN NOMBRE MAL EN LA ELECCION DE PERSONAJES
 QUE VUELVA A PEDIRLE INGRESAR UNO*/

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

//typedef struct Node Node;

void imprimir_muro(int lineas);
void imprimir_muro2(int lineas);
void imprimir_muro3(int lineas);
void genera_pasillo1(List *muros1, muro *partes1);
void genera_pasillo2(List *muros2, muro *partes2);
void genera_pasillo3(List *muros3, muro *partes3);
void imprimir_pasillo(muro * lugar_jugador, List *muros, int avanzar,char *linea);
void imprimir_pasillo_atras(muro * lugar_jugador, List *muros, int avanzar,char *linea);


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
  char Nerd;
  char Caballero;
  char Ninja;
  int contra;
  int personaje_existe = 0;
  int inicio_sesion_juego = 0;

  Jugador* nuevo;
  Jugador* nuevo2;
  Jugador* nuevo3;
  
  List * listaJugador;
  listaJugador = createList();

  List * listaMonstruo;
  listaMonstruo = createList();

  List *result = createList();

  List * muros = createList();
  List * muros2 = createList();
  List * muros3 = createList();

  muro * partes = NULL;
  muro * partes2 = NULL;
  muro * partes3 = NULL;


  genera_pasillo1(muros, partes);
  genera_pasillo2(muros2, partes2);
  genera_pasillo3(muros3, partes3);

  muro* lugar_jugador = firstList(muros);

  lugar_jugador->visita=1;

  int avanzar = 0;

  int fin = 0;
  

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

       inicio_sesion_juego=1;

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

   personaje_existe=1;


      break;

      

   case 4:
   
if(personaje_existe==0){
  printf(ANSI_COLOR_RED"_________________________________\n\n");
          printf("⚠ ESCOGE UN PERSONAJE PRIMERO ⚠\n");
          printf("_________________________________\n\n\n\n");
          
  break;
}

  if(inicio_sesion_juego==0){
  printf(ANSI_COLOR_RED"_________________________________\n\n");
          printf("    ⚠ INICIA SESION PRIMERO ⚠\n");
          printf("_________________________________\n\n\n\n");
          
  break;
}

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

if (strcmp("Nerd",personaje)==0){
agregarJugador(listaJugador,&vida,&daño);
}

if (strcmp("NERD",personaje)==0){
agregarJugador(listaJugador,&vida,&daño);
}

if (strcmp("nerd",personaje)==0){
agregarJugador(listaJugador,&vida,&daño);
}

if (strcmp("Caballero",personaje)==0){
agregarCaballero(listaJugador,&vida,&daño);
}

if (strcmp("CABALLERO",personaje)==0){
agregarCaballero(listaJugador,&vida,&daño);
}

if (strcmp("caballero",personaje)==0){
agregarCaballero(listaJugador,&vida,&daño);
}

if (strcmp("Ninja",personaje)==0){
agregarNinja(listaJugador,&vida,&daño);
}

if (strcmp("NINJA",personaje)==0){
agregarNinja(listaJugador,&vida,&daño);
}

if (strcmp("ninja",personaje)==0){
agregarNinja(listaJugador,&vida,&daño);
}

printf("\n");

agregarMonstruo(listaMonstruo, &vida, &daño);
agregarMonstruo2(listaMonstruo, &vida, &daño);
agregarMonstruo3(listaMonstruo, &vida, &daño);

printf("\n");

printf("\n"); 
  printf("\n");

  while(fin==0){

    if (lugar_jugador->indice==1){

      printf(ANSI_COLOR_YELLOW"╔══════════╗"ANSI_COLOR_RESET "\n");
      printf(ANSI_COLOR_YELLOW"║ Acciones ║"ANSI_COLOR_RESET "\n");
                              
      printf(ANSI_COLOR_YELLOW"╠══════════╩═══════╦═══════════════════╗"ANSI_COLOR_RESET "\n");
      printf(ANSI_COLOR_YELLOW"║"ANSI_COLOR_RESET""ANSI_COLOR_BLUE"(1)"ANSI_COLOR_RESET""" Para Avanzar" ANSI_COLOR_YELLOW "  ║"ANSI_COLOR_RESET""ANSI_COLOR_BLUE " (3)"ANSI_COLOR_RESET" Para Ver Mapa "ANSI_COLOR_YELLOW"║" ANSI_COLOR_RESET"\n");
      printf(ANSI_COLOR_YELLOW"╚══════════════════╩═══════════════════╝"ANSI_COLOR_RESET "\n");
    }

    else{
      printf(ANSI_COLOR_YELLOW"╔══════════╗"ANSI_COLOR_RESET "\n");
      printf(ANSI_COLOR_YELLOW"║ Acciones ║"ANSI_COLOR_RESET "\n");                     
      printf(ANSI_COLOR_YELLOW"╠══════════╩═══════╦════════════════════╗"ANSI_COLOR_RESET "\n");
      printf(ANSI_COLOR_YELLOW"║"ANSI_COLOR_RESET""ANSI_COLOR_BLUE"(1)"ANSI_COLOR_RESET""" Para Avanzar" ANSI_COLOR_YELLOW "  ║"ANSI_COLOR_RESET""ANSI_COLOR_BLUE "(2)"ANSI_COLOR_RESET" Para Retroceder "ANSI_COLOR_YELLOW"║" ANSI_COLOR_RESET"\n");
      printf(ANSI_COLOR_YELLOW"╠══════════════════╩════════════════════╣"ANSI_COLOR_RESET "\n");
      printf(ANSI_COLOR_YELLOW"║"ANSI_COLOR_RESET""ANSI_COLOR_BLUE"            (3)"ANSI_COLOR_RESET" Ver Mapa   "ANSI_COLOR_YELLOW "            ║"ANSI_COLOR_RESET"\n");
      printf(ANSI_COLOR_YELLOW"╚═══════════════════════════════════════╝"ANSI_COLOR_RESET "\n");

    }
    
    printf("\n");

    printf("👉 ");scanf("%d",&avanzar);

    

/////////////////////////////////////////////
    if (avanzar==1){
      if (lugar_jugador->pasillo==1){
        lugar_jugador=nextList(muros);

        if (lugar_jugador->pelea==1){
          

        }


      imprimir_pasillo(lugar_jugador,muros,avanzar,linea);
      }

      if (lugar_jugador->pasillo==2){
        lugar_jugador=nextList(muros2);
      imprimir_pasillo(lugar_jugador,muros2,avanzar,linea);
      }

      if (lugar_jugador->pasillo==3){
        lugar_jugador=nextList(muros3);
      imprimir_pasillo(lugar_jugador,muros3,avanzar,linea);
      }

    }
////////////////////////////////////////

  if (avanzar == 2 && lugar_jugador->indice!=1){

    if (lugar_jugador->pasillo==1){
    lugar_jugador = prevList(muros);
    imprimir_pasillo(lugar_jugador,muros,avanzar,linea);
    }

    if (lugar_jugador->pasillo==2){
    lugar_jugador = prevList(muros2);
    imprimir_pasillo(lugar_jugador,muros2,avanzar,linea);
    }
    if (lugar_jugador->pasillo==3){
    lugar_jugador = prevList(muros3);
    imprimir_pasillo(lugar_jugador,muros3,avanzar,linea);
    }

    
  }

  printf("-%d-\n",lugar_jugador->indice);

 ///////////////////////////////////////////// 
  if (avanzar == 3){

    if (lugar_jugador->pasillo==1){

        printf("\n");
        printf("~~~~~~~~~~  Mapa P1  ~~~~~~~~~~~\n");
        imprimir_muro(lugar_jugador->indice);
        printf("\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }

    if (lugar_jugador->pasillo==2){

        printf("\n");
        printf("~~~~~~~~~~  Mapa P2  ~~~~~~~~~~~\n");
        imprimir_muro2(lugar_jugador->indice);
        printf("\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }

    if (lugar_jugador->pasillo==3){

        printf("\n");
        printf("~~~~~~~~~~  Mapa P3  ~~~~~~~~~~~\n");
        imprimir_muro3(lugar_jugador->indice);
        printf("\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    }

  

    }

  if (lugar_jugador->indice==16 && lugar_jugador->pasillo==1){

    lugar_jugador = firstList(muros2);

  }

  if (lugar_jugador->indice==16 && lugar_jugador->pasillo==2){

    lugar_jugador = firstList(muros3);

  }

}


Monstruo * pelea1 = firstList(listaMonstruo);

int decision =0;

while (pelea1->vida >0){

  printf("╔══════════╗" "\n");
  printf("║ Combate  ║" "\n");
  printf("╠══════════╩══════════════════════╗\n");
  printf("║"ANSI_COLOR_RED"- Estás siendo atacado          "ANSI_COLOR_RESET " ║" "\n");
  printf("║- ¿Qué haces?                    ║\n");
  printf("╚═════════════════════════════════╝" "\n");
  printf(ANSI_COLOR_YELLOW"╔═══════════════╦═════════════════╗\n");
  printf("║" ANSI_COLOR_BLUE"(1)"ANSI_COLOR_RESET"Atacar     "ANSI_COLOR_YELLOW " ║"ANSI_COLOR_RESET""ANSI_COLOR_BLUE "(2)"ANSI_COLOR_RESET"Defender     "ANSI_COLOR_YELLOW" ║" "\n");
  printf("╚═══════════════╩═════════════════╝"ANSI_COLOR_RESET "\n");

  printf("👉 ");scanf("%d", &decision);
  printf("\n");

  if (decision==1){
   nuevo3->vida--;
   }
   
  if (decision==2){

    printf(ANSI_COLOR_GREEN"🛡️ Bloqueaste el Ataque 🛡️"ANSI_COLOR_RESET"\n");
    printf("\n");
    printf("┌─────────────────────────────────┐\n");
    printf("│- Tu turno ¿que haces?           │\n");
    printf("└─────────────────────────────────┘" "\n");
    printf(ANSI_COLOR_YELLOW"┌───────────────┬─────────────────┐\n");
  printf("│ (1)Atacar     │ (2)Defender     │" "\n");
  printf("└───────────────┴─────────────────┘"ANSI_COLOR_RESET "\n");
    printf("👉 ");scanf("%d", &decision);
    if (decision==1){
     pelea1->vida--;
   }

  } 

  }

  if (pelea1->vida ==0){
    printf("\n");
    printf("\n");
    printf(ANSI_COLOR_CYAN"     --------------------------\n");
    printf("       👏 Enemigo derrotado 👏\n");
    printf("     --------------------------\n"ANSI_COLOR_RESET);

  }


  Monstruo2 * pelea2 = nextList(listaMonstruo);

  printf("\n");
  printf("\n");
  printf(ANSI_COLOR_MAGENTA"                 👾           \n");
  printf("Oh has encontrado al Jefe Monstruo 2\n");
  printf("                 👾           \n"ANSI_COLOR_RESET);
  printf("\n");
  printf("\n");

  int decision2 = 0;

  while (pelea2->vida >0){

  
  printf("┌─────────────────────────────────┐\n");
  printf("│"ANSI_COLOR_RED"- Estás siendo atacado          "ANSI_COLOR_RESET " │" "\n");
  printf("│- ¿Qué haces?                    │\n");
  printf("└─────────────────────────────────┘" "\n");
  printf(ANSI_COLOR_YELLOW"┌───────────────┬─────────────────┐\n");
  printf("│ (1)Atacar     │ (2)Defender     │" "\n");
  printf("└───────────────┴─────────────────┘"ANSI_COLOR_RESET "\n");

  printf("👉 ");scanf("%d", &decision2);
  printf("\n");

  if (decision2==1){
   nuevo3->vida--;
   }
   
  if (decision2==2){

    printf(ANSI_COLOR_GREEN"🛡️ Bloqueaste el Ataque 🛡️"ANSI_COLOR_RESET"\n");
    printf("\n");
    printf("- Tu turno ¿que haces?\n");
     printf(ANSI_COLOR_YELLOW"┌───────────────┬─────────────────┐\n");
  printf("│ (1)Atacar     │ (2)Defender     │" "\n");
  printf("└───────────────┴─────────────────┘"ANSI_COLOR_RESET "\n");
    printf("👉 ");scanf("%d", &decision2);
    if (decision2==1){
     pelea2->vida--;
   }

  } 

  }

  if (pelea2->vida ==0){
    printf("\n");
    printf("\n");
    printf(ANSI_COLOR_CYAN"     --------------------------\n");
    printf("       👏 Enemigo derrotado 👏\n");
    printf("     --------------------------\n"ANSI_COLOR_RESET);

  }

  Monstruo3 * pelea3 = nextList(listaMonstruo);

  printf("\n");
  printf("\n");
  printf(ANSI_COLOR_MAGENTA"                 👾           \n");
  printf("Oh has encontrado al Jefe Monstruo 3\n");
  printf("                 👾           \n"ANSI_COLOR_RESET);
  printf("\n");
  printf("\n");

  int decision3 = 0;

  while (pelea3->vida >0){

  printf("┌─────────────────────────────────┐\n");
  printf("│"ANSI_COLOR_RED"- Estás siendo atacado          "ANSI_COLOR_RESET " │" "\n");
  printf("│- ¿Qué haces?                    │\n");
  printf("└─────────────────────────────────┘" "\n");
  printf(ANSI_COLOR_YELLOW"┌───────────────┬─────────────────┐\n");
  printf("│ (1)Atacar     │ (2)Defender     │" "\n");
  printf("└───────────────┴─────────────────┘"ANSI_COLOR_RESET "\n");

  printf("👉 ");scanf("%d", &decision3);
  printf("\n");

  if (decision3==1){
   nuevo3->vida--;
   }
   
  if (decision3==2){
    printf(ANSI_COLOR_GREEN"🛡️ Bloqueaste el Ataque 🛡️"ANSI_COLOR_RESET"\n");
    printf("\n");
    printf("- Tu turno ¿que haces?\n");
    printf(ANSI_COLOR_YELLOW"┌───────────────┬─────────────────┐\n");
    printf("│ (1)Atacar     │ (2)Defender     │" "\n");
    printf("└───────────────┴─────────────────┘"ANSI_COLOR_RESET "\n");
    printf("👉 ");scanf("%d", &decision3);
    if (decision2==1){
     pelea3->vida--;
   }

  } 

  }

  if (pelea3->vida ==0){
    printf("\n");
    printf("\n");
    printf(ANSI_COLOR_CYAN"     --------------------------\n");
    printf("       👏 Enemigo derrotado 👏\n");
    printf("     --------------------------\n"ANSI_COLOR_RESET);

  }



    }




    }
    
  return 0;
}

//------------------------FUNCIONES----------------------------------------

void imprimir_muro(int lineas){
   
   char linea[1024];
   int cont=0;
   int espacios=0; 
   int i;

  FILE * libro = fopen("Muro 1.txt","r");

  while (fgets(linea , 1024 , libro )!= NULL){
   
    
    if (cont!=lineas){

      if (strstr(linea,"║")){
        if (espacios>0){
          for(i=0 ; i!=espacios+1; i++){
            printf(" ");
          }
        }
        printf("║\n");

      }
      

      if (strstr(linea,"╚")){
        if (espacios>0){
          for(i=0 ; i!=espacios+1; i++){
            printf(" ");
          }
        }
        printf("╚");

      }

      if (strstr(linea,"═")){
        espacios++;
        printf("═");
      }

      if (strstr(linea,"╗")){
       
        
        printf("╗\n");

      }

    if (strstr(linea,"©")){
        if (espacios>0){
          for(i=0 ; i!=espacios+1; i++){
            printf(" ");
          }
        }
        printf(" ©\n");

      }  
     

    cont++;

    }
    }
}
void imprimir_muro2(int lineas){
   
   char linea[1024];
   int cont=0;
   int espacios=0; 
   int i;

  FILE * libro = fopen("Muro 2.txt","r");

  while (fgets(linea , 1024 , libro )!= NULL){
   
    
    if (cont!=lineas){

      if (strstr(linea,"║")){
        if (espacios>0){
          for(i=0 ; i!=espacios+1; i++){
            printf(" ");
          }
        }
        printf("║\n");

      }
      

      if (strstr(linea,"╚")){
        if (espacios>0){
          for(i=0 ; i!=espacios+1; i++){
            printf(" ");
          }
        }
        printf("╚");

      }

      if (strstr(linea,"═")){
        espacios++;
        printf("═");
      }

      if (strstr(linea,"╗")){
        printf("╗\n");
      }

    if (strstr(linea,"©")){
        if (espacios>0){
          for(i=0 ; i!=espacios+1; i++){
            printf(" ");
          }
        }
        printf(" ©\n");

      }  
     

    cont++;

    }else{
      break;
    }
    }
}
void imprimir_muro3(int lineas){
   
   char linea[1024];
   int cont=0;
   int espacios=0; 
   int i;

  FILE * libro = fopen("Muro 3.txt","r");

  while (fgets(linea , 1024 , libro )!= NULL){
   
    
    if (cont!=lineas){

      if (strstr(linea,"║")){
        if (espacios>0){
          for(i=0 ; i!=espacios+1; i++){
            printf(" ");
          }
        }
        printf("║\n");

      }
      

      if (strstr(linea,"╚")){
        if (espacios>0){
          for(i=0 ; i!=espacios+1; i++){
            printf(" ");
          }
        }
        printf("╚");

      }

      if (strstr(linea,"═")){
        espacios++;
        printf("═");
      }

      if (strstr(linea,"╗")){
       
        
        printf("╗\n");

      }

    if (strstr(linea,"©")){
        
        printf(" ©\n");

      }
    
    if (strstr(linea,"╔")){
       
        
        printf("╔\n");

      }  
     

    cont++;

    }else{
      break;
    }
    }
}
void genera_pasillo1(List *muros, muro *partes ){

  char linea[1024];
  int lugar = 1;
  
  FILE * libro = fopen("Muro 1.txt","r");

  while (fgets(linea , 1024 , libro )!= NULL){

    partes = (muro*) malloc(sizeof(muro));
    strcpy(partes->pieza,linea);
    partes->visita=0;
    partes->pelea=0;
    partes->indice=lugar;
    lugar++; 
    partes->pasillo=1;
    
    if (partes->indice==15){
      partes->pelea=1;
    } 


    pushBack(muros, partes);
    
  }





}
void genera_pasillo2(List *muros2, muro *partes2 ){
  int lugar=1;
   char linea[1024];

  FILE * libro2 = fopen("Muro 2.txt","r");

  while (fgets(linea , 1024 , libro2 )!= NULL){

    partes2 = (muro*) malloc(sizeof(muro));
    strcpy(partes2->pieza,linea);
    partes2->visita=0;
    partes2->pelea=lugar;
    partes2->indice=lugar;
    lugar++; 
    partes2->pasillo=2;
    if (partes2->indice==15){
      partes2->pelea=1;
    } 
    pushBack(muros2, partes2);
    
  } 
}
void genera_pasillo3(List *muros3, muro *partes3 ){
  
  int lugar=1;
   char linea[1024];

  FILE * libro3 = fopen("Muro 3.txt","r");

  while (fgets(linea , 1024 , libro3 )!= NULL){

    partes3 = (muro*) malloc(sizeof(muro));
    strcpy(partes3->pieza,linea);
    partes3->visita=0;
    partes3->pelea=lugar;
    partes3->indice=lugar;
    lugar++; 
    partes3->pasillo=3;
    if (partes3->indice==15){
      partes3->pelea=1;
    } 
    pushBack(muros3, partes3);
  }
}
void imprimir_pasillo(muro * lugar_jugador, List *muros, int avanzar,char *linea){

  
      if (strstr(lugar_jugador->pieza,"╝") && lugar_jugador->pelea==0 ){
        FILE * libro = fopen("pasillo.txt","r");

        while (fgets(linea , 1024 , libro )!= NULL){
          printf("%s",linea);

        }
   

        printf("\n");
      }
     

      if (strstr(lugar_jugador->pieza,"║") && lugar_jugador->pelea==0){
       FILE * libro = fopen("pasillo.txt","r");

        while (fgets(linea , 1024 , libro )!= NULL){
          printf("%s",linea);

        }
        printf("\n");
        printf("\n        ----------------------------");
        
        printf("\n            Vez un pasillo vacio.");
        printf("\n        ----------------------------");
        printf("\n");
    }

    if (strstr(lugar_jugador->pieza,"═") && lugar_jugador->pelea==0){
       FILE * libro = fopen("pasillo.txt","r");

        while (fgets(linea , 1024 , libro )!= NULL){
          printf("%s",linea);

        }

        printf("\n");
        printf("\n        ----------------------------");
        
        printf("\n            Vez un pasillo vacio.");
        printf("\n        ----------------------------");
  
        printf("\n");
    }

    
      if (strstr(lugar_jugador->pieza,"╚") && lugar_jugador->pelea==0){
       FILE * libro = fopen("pasillo_puerta2.txt","r");

        while (fgets(linea , 1024 , libro )!= NULL){
          printf("%s",linea);

        }
        printf("\n");
        printf("\n    ------------------------------------");
        
        printf("\n     El pasillo sigue hacia la izquierda.");
        printf("\n    ------------------------------------");
 
        printf("\n");
    }

    if (strstr(lugar_jugador->pieza,"╗") && lugar_jugador->pelea==0){
       FILE * libro = fopen("pasillo_puerta.txt","r");

        while (fgets(linea , 1024 , libro )!= NULL){
          printf("%s",linea);

        }

        printf("\n");
        printf("\n    ------------------------------------");
        
        printf("\n     El pasillo sigue hacia la derecha.");
        printf("\n    ------------------------------------");
 
        printf("\n");
  
    }
    
     printf("\n");


     if (lugar_jugador->indice==15){
       
     }

    
    lugar_jugador->visita=1;

    


}
void imprimir_pasillo_atras(muro * lugar_jugador, List *muros, int avanzar,char *linea){


  if (strstr(lugar_jugador -> pieza,"║")){
       FILE * libro = fopen("pasillo.txt","r");

        while (fgets(linea , 1024 , libro )!= NULL){
          printf("%s",linea);

        }
        printf("\n");
    
    }

     if (strstr(lugar_jugador->pieza,"╚")){
       FILE * libro = fopen("pasillo_puerta2.txt","r");

        while (fgets(linea , 1024 , libro )!= NULL){
          printf("%s",linea);

        }
        printf("\n");
    }

    if (strstr(lugar_jugador->pieza,"═")){
       FILE * libro = fopen("pasillo.txt","r");

        while (fgets(linea , 1024 , libro )!= NULL){
          printf("%s",linea);

        }
    
        printf("\n");
    }

    if (strstr(lugar_jugador->pieza,"╗")){
       FILE * libro = fopen("pasillo_puerta.txt","r");

        while (fgets(linea , 1024 , libro )!= NULL){
          printf("%s",linea);

        }
      
        printf("\n");
    }
     

    }