#include <iostream>
#include <string>
#include <vector>
#include "Vertice.cpp"
#include "HashTable.cpp"
#include <map>
#include "Grafo.cpp"
using namespace std;

int main(){
  HashTable *users = new HashTable();
  users->clear();
  string u;

  cout << "--------------ADDING USERS---------------------" << endl;
  u = "carlos";
      cout << "\tcontains " << u << ": " << users->contains(u) << "\tpassword " << u << ": " << users->getPassword(u) << endl;
  cout << "ADDED " << users->add(u,"pass") << endl;
      cout << "\tcontains " << u << ": " << users->contains(u) << "\tpassword " << u << ": " << users->getPassword(u) << endl;
  u = "juan";
  cout << "ADDED " << users->add(u,"123") << endl;
      cout << "\tcontains " << u << ": " << users->contains(u) << "\tpassword " << u << ": " << users->getPassword(u) << endl;
  u = "maria";
  cout << "ADDED " << users->add(u,"BOOK") << endl;
      cout << "\tcontains " << u << ": " << users->contains(u) << "\tpassword " << u << ": " << users->getPassword(u) << endl;
  u = "fernanda";
  cout << "ADDED " << users->add(u,"jazz") << endl;
      cout << "\tcontains " << u << ": " << users->contains(u) << "\tpassword " << u << ": " << users->getPassword(u) << endl;
  u = "pepe";
  cout << "ADDED " << users->add(u,"qwerty321") << endl;
      cout << "\tcontains " << u << ": " << users->contains(u) << "\tpassword " << u << ": " << users->getPassword(u) << endl;
  u = "gus";
  cout << "ADDED " << users->add(u,"BATMAN") << endl;
      cout << "\tcontains " << u << ": " << users->contains(u) << "\t\tpassword " << u << ": " << users->getPassword(u) << endl;

  // cout << "\n\n\n--------------ADDING FRIENDSHIPS BETWEEN USERS-----------------------" << endl;
  users->makeFriends(users->getUser("carlos"),users->getUser("juan"),2,0);
  users->makeFriends(users->getUser("carlos"),users->getUser("maria"),4,5);
  users->makeFriends(users->getUser("juan"),users->getUser("maria"),0);
  users->makeFriends(users->getUser("maria"),users->getUser("fernanda"),3,8);
  users->makeFriends(users->getUser("juan"),users->getUser("fernanda"),1,2);
  users->makeFriends(users->getUser("carlos"),users->getUser("gus"),0,3);
  users->makeFriends(users->getUser("maria"),users->getUser("pepe"),0,9);
  users->makeFriends(users->getUser("gus"),users->getUser("pepe"),7,1);

  /*u = "carlos";
  cout << u << " friends:" << endl;
  for(int i=0; i<users->getUser(u)->amigos.size(); i++){
    cout << "\t" << users->getUser(u)->amigos[i]->key << endl;
      cout << "\t\t" << users->getUser(u)->amigos[i]->key << " friends: " << endl;
      for(int j=0; j<users->getUser(u)->amigos[i]->amigos.size(); j++){
        cout << "\t\t\t" << users->getUser(u)->amigos[i]->amigos[j]->key << endl;
      }
      if(users->getUser(u)->amigos[i]->amigos.size()==0) cout << "\t\t\t" << "NONE" << endl;
  }
  cout << "-------------------------------" << endl;*/

  cout << "\n\n\n--------------RECOMMENDING PEOPLE TO USERS-----------------------" << endl;
  u = "carlos";
  vector<Recommendation> userR = recommend(users->getUser(u));
  cout << endl << u << " recommendations:" << endl;
  for(int i=0; i<userR.size(); i++){
    cout << "\t" << userR[i].person->key << "," << userR[i].totalInteractions << endl;
  }
  if(userR.size()==0) cout << "\tNONE" << endl;
  cout << "_________________________________________" << endl;


  if(userR.size()!=0){
  vector<Recommendation> user2R = recommend(userR[0].person);
  cout << endl << userR[0].person->key << " recommendations:" << endl;
  for(int i=0; i<user2R.size(); i++){
    cout << "\t" << user2R[i].person->key << "," << user2R[i].totalInteractions << endl;
  }
  } else{
    cout << "\tno further recommendation origins..." << endl;
  }
  cout << "_________________________________________" << endl;

  users->degreesOfSeparation(6);

  delete users;
  return 0;
}
