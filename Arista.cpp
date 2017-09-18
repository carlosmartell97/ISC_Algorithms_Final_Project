#include "Arista.h"

Arista::Arista(Vertice amigo){
  this->amigo = amigo;
  this->interaccion = 0;
}

Arista::Arista(Vertice amigo,int interaccion){
  this->amigo = amigo;
  this->interaccion = interaccion;
}

Vertice Arista::getAmigo() const{
  return this->amigo;
}

int Arista::getInteraccion() const{
  return this->interaccion;
}
