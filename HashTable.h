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
  int add(string key,int value);
  int remove(string key);
  int getValue(string key);
  bool contains(string key);
  bool isEmpty() const;
  int getSize() const;
  void clear();
};

#endif
