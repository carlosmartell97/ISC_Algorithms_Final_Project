#ifndef ARISTA_H_
#define ARISTA_H_

class Arista{
public:
  Vertice amigo;
  int interaccion;
  Arista(Vertice amigo);
  Arista(Vertice amigo,int interaccion);
  Vertice getAmigo() const;
  int getInteraccion() const;
};

#endif
