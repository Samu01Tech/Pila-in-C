/*#include <iostream>
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
int estrai(Pila *s);
void stampaStato(Pila *s);
Pila* copia(Pila *from);
int main() {
  Pila *s = crea(5);
  cout << "s"; stampaStato(s);
  for(int k=1; k<10; k++) 
  inserisci(s, k);
  cout << "s"; stampaStato(s);
  Pila *w = copia(s);
  cout << "w"; stampaStato(w);
  for (int k=1; k<8;k++){
    cout << estrai(s) << endl;
  }
  cout << "s"; stampaStato(s);
  distruggi(s);
  //cout << "s"; stampaStato(s);
  for(int k=1; k<15; k++){
    cout << estrai(w) << endl;
  }
  cout << "w"; stampaStato(w);
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

}

void distruggi(Pila *s){
  cout << "Eseguendo distruggi..." << endl;
  delete [] (s->contenuto);
  delete s;

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

}

void inserisci(Pila *s, int k){
  cout << "Eseguendo inserisci..." << endl;
  if(s->size == s->marker){
    cresci(s, s->defaultGrowthSize);
  }
  s->contenuto[s->marker] = k;
  s->marker++;

}

int estrai(Pila *s){
  cout << "Eseguendo estrai..." << endl;
    assert(s->marker>0);
    //serve in fase di debug per verificare il corretto funzionamento del programma

  return s->contenuto[--(s->marker)];
}

void stampaStato(Pila *s){
  cout << "===============" << endl;
  cout << "size = " << s->size << endl;
  cout << "defaultGrowthSize = " << s->defaultGrowthSize << endl;
  cout << "marker = " << s->marker << endl;
  for(int k=0; k < s->marker; k++){
    cout << "[" << (s->contenuto[k]) << "]";
  }
  cout << endl;
  cout << "================" << endl;

}
Pila* copia(Pila *from){
  cout << "Eseguendo copia..." << endl;
  Pila *to = crea(from->size);
  to->defaultGrowthSize = from->defaultGrowthSize;
  for(int k=0; k < from->marker; k++){
    to->contenuto[k] = from->contenuto[k];
  }
  to->marker = from->marker;
  return to;
}
*/