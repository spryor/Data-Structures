//Author: Stephen Pryor
//This is a quick Binary Search Tree data structure.
//I have not fully tested it but I believe it is correct.
//There is likely room for improvement in the following code. 

#include <iostream>
#include "subtree.cpp"

using namespace std;

template<class T>
class bs_tree {
  private:
    subtree<T> * root;
    int n;
    
    void _insert(T value, subtree<T> * &leaf);
    void _remove(T value, subtree<T> * &leaf);
    bool _search(T value, subtree<T> * leaf);
    void _print_inorder(subtree<T> * leaf);
    void destroy(subtree<T> * &leaf);
  public:
    bs_tree();
    ~bs_tree();
    bool empty();
    int size();
    void insert(T value);
    void remove(T value);
    bool search(T value);
    void print_inorder();
};

template <class T>
bs_tree<T>::bs_tree() {
  root = 0;
  n = 0;
}

template <class T>
bs_tree<T>::~bs_tree() {
  destroy(root);
}

template <class T>
void bs_tree<T>::destroy(subtree<T> * &leaf) {
  if(leaf != 0)
  {
    destroy(leaf.left);
    destroy(leaf.right); 
  }
  delete leaf;
  leaf = 0;
}

template <class T>
bool bs_tree<T>::empty() {
  return root == 0;
}

template <class T>
int bs_tree<T>::size() {
  return n;
}

template <class T>
void bs_tree<T>::insert(T value) {
  if(empty()) {
    root = new subtree<T>(value);
    ++n;
  } else {
    _insert(value, root);
  }
}

template <class T>
void bs_tree<T>::_insert(T value, subtree<T> * &leaf) {
  if(leaf == 0)
  {
    leaf = new subtree<T>(value);
    ++n;
  } else if(leaf->value > value) {
    _insert(value, leaf->left);
  } else if(leaf->value < value) {
    _insert(value, leaf->right);
  }
}

template <class T>
void bs_tree<T>::remove(T value) {
  _remove(value, root);
}

template <class T>
void bs_tree<T>::_remove(T value, subtree<T> * &leaf) {
  if(leaf != 0) {
    if(leaf->value == value) {
      if(leaf->left == 0 && leaf->right == 0)
      {
        delete leaf;
        leaf = 0;
      } else if(leaf->left != 0 && leaf->right == 0) {
        subtree<T> * tmp = leaf;
        leaf = leaf->left;
        delete tmp;
        tmp = 0;
      } else {
        if(leaf->right->left == 0)
        {
          subtree<T> * tmp = leaf;
          leaf->right->left = leaf->left;
          leaf = leaf->right;
          delete tmp;
          tmp = 0;
        } else {
          subtree<T> * prevLeaf = leaf->right;
          subtree<T> * nextLeaf = leaf->right->left;
          while(nextLeaf->left != 0) {
            prevLeaf = nextLeaf;
            nextLeaf = nextLeaf->left;
          }
          leaf->value = nextLeaf->value;
          prevLeaf->left = nextLeaf->right;
          delete nextLeaf;
          nextLeaf = 0;
        }
      }
      --n;
    } else if(leaf->value < value) {
      _remove(value, leaf->right);
    } else if(leaf->value > value) {
      _remove(value, leaf->left);
    }
  }
}

template <class T>
bool bs_tree<T>::search(T value) {
  return _search(value, root);
}

template <class T>
bool bs_tree<T>::_search(T value, subtree<T> * leaf) {
  if(leaf == 0) {
    return false;
  } else if(leaf->value == value) {
    return true;
  } else if(leaf->value > value) {
    return _search(value, leaf->left);
  } else {
    return _search(value, leaf->right);
  }
}

template <class T>
void bs_tree<T>::print_inorder() {
  _print_inorder(root);
}

template <class T>
void bs_tree<T>::_print_inorder(subtree<T> * leaf) {
  if(leaf != 0){
    _print_inorder(leaf->left);
    cout << leaf->value << endl;
    _print_inorder(leaf->right);
  }
}
