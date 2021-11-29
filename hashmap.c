#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "list.h"
#include "hashmap.h"

typedef struct Pair Pair;
typedef struct HashMap HashMap;
int enlarge_called=0;

struct Pair {
     char * key;
     List * value;
};

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  List * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertMap(HashMap * map, char * key, List * value) {
int p;

Pair* nuevaKey= createPair(key,value);
p = hash(key,map->capacity);
if(map->size >= map->capacity * 0.7){
  map = (HashMap*)realloc(map,sizeof(HashMap)*2);
  map->capacity *= 2;
}
while(map->buckets[p]!=NULL){
  p++;
  if(p == map->capacity){
   p=0; 
  }
}

map->buckets[p] = nuevaKey;
map->size++;
}
void enlarge(HashMap * map) {
    enlarge_called = 1; 


}


HashMap * createMap(long capacity) {
  
HashMap* mapa = (HashMap*)malloc(sizeof(HashMap));
  mapa->size = 0;
  mapa->capacity = capacity;
  mapa->current = -1;
  mapa->buckets = (Pair**)calloc(capacity,sizeof(Pair*));
  while(mapa->buckets!=NULL){
  return mapa;
  }
  return 0;
}

void eraseMap(HashMap * map,  char * key) {    
  int p,i;
  i=0;
  p = hash(key,map->capacity);
  if(strcmp(map->buckets[p]->key,key)==0){
    map->buckets[p]->key = NULL;
    map->size-=1;
  }
  while(i<map->capacity){
    i++;
    if(map->buckets[i]!=NULL){
      if(strcmp(map->buckets[i]->key,key)==0){
        map->buckets[i]->key =NULL;
        map->size -=i;
      }
    }
  }
}

void * searchMap(HashMap * map,  char * key) {

  int p;

  p = hash(key,map->capacity);
  int i;
  i=0;
  if(strcmp(map->buckets[p]->key,key) == 0){ 
    map->current = p;
    return map->buckets[p]->value;
  }else{
    while(i < map->capacity){
      i++;
      if(map->buckets[i] != NULL){
        if(strcmp(map->buckets[i]->key,key) == 0){
          map->current = i;
          return map->buckets[i]->value;
        }
      }
    }
  }
return NULL;
}

void * firstMap(HashMap * map) {
  int i,p;
  int exit;
  exit=0;
  for(i=0;(i<map->capacity)&&(exit==0); i++){
    if(map->buckets[i] != NULL){
      exit=1;
      p=i;
    }
  }

    return map->buckets[p]->value;
}

void * nextMap(HashMap * map) {

    return NULL;
}