#include <iostream>
#include <string>
#include <vector>
#include "Vertice.cpp"
#include "HashTable.h"

HashTable::HashTable(){
  this->m = 101;
  this->size = 0;
  size_t size = 101;
  this->table.reserve(101);
}

HashTable::HashTable(int capacity){
  this->m = capacity;
  this->size = 0;
  size_t size = capacity;
  this->table.reserve(capacity);
}

HashTable::~HashTable(){
  for(int i=0; i<this->m; i++){
    delete this->table[i];
  }
  this->clear();
  cout << "table destroyed." << endl;
}

int HashTable::hash(string key){
  return ((long)&key * this->m)%this->m;
}

void HashTable::resize(){
  this->m = this->m*2 + 1;
  vector<Vertice*> newTable;
  newTable.reserve(this->m);
  for(int i=0; i<this->m; i++){
    if(this->table[i]!=NULL) newTable[hash(this->table[i]->key)] = this->table[i];
  }
  this->table = newTable;
}

int HashTable::add(string key,int value){
  if(this->size >= this->m-1 || (this->size+0.0)/(this->m) >= 0.75){
    this->resize();
  }
  int pos = this->hash(key);
  for(int i=pos,count=0; count<this->m; i=(++i)%this->m,count++){
    if(this->table[i]==NULL){
      this->table[i] = new Vertice(key,value);
      this->size++;
      break;
    }
    else if(this->table[i]->key == key){
      int saved = this->table[i]->value;
      this->table[i]->value = value;
      return saved;
    }
  }
}

int HashTable::remove(string key){
  int pos = this->hash(key);
  int freeSpace = -1;
  int removed = 0;
  for(int i=pos; this->table[i]!=NULL; i=(++i)%this->m){
    if(this->table[i]->key==key){
      removed = this->table[i]->value;
      this->table[i]=NULL;
      freeSpace = i;
      this->size--;
    }
    else if(freeSpace!=-1 && this->hash(this->table[i]->key)==pos){
      this->table[freeSpace] = this->table[i];
      this->table[i] = NULL;
      freeSpace = i;
    }
  return removed;
  }
}

int HashTable::getValue(string key){
  int pos = this->hash(key);
  for(Vertice* v=this->table[pos]; v!=NULL; v=this->table[(pos++)%this->m]){
    if(v->key==key){
      return v->value;
    }
  }
  return -1;
}

bool HashTable::contains(string key){
  return this->getValue(key)!=-1;
}

bool HashTable::isEmpty() const{
  return this->size==0;
}

int HashTable::getSize() const{
  return this->size;
}

void HashTable::clear(){
  for(int i=0; i<this->m; i++){
    this->table[i] = NULL;
  }
  this->size = 0;
}

/*
// possible use case:
int main(){
  HashTable *t = new HashTable();
  cout << t->contains("uno") << endl;
  cout << "isempty " << t->isEmpty() << endl;
  cout << "size " << t->getSize() << endl;
  t->add("uno",126);
  cout << "size " << t->getSize() << endl;
  cout << "isempty " << t->isEmpty() << endl;
  cout << t->contains("uno") << endl;
  cout << t->getValue("uno") << endl;
  t->add("dos",156);
  t->clear();
  cout << "size " << t->getSize() << endl;
  cout << "isempty " << t->isEmpty() << endl;

  return 0;
}*/
