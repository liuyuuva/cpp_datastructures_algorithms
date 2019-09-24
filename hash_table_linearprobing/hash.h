#include "hash_node.h"

#ifndef HASH_H
#define HASH_H

constexpr int kListLength = 20;


class Hash{
 public:
  Hash();
  ~Hash();

  int HashFun(int key); 
  void Add(int key, int value);
  bool IsInHash(int key);
  int GetValue(int key); 
  void RemoveValue(int key);
  void PrintHash(void); 
  
 private:
  HashNode **ptr_hash_;
};


#endif
