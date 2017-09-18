#ifndef VERTICE_H_
#define VERTICE_H_

class Vertice{
public:
  std::string key;
  std::string value;
  double interaccionesTotal;
  int positionInTable;
  int positionInUsedIndexes;
  std::vector<Vertice*> amigos;
  std::vector<int> interacciones;
  std::map<std::string,int> knownShortestPaths;
  // deque<Vertice> history;
  Vertice();
  Vertice(std::string key,std::string value,int position,int positionInUsedIndexes);
  ~Vertice();
  /*Vertice**/void addFriend(Vertice* amigo,int interaccion);
};

#endif
