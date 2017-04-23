#ifndef GRAFO_H_
#define GRAFO_H_


struct Recommendation{
  Vertice *person;
  int totalInteractions;
  Recommendation(Vertice *person,int totalInteractions){
    this->person = person;
    this->totalInteractions = totalInteractions;
  }
};
// deque<Vertice> breadthFirstSearch(Vertice origin,Vertice end);
vector<Recommendation> recommend(Vertice *origin);

#endif
