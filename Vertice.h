#ifndef VERTICE_H_
#define VERTICE_H_

class Vertice{
public:
  string key;
  string value;
  double interaccionesTotal;
  vector<Vertice*> amigos;
  vector<int> interacciones;
  // deque<Vertice> history;
  Vertice();
  Vertice(string key,string value);
  ~Vertice();
  /*Vertice**/void addFriend(Vertice* amigo,int interaccion);
};

#endif