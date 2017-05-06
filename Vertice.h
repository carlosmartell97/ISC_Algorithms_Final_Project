#ifndef VERTICE_H_
#define VERTICE_H_

class Vertice{
public:
  string key;
  string value;
  double interaccionesTotal;
  int positionInTable;
  int positionInUsedIndexes;
  vector<Vertice*> amigos;
  vector<int> interacciones;
  map<string,int> knownShortestPaths;
  // deque<Vertice> history;
  Vertice();
  Vertice(string key,string value,int position,int positionInUsedIndexes);
  ~Vertice();
  /*Vertice**/void addFriend(Vertice* amigo,int interaccion);
};

#endif
