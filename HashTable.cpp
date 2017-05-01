#include "HashTable.h"

HashTable::HashTable(){
  this->m = 101;
  this->size = 0;
  size_t size = 101;
  this->table.reserve(101);
  this->MAX_SIZE = 100001;
  this->INF = INT_MAX;
}

HashTable::HashTable(int capacity){
  this->m = capacity;
  this->size = 0;
  size_t size = capacity;
  this->table.reserve(capacity);
  this->MAX_SIZE = 100001;
  this->INF = INT_MAX;
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
      this->table[i] = new Vertice(key,value,i);
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
      cout << endl;
      int distance = Dijkstra(this->table[this->usedIndexesInTable[i]],this->table[this->usedIndexesInTable[j]],this->usedIndexesInTable[i],this->usedIndexesInTable[j],this->usedIndexesInTable.size());
      if(distance>separation){
        cout << endl << endl << "theory is false because shortest path between " << this->table[this->usedIndexesInTable[i]]->key << " and " << this->table[this->usedIndexesInTable[j]]->key << " is " << distance << endl;
        return false;
      }
    }
    if(i+1==this->usedIndexesInTable.size())
      cout << "\t...and NONE" << endl;
  }
  // string o = "gus";
  // string e = "fernanda";
  // Dijkstra(this->table[71],this->table[73],this->getUser(o)->positionInTable,this->getUser(e)->positionInTable,this->usedIndexesInTable.size());
  return true;
}

struct HashTable::compare{
  bool operator()(const pii &a,const pii &b){
    return a.second > b.second;
  }
};

int HashTable::Dijkstra(Vertice* origin, Vertice* end,int indexOrigin,int indexEnd, int nodes){
  // cout << "\n\n\n--------------DIJKSTRA-----------------------" << endl;
  priority_queue< pii, vector<pii>, compare > Q;
  int D[this->m];
  bool F[this->m];
  vector<int> path[this->m];
  int u, sz, v, w;

  for(int i=0; i<nodes; i++){
    // cout << "INF to: " << usedIndexesInTable[i] << endl;
    D[this->usedIndexesInTable[i]] = INF;
    F[this->usedIndexesInTable[i]] = false;
  }
  D[indexOrigin] = 0;
  Q.push(pii(indexOrigin,0));
  path[indexOrigin].push_back(indexOrigin);

  while(!Q.empty()){
    u = Q.top().first;
    // cout << endl << "pop " << u << " " << Q.top().second << flush;
    Q.pop();
    if(F[u]) continue;
    sz = this->table[u]->amigos.size();
    // cout << endl << "friends of " << this->table[u]->key << " u:" << u << endl;
    for(int i=0; i<sz; i++){
      // cout << "\t-" << this->table[u]->amigos[i]->positionInTable << " " << this->table[u]->amigos[i]->key << endl;
      v = this->table[u]->amigos[i]->positionInTable;
      w = 1;
      // cout << "\t\tv:" << v << endl;
      // cout << "\t\tF[" << v << "]:" << F[v] << endl;
      // cout << "\t\tD[" << u << "]:" << D[u] << " D[" << v << "]:" << D[v] << endl;
      if(!F[v] && D[u]+w < D[v]){
        // cout << "TRUE" << endl;
        D[v] = D[u]+w;
        // cout << "\t\tupdated: D[" << v << "]:" << D[v] << endl;
        Q.push(pii(v,D[v]));
        // cout << "\t\tpush to Q: " << v << " " << D[v] << endl;
        path[v] = path[u];
        path[v].push_back(v);
      }
    }
    // cout << "\tnew F[" << u << "]" << endl;
    F[u] = 1;
  }

  // result
  // for(i=1; i<=nodes; i++){
    // cout << "Node " << i << ", min weight = " << D[i] << "     " << flush;
    // printf("Node %d, min weight = %d     ", i, D[i]);
    cout << "\t\tpath: " << flush;
    cout << this->table[path[indexEnd][0]]->key << flush;
    for(int j=1; j<path[indexEnd].size(); j++){
      cout << "->" << this->table[path[indexEnd][j]]->key << flush;
    }
    cout << "\tdistance:" << D[indexEnd] << endl;
  // }
  return D[indexEnd];
}

void HashTable::printUsersPosition(){
  cout << "\n\n\n--------------CURRENT USER POSITIONS-----------------------" << endl;
  for(int i=0; i<this->usedIndexesInTable.size(); i++){
    cout << this->usedIndexesInTable[i] << ": " << this->table[this->usedIndexesInTable[i]]->key << "\t" << endl;
  }
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
