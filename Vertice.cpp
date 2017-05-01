#include "Vertice.h"

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

Vertice::Vertice(string key,string value,int position){
  this->key = key;
  this->value = value;
  this->positionInTable = position;
}

/*Vertice**/void Vertice::addFriend(Vertice* amigo,int interaccion){
  this->amigos.push_back(amigo);
  this->interacciones.push_back(interaccion);
  this->interaccionesTotal += interaccion;
  // return this->amigos[this->amigos.size()];
}
