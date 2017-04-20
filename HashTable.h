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
  string remove(string key);
  string getPassword(string key);
  bool contains(string key);
  bool isEmpty() const;
  int getSize() const;
  void clear();
};

#endif
