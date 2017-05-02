#include <iostream>
#include <string>
#include <vector>
#include "Vertice.cpp"
#include <queue>
#include <limits.h>
// #include <cstdio>
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
  cout << "ADDED " << users->add(u,"pass") << ": " << flush; cout << users->getPassword(u) << endl;
  u = "juan";
  cout << "ADDED " << users->add(u,"123") << ": " << flush; cout << users->getPassword(u) << endl;
  u = "maria";
  cout << "ADDED " << users->add(u,"BOOK") << ": " << flush; cout << users->getPassword(u) << endl;
  u = "fernanda";
  cout << "ADDED " << users->add(u,"jazz") << ": " << flush; cout << users->getPassword(u) << endl;
  u = "pepe";
  cout << "ADDED " << users->add(u,"qwerty321") << ": " << flush; cout << users->getPassword(u) << endl;
  u = "gus";
  cout << "ADDED " << users->add(u,"BATMAN") << ": " << flush; cout << users->getPassword(u) << endl;
  u = "diego";
  cout << "ADDED " << users->add(u,"password") << ": " << flush; cout << users->getPassword(u) << endl;
  u = "raul";
  cout << "ADDED " << users->add(u,"monkey") << ": " << flush; cout << users->getPassword(u) << endl;
  u = "alejandra";
  cout << "ADDED " << users->add(u,"abc123") << ": " << flush; cout << users->getPassword(u) << endl;
  u = "ivan";
  cout << "ADDED " << users->add(u,"shadow") << ": " << flush; cout << users->getPassword(u) << endl;
  u = "andrea";
  cout << "ADDED " << users->add(u,"football") << ": " << flush; cout << users->getPassword(u) << endl;
  u = "tommy";
  cout << "ADDED " << users->add(u,"DRAGON") << ": " << flush; cout << users->getPassword(u) << endl;
  u = "bernardo";
  cout << "ADDED " << users->add(u,"sunshine") << ": " << flush; cout << users->getPassword(u) << endl;
  u = "vero";
  cout << "ADDED " << users->add(u,"love") << ": " << flush; cout << users->getPassword(u) << endl;
  u = "nick";
  cout << "ADDED " << users->add(u,"PePPer") << ": " << flush; cout << users->getPassword(u) << endl;
  u = "kevin";
  cout << "ADDED " << users->add(u,"access_k") << ": " << flush; cout << users->getPassword(u) << endl;
  u = "luisa";
  cout << "ADDED " << users->add(u,"StarWars") << ": " << flush; cout << users->getPassword(u) << endl;
  u = "hugo";
  cout << "ADDED " << users->add(u,"Thunder!") << ": " << flush; cout << users->getPassword(u) << endl;
  u = "emilio";
  cout << "ADDED " << users->add(u,"Freedom") << ": " << flush; cout << users->getPassword(u) << endl;
  // cout << "_________________________________________" << endl;

  cout << "\n\n--------------ADDING FRIENDSHIPS BETWEEN USERS-----------------------" << endl;
  cout << "ADDED several friendships..." << endl;
  users->makeFriends(users->getUser("carlos"),users->getUser("juan"),2,0);
  users->makeFriends(users->getUser("carlos"),users->getUser("maria"),4,5);
  users->makeFriends(users->getUser("juan"),users->getUser("maria"),0);
  users->makeFriends(users->getUser("maria"),users->getUser("fernanda"),3,8);
  users->makeFriends(users->getUser("juan"),users->getUser("fernanda"),1,2);
  users->makeFriends(users->getUser("carlos"),users->getUser("gus"),0,3);
  users->makeFriends(users->getUser("maria"),users->getUser("pepe"),0,9);
  users->makeFriends(users->getUser("gus"),users->getUser("pepe"),7,1);
  users->makeFriends(users->getUser("pepe"),users->getUser("diego"),6,3);
  users->makeFriends(users->getUser("diego"),users->getUser("alejandra"),4,9);
  users->makeFriends(users->getUser("diego"),users->getUser("ivan"),5,2);
  users->makeFriends(users->getUser("alejandra"),users->getUser("ivan"),0);
  users->makeFriends(users->getUser("ivan"),users->getUser("andrea"),7,1);
  users->makeFriends(users->getUser("ivan"),users->getUser("tommy"),4,3);
  users->makeFriends(users->getUser("pepe"),users->getUser("raul"),0);
  users->makeFriends(users->getUser("raul"),users->getUser("bernardo"),2);
  users->makeFriends(users->getUser("raul"),users->getUser("fernanda"),0,6);
  users->makeFriends(users->getUser("bernardo"),users->getUser("nick"),0);
  users->makeFriends(users->getUser("bernardo"),users->getUser("vero"),5,0);
  users->makeFriends(users->getUser("nick"),users->getUser("vero"),6,9);
  users->makeFriends(users->getUser("vero"),users->getUser("kevin"),0);
  users->makeFriends(users->getUser("kevin"),users->getUser("fernanda"),8,7);
  users->makeFriends(users->getUser("carlos"),users->getUser("luisa"),1,8);
  users->makeFriends(users->getUser("juan"),users->getUser("emilio"),4,7);
  users->makeFriends(users->getUser("emilio"),users->getUser("hugo"),8,0);

  // cout << "_________________________________________" << endl;

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

  string text;
  string action,stringParameter,stringParameter2;
  int intParameter,intParameter2;
  while(true){
    cout << "\n\nWhat do you want to do?" << endl;
    cin >> action;

    if(action == "exit" || action == "end")
      break;
    else if(action == "degrees"){
      cin >> intParameter;
      bool prove = users->degreesOfSeparation(intParameter);
      if(prove) text = "TRUE";
      else text = "FALSE";
      cout << endl << "theory of " << intParameter << " degrees of separation is " << text << endl;
    }
    else if(action == "recommend"){
      cin >> stringParameter;
      // if(users->contains(stringParameter)){
        vector<Recommendation> userR = recommend(users->getUser(stringParameter));
        cout << endl << stringParameter << " recommendations:" << endl;
        for(int i=0; i<userR.size(); i++){
          cout << userR[i].person->key << "," << userR[i].totalInteractions << endl;
        }
        if(userR.size()==0) cout << "NONE" << endl;
      // }
      // else
        // cout << "user doesn't exist" << endl;
    }
    else if(action == "friends"){
      cin >> stringParameter;
      cin >> stringParameter2;
      cin >> intParameter;
      cin >> intParameter2;
      users->makeFriends(users->getUser(stringParameter),users->getUser(stringParameter2),intParameter,intParameter2);
      cout << stringParameter << " and " << stringParameter2 << " are now friends" << endl;
    }
    else if(action == "interact"){
      cin >> stringParameter;
      cin >> stringParameter2;
      cin >> intParameter;
      for(int i=0; i<users->getUser(stringParameter)->amigos.size(); i++){
        if(users->getUser(stringParameter)->amigos[i]->key == stringParameter2){
          users->getUser(stringParameter)->interacciones[i] += intParameter;
          cout << "updated " << stringParameter << "'s friendship with " << users->getUser(stringParameter)->amigos[i]->key << endl;
        }
      }
    }
    else if(action == "print"){
      cin >> stringParameter;
      if(stringParameter == "users")
        users->printUsersPosition();
    }
    else{
      cout << "unrecognized command" << endl;
    }
  }
  delete users;
  return 0;
}
