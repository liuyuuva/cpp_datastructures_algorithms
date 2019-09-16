#ifndef BST_NODE_H
#define BST_NODE_H

class BSTNode{
 private:
  int key_;
  BSTNode *left_;
  BSTNode *right_;

 public:
  BSTNode() : key_(0), left_(nullptr), right_(nullptr) {}
  BSTNode(int value, BSTNode *l=nullptr, BSTNode *r=nullptr) : key_(value), left_(l), right_(r) {}

  friend class BST;
  int GetKey(){
    return key_;
  }

  void SetKey(int value){
    key_ = value;
  }

  BSTNode* GetLeft(){
    return left_;
  }

  BSTNode* GetRight(){
    return right_;
  }

  void SetLeft(BSTNode* left){
    left_ = left;
  }

  void SetRight(BSTNode* right){
    right_ = right;
  }
};

#endif
