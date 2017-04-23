#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

class HashTable{
private:
  int m;
  int size;
  vector<Vertice*> table;
  int hash(string key);
  void resize();
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
  bool contains(string key);
  bool isEmpty() const;
  int getSize() const;
  void clear();
};

#endif
