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

int main() {
  
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

