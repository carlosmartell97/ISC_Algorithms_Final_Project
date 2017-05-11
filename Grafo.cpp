#include "Grafo.h"

// float consideracionDirectos = 0.1;
float consideracionIndirectos = 0.5;

vector<Recommendation> recommend(Vertice *origin){
  vector<Recommendation> recommendations;
  vector<Vertice*> toLookForInMap;
  // cout << "running recommendations for " << origin->key << "..." << endl;
  map<string,double> friendsOfFriends;
  map<string,short> ignorePeople;
  for(int i=0; i<origin->amigos.size(); i++){
    ignorePeople[origin->amigos[i]->key] = 0;
  }
  for(int i=0; i<origin->amigos.size(); i++){
    if(origin->interacciones[i] != 0){
      // cout << origin->amigos[i]->key << endl;
      for(int j=0; j<origin->amigos[i]->amigos.size(); j++){
        if(origin->key != origin->amigos[i]->amigos[j]->key){
          // cout << "\t" << origin->amigos[i]->amigos[j]->key << endl;
          if(ignorePeople.find(origin->amigos[i]->amigos[j]->key) == ignorePeople.end() && friendsOfFriends.find(origin->amigos[i]->amigos[j]->key) != friendsOfFriends.end()){
            // cout << "\tCOLLISION " << origin->amigos[i]->amigos[j]->key << endl;
            toLookForInMap.push_back(origin->amigos[i]->amigos[j]);
            ignorePeople[origin->amigos[i]->amigos[j]->key] = 0;
          }
          // cout << "\t\t" << origin->key << "-" << origin->interacciones[i] << "::" << origin->interacciones[i]/origin->interaccionesTotal << "->" << flush;
          // cout << origin->amigos[i]->key << "-" << origin->amigos[i]->interacciones[j] << "::" << flush;
            // cout << origin->amigos[i]->interacciones[j]/origin->amigos[i]->interaccionesTotal << "::" << flush;
            // cout << (origin->amigos[i]->interacciones[j]/origin->amigos[i]->interaccionesTotal)*consideracionIndirectos << flush;
            // cout << "->" << origin->amigos[i]->amigos[j]->key << endl;
          if(origin->interaccionesTotal != 0)
            friendsOfFriends[origin->amigos[i]->amigos[j]->key] += origin->interacciones[i]/origin->interaccionesTotal;
          if(origin->amigos[i]->interaccionesTotal != 0)
            friendsOfFriends[origin->amigos[i]->amigos[j]->key] += (origin->amigos[i]->interacciones[j]/origin->amigos[i]->interaccionesTotal)*consideracionIndirectos;
          friendsOfFriends[origin->amigos[i]->amigos[j]->key] += 1;
          // cout << "\t\tbucket:" << friendsOfFriends[origin->amigos[i]->amigos[j]->key] << endl;
        }
      }
    }
  }
  // cout << "size: " << toLookForInMap.size() << endl;
  for(int i=0; i<toLookForInMap.size(); i++){
    Recommendation *found = new Recommendation(toLookForInMap[i],friendsOfFriends[toLookForInMap[i]->key]);
    recommendations.push_back(*found);
    delete found;
  }
  toLookForInMap.clear();

  // cout << "----------------------" << endl;
  return recommendations;
}
