// #include <iostream>
// #include <string>
// #include "Vertice.cpp"
using namespace std;

struct Node; struct LinkedList;

struct Node{
    Node *previous, *next;
    LinkedList *list;
    Vertice vert;

    Node(Vertice vert) {
        this->previous = this->next = NULL;
        this->list = NULL;
        this->vert = vert;
    }

    Node(Vertice vert, LinkedList *list) {
      this->previous = this->next = NULL;
        this->list = list;
        this->vert = vert;
    }

    Node(Vertice vert, Node *previous, LinkedList *list) {
        this->previous = previous;
        this->list = list;
        this->vert = vert;
        this->next = NULL;
    }

    Node(Vertice vert, Node *prev, Node *next, LinkedList *list) {
        this->vert = vert;
        this->previous = prev;
        this->next = next;
        this->list = list;
    }
};

struct LinkedList {
    Node *tail, *head;
    int size;

    LinkedList() {
        this->tail = NULL;
        this->head = NULL;
        this->size = 0;
    }

    LinkedList(Vertice vert) {
        Node *n = new Node(vert, this);
        this->tail = n;
        this->head = n;
        this->size = 1;
    }

    LinkedList(Node *node) {
        node->previous = node->next = NULL;
        node->list = this;
        this->tail = node;
        this->head = node;
        this->size = 1;
    }

    void pushBack(Vertice vert) {
        Node *n = new Node(vert, this->tail, this);
        if (this->head == NULL) {
            this->head = n;
            this->tail = n;
        } else {
            this->tail->next = n;
        }
        this->tail = n;
        this->size++;
    }

    void pushBack(Node *x) {
        x->list = this;
        x->previous = tail;
        if (this->head == NULL) {
            tail = x;
            head = x;
        } else {
            this->tail->next = x;
        }
        this->tail = x;
        this->size++;
    }

    void pushFront(Vertice vert) {
        Node *n = new Node(vert, NULL, head, this);
        if (this->head == NULL) {
            this->tail = n;
            this->head = n;
        } else {
            head->previous = n;
        }
        head = n;
        size++;
    }

    void pushFront(Node* x) {
        x->previous = NULL;
        x->next = head;
        x->list = this;
        if (this->head == NULL) {
            this->head = x;
            this->tail = x;
        } else {
            this->head->previous = x;
        }
        this->head = x;
        this->size++;
    }

    void append(LinkedList *list) {
        this->tail->next = list->head;
        list->head->previous = tail;

        Node *current = list->head;
        while (current != NULL) {
            current->list = this;
            current = current->next;
        }
        this->tail = list->tail;
        this->size += list->size;
    }

    bool isEmpty(){
      return this->size==0 || this->head==NULL;
    }

    bool contains(Vertice vert){
      Node *temp = this->head;
      while(temp!=NULL){
        cout << "run" << endl;
        if(vert.key==temp->vert.key) return true;
        temp = temp->next;
      }
      return false;
    }

    Vertice popFront(){
      if(!this->isEmpty()){
        Vertice removed = this->head->vert;
        if(this->head->next==NULL){
            cout << "case1... head:" << this->head->vert.key << "     previous:" << "NULL" << "     next:" << "NULL" << endl;
            this->head = NULL;
            this->tail = NULL;
            size--;
        }
        else{
          cout << "case2... head:" << this->head->vert.key << "     previous:" << "NULL" << "     next:" << this->head->next->vert.key << endl;
          this->head = this->head->next;
          size--;
        }
        return removed;
      }
    }

    void print() {
      if(!this->isEmpty()){
        Node *current = this->head;
        while (current != NULL) {
            cout << current->vert.key << ' ';
            current = current->next;
        }
      } else {
        cout << "list is empty" << flush;
      }
    }
};

/*
// possible use case:
int main(){
  LinkedList *list = new LinkedList();
  Vertice *carlos = new Vertice("carlos","pass");
  Vertice *juan = new Vertice("juan","123");
  Vertice *maria = new Vertice("maria","asdf");

  list->pushBack(*carlos);
  list->pushBack(*juan);
  list->pushBack(*maria);

  cout << "head: " << list->head->vert.key << "     tail: " << list->tail->vert.key << endl;
  cout << "LIST: " << flush; list->print(); cout << "      size:" << list->size << endl << endl;

  cout << "contains maria: " << list->contains(*maria) << endl << endl;

  list->popFront();
  cout << "LIST after popFront: " << flush; list->print(); cout << "\t\t size:" << list->size << endl << endl;
  list->popFront();
  cout << "LIST after popFront: " << flush; list->print(); cout << "\t\t size:" << list->size << endl << endl;
  list->popFront();
  cout << "LIST after popFront: " << flush; list->print(); cout << "\t\t size:" << list->size << endl << endl;

  delete list;
  delete carlos;
  delete juan;
  delete maria;
  return 0;
}*/
