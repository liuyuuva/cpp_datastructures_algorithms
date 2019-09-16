#include "bst.h"
#include <iostream>

using namespace std;

BST::BST() { root_ = nullptr; }

BST::~BST(){
  this->DeleteTree(root_);
}

BSTNode* BST::Insert(BSTNode* root, int value) {
  if (!root) {
    root = new BSTNode(value);
    return root;
  }

  if (IsInTree(root, value)) {
    cout << "Value is already in tree." << endl;
    return root;
  }


  if (value < root->key_) {

    root->left_ = Insert(root->left_, value);
  } else if (value > root->key_ ){
    root->right_ = Insert(root->right_, value);
  }

  return root;
}


int BST::GetNodeCount(BSTNode *root) {
  if (!root)
    return 0;
  else{
    return this->GetNodeCount(root->left_) + this->GetNodeCount(root->right_) + 1;
  }  
}

void BST::DeleteTree(BSTNode *root) {
  if (!root) {
    return;
  }

  DeleteTree(root->left_);
  DeleteTree(root->right_);

  delete root;
}

bool BST::IsInTree(BSTNode *root, int value) {
  if (!root)
    return false;

  if (value == root->key_)
    return true;

  if (value < root->key_)
    return IsInTree(root->left_, value);
  else
    return IsInTree(root->right_, value);
}

int BST::GetHeight(BSTNode *root) {
  int left_h = 0, right_h = 0;
  if (!root)
    return 0;
  else{
    left_h= GetHeight(root->left_);
    right_h = GetHeight(root->right_);
    return (left_h > right_h ? left_h : right_h) + 1;
  }
}

BSTNode *BST::GetMin(BSTNode *root) {
  if (!root)
    return nullptr;
  BSTNode *iter = root;

  while (iter->left_)
    iter = iter->left_;

  return iter;
}

BSTNode *BST::GetMax(BSTNode *root) {
  if (!root)
    return nullptr;

  BSTNode *iter = root;

  while (iter->right_)
    iter = iter->right_;

  return iter;
}

bool BST::IsBSTUtil(BSTNode *root, int min_value, int max_value) {
  if (!root)
    return true;
  if (root->key_ > min_value && root->key_ < max_value &&
      IsBSTUtil(root->left_, min_value, root->key_) &&
      IsBSTUtil(root->right_, root->key_, max_value))
    return true;
  else
    return false;
}

bool BST::IsBST(BSTNode *root) { return IsBSTUtil(root, INT32_MIN, INT32_MAX); }

BSTNode *BST::DeleteValue(BSTNode *root, int value) {
  if (!root){
    return root;
  }

  if (value < root->key_)
    root->left_ = DeleteValue(root->left_, value);
  else if (value > root->key_)
    root->right_ = DeleteValue(root->right_, value);
  else {

    if (root->left_ == nullptr) {
      BSTNode *temp = root->right_;
      delete root;
      return temp;
    } else if (root->right_ == nullptr) {
      BSTNode *temp = root->left_;
      delete root;
      return temp;
    }

    BSTNode *temp = GetMin(root->right_);

    root->key_ = temp->key_;

    root->right_ = DeleteValue(root->right_, temp->key_);
  }
  return root;
}

BSTNode *BST::FindInTree(BSTNode *node, int value) {
  if (!node) {
    return node;
  }

  if (node->key_ == value)
    return node;
  else if (node->key_ < value)
    return FindInTree(node->right_, value);
  else
    return FindInTree(node->left_, value);
}


BSTNode *BST::GetSuccessor(BSTNode* root, BSTNode* input) {
  
  if (!root || !input)
    return nullptr;

  if (input->right_ )
    return GetMin(input->right_);

  BSTNode* last_left = nullptr;
  while(root){
    if(input->key_ < root-> key_){
      last_left = root;
      root = root->left_;
    }
    else if (input->key_ > root->key_){
      root = root->right_;
    }
    else
      break;
      
  }

  return last_left;
}

void BST::PreOrderPrint(BSTNode *root){
  if(!root)
    return;
  else{
    std::cout<< root->key_ << " ";
    PreOrderPrint(root->left_);
    PreOrderPrint(root->right_);
  }

}


void BST::InOrderPrint(BSTNode *root){
  if(!root)
    return;
  else{
    InOrderPrint(root->left_);
    std::cout << root->key_ << " ";
    InOrderPrint(root->right_);
  }
}

void BST::PostOrderPrint(BSTNode *root){
  if(!root)
    return;
  else{
    PostOrderPrint(root->left_);
    PostOrderPrint(root->right_);
    std::cout << root->key_ << " ";
  }

}

bool BST::IsLeaf(BSTNode* node){
  return !(node->GetLeft()) && !(node->GetRight());
}
