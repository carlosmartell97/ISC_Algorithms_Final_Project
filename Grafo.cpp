#include <iostream>
#include <string>
#include <vector>
// #include <deque>
// #include "Arista.cpp"
#include "Vertice.cpp"
#include "Grafo.h"
// #include "LinkedList.cpp"
using namespace std;

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


vector<Vertice> recommend(Vertice *origin){
  vector<Vertice> recommendations;
  // cout << origin->key << " FRIENDS:" << endl;
  for(int i=0; i<origin->amigos.size(); i++){

    for(int j=i+1; j<origin->amigos.size(); j++){
      // cout << "\t" << origin->amigos[i]->key << " -> " << origin->amigos[j]->key << endl;
      for(int k=0; k<origin->amigos[i]->amigos.size(); k++){
        for(int l=0; l<origin->amigos[j]->amigos.size(); l++){
          // cout << "\t\t" << origin->amigos[i]->amigos[k]->key << " -> " << origin->amigos[j]->amigos[l]->key << flush;
          if(origin->key != origin->amigos[i]->amigos[k]->key && origin->amigos[i]->amigos[k]->key == origin->amigos[j]->amigos[l]->key){
            // cout << "\t\t\t\tTRUE" << flush;
            recommendations.push_back(*origin->amigos[i]->amigos[k]);
          }
          // cout << endl;
        }
      }
    }
    // if(i+1 == origin->amigos.size()) cout << "\t" << origin->amigos[i]->key << " -> NONE" << endl;
  }
  return recommendations;
}

int main(){
  Vertice *carlos = new Vertice("carlos","pass");
  Vertice *juan = new Vertice("juan","123");
  Vertice *maria = new Vertice("maria","asdf");
  Vertice *fernanda = new Vertice("fernanda","word");
  Vertice *pepe = new Vertice("pepe","qwerty");
  Vertice *gus = new Vertice("gus","BATMAN");

  string u;
  u = "carlos";
  cout << u << ": " << carlos->value << endl;
  u = "juan";
  cout << u << ": " << juan->value << endl;
  u = "maria";
  cout << u << ": " << maria->value << endl;
  u = "fernanda";
  cout << u << ": " << fernanda->value << endl;
  u = "pepe";
  cout << u << ": " << pepe->value << endl;
  u = "gus";
  cout << u << ": " << gus->value << endl;
  cout << "------------------------------" << endl;

  // carlos->addFriend(juan,0);
  carlos->amigos.push_back(juan);
  carlos->interacciones.push_back(0);
  juan->amigos.push_back(carlos);
  juan->interacciones.push_back(0);
  //------
  carlos->amigos.push_back(maria);
  carlos->interacciones.push_back(0);
  maria->amigos.push_back(carlos);
  maria->interacciones.push_back(0);
  //------
  juan->amigos.push_back(maria);
  juan->interacciones.push_back(0);
  maria->amigos.push_back(juan);
  maria->interacciones.push_back(0);
  //------
  maria->amigos.push_back(fernanda);
  maria->interacciones.push_back(0);
  fernanda->amigos.push_back(maria);
  fernanda->interacciones.push_back(0);
  //------
  juan->amigos.push_back(fernanda);
  juan->interacciones.push_back(0);
  fernanda->amigos.push_back(juan);
  fernanda->interacciones.push_back(0);
  //------
  carlos->amigos.push_back(gus);
  carlos->interacciones.push_back(0);
  gus->amigos.push_back(carlos);
  gus->interacciones.push_back(0);
  //------
  maria->amigos.push_back(pepe);
  maria->interacciones.push_back(0);
  pepe->amigos.push_back(maria);
  pepe->interacciones.push_back(0);

  /*cout << "carlos friends:" << endl;
  for(int i=0; i<carlos->amigos.size(); i++){
    cout << "\t" << carlos->amigos[i]->key << endl;
      cout << "\t\t" << carlos->amigos[i]->key << " friends: " << endl;
      for(int j=0; j<carlos->amigos[i]->amigos.size(); j++){
        cout << "\t\t\t" << carlos->amigos[i]->amigos[j]->key << endl;
      }
      if(carlos->amigos[i]->amigos.size()==0) cout << "\t\t\t" << "NONE" << endl;
      cout << "-------------------------------" << endl;
  }*/

  vector<Vertice> carlosR = recommend(carlos);
  cout << "carlos recommendations:" << endl;
  for(int i=0; i<carlosR.size(); i++){
    cout << "\t" << carlosR[i].key << endl;
  }

  delete carlos;
  delete juan;
  delete maria;
  delete fernanda;
  delete pepe;
  delete gus;
  return 0;
}
