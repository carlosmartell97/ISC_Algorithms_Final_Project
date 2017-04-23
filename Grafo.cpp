#include "Grafo.h"

/*deque<Vertice> breadthFirstSearch(Vertice origin,Vertice end){
  /*deque<Vertice> work;
  deque<Vertice> visited;

  work.push_back(origin);
  visited.push_back(origin);

  // deque<int>::iterator it = find(q.begin(),q.end(),1);
  // if(it != q.end())
  // {
  // q.push_back(1);
  // }

  while(work.size()>0){
    Vertice current = work.front();
    work.pop_front();
    if(current.key==end.key){
      cout << "found path!!!" << endl;
      deque<Vertice> result = current.history;
      return result;
    } else {
      for(int i=0; i<current.amigos.size(); i++){
        Vertice *currentChild = current.amigos[i];
        deque<Vertice>::iterator it = find(visited.begin(),visited.end(),currentChild);
        if(it != q.end()){
          work.push_back(*currentChild);
        }
      }
    }/
  }

  // delete current;
}*/

vector<Recommendation> recommend(Vertice *origin){
  vector<Recommendation> recommendations;
  cout << "running recommendations for " << origin->key << "..." << endl;
  for(int i=0; i<origin->amigos.size(); i++){

    for(int j=i+1; j<origin->amigos.size(); j++){
      if(origin->interacciones[i]!=0 && origin->interacciones[j]!=0){
        // cout << "\t" << origin->amigos[i]->key << " -> " << origin->amigos[j]->key << endl;
        for(int k=0; k<origin->amigos[i]->amigos.size(); k++){
          for(int l=0; l<origin->amigos[j]->amigos.size(); l++){
            // cout << "\t\t" << origin->amigos[i]->amigos[k]->key << " -> " << origin->amigos[j]->amigos[l]->key << flush;
            if(origin->key != origin->amigos[i]->amigos[k]->key && origin->amigos[i]->amigos[k]->key == origin->amigos[j]->amigos[l]->key){
              int interactions = 0;
              // cout << "\t\t\t\tTRUE" << flush;
              cout << "found " << origin->amigos[i]->amigos[k]->key << " through\t" <<
                origin->key << " -"<<origin->interacciones[i]<<"-> " << origin->amigos[i]->key << " -"<<origin->amigos[i]->interacciones[k]<<"-> " << origin->amigos[i]->amigos[k]->key << "\n\t\tand \t" <<
                origin->key << " -"<<origin->interacciones[j]<<"-> " << origin->amigos[j]->key << " -"<<origin->amigos[j]->interacciones[l]<<"-> " << origin->amigos[j]->amigos[l]->key << endl;
              interactions += origin->interacciones[i] + origin->amigos[i]->interacciones[k] + origin->interacciones[j] + origin->amigos[j]->interacciones[l];
              Recommendation *found = new Recommendation(origin->amigos[i]->amigos[k],interactions);
              recommendations.push_back(*found);
              delete found;
            }
            // cout << endl;
          }
        }
      }
    }
    // if(i+1 == origin->amigos.size()) cout << "\t" << origin->amigos[i]->key << " -> NONE" << endl;
  }
  return recommendations;
}
