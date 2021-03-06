#include "Vertice.h"
using namespace std;

Vertice::Vertice(){
  vector<Vertice> amigos;
  vector<int> interacciones;
  this->amigos.reserve(101);
  this->interacciones.reserve(101);
}

Vertice::~Vertice(){
  this->amigos.clear();
  this->interacciones.clear();
}

Vertice::Vertice(string key,string value,int position,int positionInUsedIndexes){
  this->key = key;
  this->value = value;
  this->positionInTable = position;
  this->positionInUsedIndexes = positionInUsedIndexes;
}

/*Vertice**/void Vertice::addFriend(Vertice* amigo,int interaccion){
  this->amigos.push_back(amigo);
  this->interacciones.push_back(interaccion);
  this->interaccionesTotal += interaccion;
  // return this->amigos[this->amigos.size()];
}
