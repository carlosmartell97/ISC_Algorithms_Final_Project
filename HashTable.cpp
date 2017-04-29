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
  cout << "\n\n\n--------------END OF PROGRAM. DATABASE DESTROYED-----------------------" << endl;
}

int HashTable::hash(string key){
  return abs((long)&key * this->m)%this->m;
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
      string saved = this->table[i]->key;
      usedIndexesInTable.push_back(i);
      // cout << "_saved: "<< saved << endl;
      return saved;
    }
    else if(this->table[i]->key == key){
      this->table[i]->value = value;
      string saved = this->table[i]->key;
      // cout << "_updated: "<< saved << endl;
      return saved;
    }
  }
}

void HashTable::makeFriends(Vertice* person,Vertice* person2,int inter){
  this->makeFriends(person,person2,inter,inter);
}

void HashTable::makeFriends(Vertice* person,Vertice* person2,int inter,int inter2){
  person->addFriend(person2,inter);
  person2->addFriend(person,inter2);
}

string HashTable::remove(string key){
  int pos = this->hash(key);
  int freeSpace = -1;
  string removed = 0;
  for(int i=pos, count=0; this->table[i]!=NULL && count<this->m; i=(++i)%this->m, count++){
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

Vertice* HashTable::getUser(string key){
  int pos = this->hash(key);
  int count = 0;
  for(string k; this->table[pos]!=NULL && count<this->m; k=this->table[(++pos)%this->m]->key, count++){
    k=this->table[pos]->key;
    if(k==key){
      return this->table[pos];
    }
  }
  cout << "not found" << endl;
  return NULL;
}

string HashTable::getPassword(string key){
  int pos = this->hash(key);
  int count = 0;
  for(string k; this->table[pos]!=NULL && count<this->m; k=this->table[(++pos)%this->m]->key, count++){
    k=this->table[pos]->key;
    if(k==key){
      return this->table[pos]->value;
    }
  }
  // cout << "not found" << endl;
  return "";
}

bool HashTable::degreesOfSeparation(int separation){
  cout << "\n\n\n--------------TESTING FOR "<<separation<<" DEGREES OF SEPARATION-----------------------" << endl;
  for(int i=0; i<this->usedIndexesInTable.size(); i++){
    cout << "route between " << this->table[this->usedIndexesInTable[i]]->key << endl;
    for(int j=i+1; j<this->usedIndexesInTable.size(); j++){
      cout << "\tand " << this->table[this->usedIndexesInTable[j]]->key << flush;
      int distance = shortestPath(this->table[this->usedIndexesInTable[j]],this->table[this->usedIndexesInTable[j]]);
      cout << ": " << distance << endl;
      if(distance>separation)
        return false;
    }
    if(i+1==this->usedIndexesInTable.size())
      cout << "\t...and NONE" << endl;
  }
  return true;
}

int HashTable::shortestPath(Vertice* origin, Vertice* end){
  // Dijkstra(greedy) o Bellman-Ford(dynamic)
  return 0;
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
