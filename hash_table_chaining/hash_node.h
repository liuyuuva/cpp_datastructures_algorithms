
#ifndef HASH_NODE_H
#define HASH_NODE_H

class HashNode{
 public:
  HashNode() : key_(0), value_(0), next_node_(nullptr) {}
  HashNode(int key, int value) : key_(key), value_(value), next_node_(nullptr) {};


  int GetKey() const { return key_ ;}
  int GetValue() const {return value_;}
  HashNode *GetNext() const { return next_node_; }
  void SetNext(HashNode *next) { this->next_node_ = next; }
  void SetKey(int key) { this->key_ = key; }
  void SetValue(int val) { this->value_ = val; }

private:
  int key_;
  int value_;
  HashNode *next_node_;
};

#endif
