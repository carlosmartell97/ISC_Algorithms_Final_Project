#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

const bool RED = 0;
const bool BLACK = 1;

struct Node{
  int key;
  bool color;
  Node *right, *left, *parent;

  Node(){
    right = left = parent = NULL;
    color = BLACK;
  }

  Node(int k){
    key=k;
    right = left = parent = NULL;
    color = RED;
  }
};

class RedBlackTree{
  private:
    Node *root, *nil;
    int size;

  public:
    RedBlackTree(){
      this->nil = new Node();
      this->root = this->nil;
      this->nil->parent = this->nil;
      this->size=0;
    }

    int Size(){
      return this->size;
    }

    void inOrder(){
      inOrder(this->root,1);
    }

    void inOrder(Node *node, int mul){
      if(node->right != NULL) {
        inOrder(node->right, mul+1);
      }
      for(int i = 1; i < mul; i++) {
        cout << "\t";
      }
      cout << "[" << node->key << ", ";
      if(node->color) {
        cout << "B";
      }
      else cout << "R";
      cout << "]" << endl;
      if(node->left != NULL) {
        inOrder(node->left, mul+1);
      }
    }

    void insert(int key){
      Node *z = new Node(key);
      Node *y = this->nil;
      Node *x = this->root;

      while(x != this->nil) {
        y = x;
        if(z->key < x->key)
          x = x->left;
        else
          x = x->right;
      }
      z->parent = y;
      if(y == this->nil) {
        this->root = z;
      }
      else if(z->key < y->key)
        y->left = z;
      else
        y->right = z;
        z->left = this->nil;
        z->right = this->nil;
        z->color = RED;

      this->size++;

      insertFix(z);
    }

    void insertFix(Node *z){
      Node *y;
      while(z->parent->color == RED) {
        if(z->parent == z->parent->parent->left) {
          y = z->parent->parent->right;
          if(y->color == RED) {
            z->parent->color = BLACK;
            y->color = BLACK;
            z->parent->parent->color = RED;
            z = z->parent->parent;
          }
          else {
            if(z == z->parent->right) {
              z = z->parent;
              leftRotate(z);
            }
            z->parent->color = BLACK;
            z->parent->parent->color = RED;
            rightRotate(z->parent->parent);
          }
        }
        else {
          y = z->parent->parent->left;
          if(y->color == RED) {
            z->parent->color = BLACK;
            y->color = BLACK;
            z->parent->parent->color = RED;
            z = z->parent->parent;
          }
          else {
            if(z == z->parent->left) {
              z = z->parent;
              rightRotate(z);
            }
            z->parent->color = BLACK;
            z->parent->parent->color = RED;
            leftRotate(z->parent->parent);
          }
        }
      }
      this->root->color = BLACK;
    }

    void rightRotate(Node *x) {
      Node *y = x->left;
      x->left = y->right;
      if(y->right != this->nil) {
        y->right->parent = x;
      }
      y->parent = x->parent;
      if(x->parent == this->nil) {
        this->root = y;
      }
      else if(x == x->parent->right) {
        x->parent->right = y;
      }
      else {
        x->parent->left = y;
      }
      y->right = x;
      x->parent = y;
    }

    void leftRotate(Node *x) {
      Node *y = x->right;
      x->right = y->left;
      if(y->left != this->nil) {
        y->left->parent = x;
      }
      y->parent = x->parent;
      if(x->parent == this->nil) {
        this->root = y;
      }
      else if(x == x->parent->left) {
        x->parent->left = y;
      }
      else {
        x->parent->right = y;
      }
      y->left = x;
      x->parent = y;
    }
};

void randomArray(int *a, int n){
  cout << "size: " << n << endl;
  for(int i=0; i<n; i++){
    a[i] = rand()%3+1;
  }
}

int main(){
  srand(time(NULL));
  cout << rand()%3+1 << endl;
  int n = 10;
  int values[n];
  randomArray(values,n);
  for(int j=0; j<n; j++){
    cout << "a["<<j<<"]:" << values[j] << endl;
  }

  ofstream output;
  output.open("timeComplexities.txt");

  for (int n = 100; n < 1000; n ++) {
    int values[n];
    randomArray(values, n);

    clock_t start = clock();
    RedBlackTree *tree = new RedBlackTree();
    for (int i = 0; i < n; i++) {
      tree->insert(values[i]);
    }

    output << n << " " << clock() - start << " " << n << " "<< log(n) / log(2) << endl;

    delete(tree);
  }
  output.close();

  return 0;
}
