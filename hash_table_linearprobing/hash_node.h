
#ifndef HASH_NODE_H
#define HASH_NODE_H

class HashNode{
 public:
  HashNode() : key_(0), value_(0) {}
  HashNode(int key, int value) : key_(key), value_(value) {}


  int GetKey() const { return key_ ;}
  int GetValue() const {return value_;}
  void SetKey(int key) { this->key_ = key; }
  void SetValue(int val) { this->value_ = val; }

private:
  int key_;
  int value_;
};

#endif
