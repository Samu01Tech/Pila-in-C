#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

//INFORMATION HIDING
/*
Non devo lasciare visibile non più di quello che è necessario
struct Pila{
  //funzioni accessibili
  private:
  //variabili e funzioni nascoste
}
*/
//CLASSI IN C
/*
class Pila{
  //variabili e funzioni nascoste
  public:
  //funzioni accessibili
}
*/

class Pila {
  int size;
  int defaultGrowthSize;
  int marker;
  int* contenuto;
  //funzioni
  void cresci(int increment);
  public:
    int estrai();
    Pila(int initialSize); 
    ~Pila();
    void inserisci(int k);
    void stampaStato();
    Pila* copia();
};

int main() {
  Pila *s = new Pila(5); // OLD: = crea(5)
  cout << "s"; s->stampaStato();
  for (int k=1; k<10; k++) s->inserisci(k);
  cout << "s"; s->stampaStato();
  Pila *w = s->copia();
  cout << "w"; w->stampaStato();
  for (int k=1; k<8; k++) 
  cout << s->estrai()<< endl;
  cout << "s"; s->stampaStato();
  delete s; // OLD: distruggi(s);
  //cout << "s"; s->stampaStato(); --PROBLEMATICA perché vuota
  for (int k=1; k<15; k++) 
  cout << w->estrai() << endl;
  cout << "w"; w->stampaStato();
  return 0;
}

int Pila::estrai() {
  cout << "entro in estrai" << endl;
  assert(marker>0);
  return contenuto[--(marker)];
}
Pila::Pila(int initialSize) {
  size = initialSize;
  defaultGrowthSize = initialSize;
  marker = 0;
  contenuto = new int[initialSize];
}
Pila::~Pila() {
  cout << "entro nel distruttore" << endl;
  delete []contenuto;
}

void Pila::cresci(int increment){
  cout << "Eseguendo cresci..." << endl;
  size += increment;
  int* temp = new int[size];
  for(int k=0; k < marker; k++){
    temp[k] = contenuto[k];
  }
  delete [] (contenuto);
  contenuto = temp;
}

void Pila::inserisci(int k){
  cout << "Eseguendo inserisci..." << endl;
  if(size == marker){
    cresci(defaultGrowthSize);
  }
  contenuto[marker] = k;
  marker++;

}

void Pila::stampaStato(){
  cout << "===============" << endl;
  cout << "size = " << size << endl;
  cout << "defaultGrowthSize = " << defaultGrowthSize << endl;
  cout << "marker = " << marker << endl;
  for(int k=0; k < marker; k++){
    cout << "[" << (contenuto[k]) << "]";
  }
  cout << endl;
  cout << "================" << endl;

}

Pila* Pila::copia(){
  cout << "Eseguendo copia..." << endl;
  Pila *to = new Pila(size);
  to->defaultGrowthSize = defaultGrowthSize;
  for(int k=0; k < marker; k++){
    to->contenuto[k] = contenuto[k];
  }
  to->marker = marker;
  return to;
}

