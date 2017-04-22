#include <vector>
#include <string>
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

Vertice::Vertice(string key,string value){
  this->key = key;
  this->value = value;
}

/*Vertice Vertice::addFriend(Vertice* amigo,int interaccion){
  // Vertice *newVert = new Vertice(amigo->key,amigo->value);
  // this->amigos.push_back(*newVert);
  this->amigos.push_back(*amigo);
  this->interacciones.push_back(interaccion);

  // return this->amigos[this->amigos.size()];
}*/
