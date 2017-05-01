#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#define pii pair<int,int>

class HashTable{
private:
  int m;
  int size;
  int MAX_SIZE;
  int INF;
  vector<Vertice*> table;
  vector<int> usedIndexesInTable;
  int hash(string key);
  void resize();
  struct compare;
public:
  HashTable();
  HashTable(int capacity);
  ~HashTable();
  string add(string key,string value);
  void makeFriends(Vertice* person,Vertice* person2,int inter);
  void makeFriends(Vertice* person,Vertice* person2,int inter,int inter2);
  string remove(string key);
  Vertice* getUser(string key);
  string getPassword(string key);
  bool degreesOfSeparation(int separation);
  int Dijkstra(Vertice* origin,Vertice* end,int indexOrigin,int indexEnd,int nodes);
  void printUsersPosition();
  bool contains(string key);
  bool isEmpty() const;
  int getSize() const;
  void clear();
};

#endif
