#ifndef BST_H
#define BST_H

#include "bst_node.h"
#include <iostream>


class BST{
 private:
  BSTNode *root_;

  
 public:
  BST();
  ~BST(); //tested
  BSTNode *GetRoot() { return this->root_; };//tested
  void SetRoot(BSTNode *ptr) { this->root_ = ptr; };//tested
  BSTNode* Insert(BSTNode* root,int value);//tested
  int GetNodeCount(BSTNode* node);//tested
  void DeleteTree(BSTNode* root);//tested
  bool IsInTree(BSTNode* root, int value);//tested
  BSTNode* FindInTree(BSTNode* root, int value);//tested
  int GetHeight(BSTNode* root);//tested
  BSTNode* GetMin(BSTNode* root);//tested
  BSTNode* GetMax(BSTNode* root);//tested
  bool IsBSTUtil(BSTNode* root, int min_value, int max_value);
  bool IsBST(BSTNode *root);//tested
  BSTNode* DeleteValue(BSTNode* root, int value);//tested
  BSTNode* GetSuccessor(BSTNode* root, BSTNode* input);
  void PreOrderPrint(BSTNode* root);
  void InOrderPrint(BSTNode* root);
  void PostOrderPrint(BSTNode* root);
  bool IsLeaf(BSTNode* node);

};


#endif
