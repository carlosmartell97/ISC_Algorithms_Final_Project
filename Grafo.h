#ifndef GRAFO_H_
#define GRAFO_H_

struct Recommendation{
  Vertice *person;
  double totalInteractions;
  Recommendation(Vertice *person,double totalInteractions){
    this->person = person;
    this->totalInteractions = totalInteractions;
  }
};
vector<Recommendation> recommend(Vertice *origin);

#endif
