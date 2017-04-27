#include "Grafo.h"

float consideracionDirectos = 0.1;
float consideracionIndirectos = 0.06667;

vector<Recommendation> recommend(Vertice *origin){
  vector<Recommendation> recommendations;
  cout << "running recommendations for " << origin->key << "..." << endl;
  for(int i=0; i<origin->amigos.size(); i++){
    for(int j=i+1; j<origin->amigos.size(); j++){
      if(origin->interacciones[i]!=0 && origin->interacciones[j]!=0){
        // cout << "\t" << origin->amigos[i]->key << " -> " << origin->amigos[j]->key << endl;
        map<string,int> friendsInI;
        // cout << "friends of " << origin->amigos[i]->key << ":" << endl;
        for(int k=0; k<origin->amigos[i]->amigos.size(); k++){
          // cout << "\t-" << origin->amigos[i]->amigos[k]->key << endl;
          if(origin->key != origin->amigos[i]->amigos[k]->key)
            friendsInI[origin->amigos[i]->amigos[k]->key] = k;
        }
        // cout << "with friends of " << origin->amigos[j]->key << ":" << endl;
        for(int k=0; k<origin->amigos[j]->amigos.size(); k++){
          bool e = friendsInI.find(origin->amigos[j]->amigos[k]->key) != friendsInI.end();
          // cout << "\t+" << origin->amigos[j]->amigos[k]->key << "<<<" << e << endl;

          if(/*origin->key != origin->amigos[i]->amigos[friendsInI[origin->amigos[j]->amigos[k]->key]]->key &&*/ origin->key != origin->amigos[j]->amigos[k]->key && friendsInI.find(origin->amigos[j]->amigos[k]->key) != friendsInI.end()){
            // cout << "\tTRUE:" << origin->amigos[j]->amigos[k]->key << endl;
            cout << "found " << origin->amigos[j]->amigos[k]->key << " through\t" <<
              origin->key << " -"<<origin->interacciones[i]<<"::"<<origin->interacciones[i]/origin->interaccionesTotal<<"::"<<(origin->interacciones[i]/*/origin->interaccionesTotal*/)*consideracionDirectos<<"-> " << origin->amigos[i]->key << " -"<<origin->amigos[i]->interacciones[friendsInI[origin->amigos[j]->amigos[k]->key]]<<"::"<<flush;
                cout << origin->amigos[i]->interacciones[friendsInI[origin->amigos[j]->amigos[k]->key]]/origin->amigos[i]->interaccionesTotal<<"::"<<flush;
                cout<<(origin->amigos[i]->interacciones[friendsInI[origin->amigos[j]->amigos[k]->key]]/*/origin->amigos[i]->interaccionesTotal*/)*consideracionIndirectos<<"-> " << origin->amigos[i]->amigos[friendsInI[origin->amigos[j]->amigos[k]->key]]->key << "\n\t\tand \t" <<flush;
              cout<<origin->key << " -"<<origin->interacciones[j]<<"::"<<origin->interacciones[j]/origin->interaccionesTotal<<"::"<<(origin->interacciones[j]/*/origin->interaccionesTotal*/)*consideracionDirectos<<"-> " << origin->amigos[j]->key << " -"<<origin->amigos[j]->interacciones[k]<<"::"<<origin->amigos[j]->interacciones[k]/origin->amigos[j]->interaccionesTotal<<"::"<<flush;
                cout<<(origin->amigos[j]->interacciones[k]/*/origin->amigos[j]->interaccionesTotal*/)*consideracionIndirectos<<"-> " << origin->amigos[j]->amigos[k]->key << endl;
          double interactions = 0;
          if(origin->interaccionesTotal != 0)
            interactions += (origin->interacciones[i]/*/origin->interaccionesTotal*/)*consideracionDirectos + (origin->interacciones[j]/*/origin->interaccionesTotal*/)*consideracionDirectos;
          if(origin->amigos[i]->interaccionesTotal != 0)
            interactions += (origin->amigos[i]->interacciones[friendsInI[origin->amigos[j]->amigos[k]->key]]/*/origin->amigos[i]->interaccionesTotal*/)*consideracionIndirectos;
          if(origin->amigos[j]->interaccionesTotal != 0)
            interactions += (origin->amigos[j]->interacciones[k]/*/origin->amigos[j]->interaccionesTotal*/)*consideracionIndirectos;

          // interactions += origin->interacciones[i] + origin->amigos[i]->interacciones[k] + origin->interacciones[j] + origin->amigos[j]->interacciones[l];
          Recommendation *found = new Recommendation(origin->amigos[i]->amigos[friendsInI[origin->amigos[j]->amigos[k]->key]],interactions+2);
          recommendations.push_back(*found);
          delete found;
        } /*else {
          cout << "nope..." << endl;
        }*/
        }
        friendsInI.clear();
        cout << "--------------------" << endl;
      }
    }
    // if(i+1 == origin->amigos.size()) cout << "\t" << origin->amigos[i]->key << " -> NONE" << endl;
  }
  return recommendations;
}
