#include <iostream>
#include <cstdlib>
#include <cassert>
#define DEBUG
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
  cout << "Eseguendo crea..." << endl;
  Pila *s = new Pila;
  s->size = initialSize;
  s->defaultGrowthSize = initialSize;
  s->marker = 0;
  s->contenuto = new int[initialSize];
  return s;
  cout << "Fatto" << endl;
}

void distruggi(Pila *s){
  cout << "Eseguendo distruggi..." << endl;
  delete [] (s->contenuto);
  delete s;
  cout << "Fatto" << endl;
}

void cresci(Pila *s, int increment){
  cout << "Eseguendo cresci..." << endl;
  s->size += increment;
  int* temp = new int[s->size];
  for(int k=0; k < s->marker; k++){
    temp[k] = s->contenuto[k];
  }
  delete [] (s->contenuto);
  s->contenuto = temp;
  cout << "Fatto" << endl;
}

void inserisci(Pila *s, int k){
  cout << "Eseguendo inserisci..." << endl;
  if(s->size == s->marker){
    cresci(s, s->defaultGrowthSize);
  }
  s->contenuto[s->marker] = k;
  s->marker++;
  cout << "Fatto" << endl;
}

int estrai(Pila *s){
  cout << "Eseguendo estrai..." << endl;
  
  #ifdef DEBBUG
    assert(s->marker>0);
    //serve in fase di debug per verificare il corretto funzionamento del programma
  #endif

  return s->contenuto[--(s->marker)];
  cout << "Fatto" << endl;
}
