#ifndef RBTREE_H_
#define RBTREE_H_

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
  RedBlackTree();
};

#endif
