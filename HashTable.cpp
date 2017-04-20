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

string HashTable::add(string key,string value){
  if(this->size >= this->m-1 || (this->size+0.0)/(this->m) >= 0.75){
    this->resize();
  }
  int pos = this->hash(key);
  for(int i=pos,count=0; count<this->m; i=(++i)%this->m,count++){
    if(this->table[i]==NULL){
      this->table[i] = new Vertice(key,value);
      this->size++;
      string saved = this->table[i]->value;
      // cout << "_saved: "<< saved << endl;
      return saved;
    }
    else if(this->table[i]->key == key){
      this->table[i]->value = value;
      string saved = this->table[i]->value;
      // cout << "_updated: "<< saved << endl;
      return saved;
    }
  }
}

string HashTable::remove(string key){
  int pos = this->hash(key);
  int freeSpace = -1;
  string removed = 0;
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

string HashTable::getPassword(string key){
  int pos = this->hash(key);
  for(string k; this->table[pos]!=NULL; k=this->table[(++pos)%this->m]->key){
    k=this->table[pos]->key;
    if(k==key){
      return this->table[pos]->value;
    }
  }
  // cout << "not found" << endl;
  return "";
}

bool HashTable::contains(string key){
  return this->getPassword(key)!="";
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
  HashTable *tab = new HashTable();
  tab->clear();
  cout << "contains maria: " << tab->contains("maria") << endl;
  cout << "value maria: " << tab->getPassword("maria") << endl << endl;
  cout << "ADDED " << tab->add("maria","pan") << endl;
  cout << "contains maria: " << tab->contains("maria") << endl;
  cout << "value maria: " << tab->getPassword("maria") << endl << endl;
  cout << "ADDED " << tab->add("peter","book") << endl;
  cout << "contains juan: " << tab->contains("peter") << endl;
  cout << "value juan: " << tab->getPassword("peter") << endl << endl;
  cout << "ADDED " << tab->add("fran","jazz") << endl;
  cout << "contains fran: " << tab->contains("fran") << endl;
  cout << "value fran: " << tab->getPassword("fran") << endl << endl;
}
*/
