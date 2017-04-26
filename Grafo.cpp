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
        for(int k=0; k<origin->amigos[i]->amigos.size(); k++){
          for(int l=0; l<origin->amigos[j]->amigos.size(); l++){
            // cout << "\t\t" << origin->amigos[i]->amigos[k]->key << " -> " << origin->amigos[j]->amigos[l]->key << flush;
            if(origin->key != origin->amigos[i]->amigos[k]->key && origin->amigos[i]->amigos[k]->key == origin->amigos[j]->amigos[l]->key){
              double interactions = 0;
              // cout << "\t\t\t\tTRUE" << flush;
              cout << "found " << origin->amigos[i]->amigos[k]->key << " through\t" <<
                origin->key << " -"<<origin->interacciones[i]<<"::"<<origin->interacciones[i]/origin->interaccionesTotal<<":<:"<<(origin->interacciones[i]/*/origin->interaccionesTotal*/)*consideracionDirectos<<"-> " << origin->amigos[i]->key << " -"<<origin->amigos[i]->interacciones[k]<<"::"<<origin->amigos[i]->interacciones[k]/origin->amigos[i]->interaccionesTotal<<"::"<<flush;
                  cout<<(origin->amigos[i]->interacciones[k]/*/origin->amigos[i]->interaccionesTotal*/)*consideracionIndirectos<<"-> " << origin->amigos[i]->amigos[k]->key << "\n\t\tand \t" <<flush;
                cout<<origin->key << " -"<<origin->interacciones[j]<<"::"<<origin->interacciones[j]/origin->interaccionesTotal<<"::"<<(origin->interacciones[j]/*/origin->interaccionesTotal*/)*consideracionDirectos<<"-> " << origin->amigos[j]->key << " -"<<origin->amigos[j]->interacciones[l]<<"::"<<origin->amigos[j]->interacciones[l]/origin->amigos[j]->interaccionesTotal<<"::"<<flush;
                  cout<<(origin->amigos[j]->interacciones[l]/*/origin->amigos[j]->interaccionesTotal*/)*consideracionIndirectos<<"-> " << origin->amigos[j]->amigos[l]->key << endl;
              if(origin->interaccionesTotal != 0)
                interactions += (origin->interacciones[i]/*/origin->interaccionesTotal*/)*consideracionDirectos + (origin->interacciones[j]/*/origin->interaccionesTotal*/)*consideracionDirectos;
              if(origin->amigos[i]->interaccionesTotal != 0)
                interactions += (origin->amigos[i]->interacciones[k]/*/origin->amigos[i]->interaccionesTotal*/)*consideracionIndirectos;
              if(origin->amigos[j]->interaccionesTotal != 0)
                interactions += (origin->amigos[j]->interacciones[l]/*/origin->amigos[j]->interaccionesTotal*/)*consideracionIndirectos;

              // interactions += origin->interacciones[i] + origin->amigos[i]->interacciones[k] + origin->interacciones[j] + origin->amigos[j]->interacciones[l];
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
