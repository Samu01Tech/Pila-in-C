#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

struct Pila {
  int size;
  int defaultGrowthSize;
  int marker;
  int* contenuto;
};

Pila* crea(int initialSize);
void distruggi(Pila *s);
void cresci(Pila *s, int increment);
void inserisci(Pila *s, int k);

int main() {
  return 0;
}

Pila* crea(int initialSize){
  Pila *s = new Pila;
  s->size = initialSize;
  s->defaultGrowthSize = initialSize;
  s->marker = 0;
  s->contenuto = new int[initialSize];
  return s;
}

void distruggi(Pila *s){
  delete [] (s->contenuto);
  delete s;
}

void cresci(Pila *s, int increment){
  s->size += increment;
  int* temp = new int[s->size];
  for(int k=0; k < s->marker; k++){
    temp[k] = s->contenuto[k];
  }
  delete [] (s->contenuto);
  s->contenuto = temp;
}

void inserisci(Pila *s, int k){
  if(s->size == s->marker){
    cresci(s, s->defaultGrowthSize);
  }
  s->contenuto[s->marker] = k;
  s->marker++;
}
