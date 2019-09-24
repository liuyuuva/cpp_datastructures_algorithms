#include "hash_node.h"

#ifndef HASH_H
#define HASH_H

constexpr int kListLength = 10;


class Hash{
 public:
  Hash();
  ~Hash();

  int HashFun(int key); //tested
  void Add(int key, int value);//tested
  bool IsInHash(int key);//tested
  int GetValue(int key); //tested
  void RemoveValue(int key);
  void PrintHash(void); //tested
  
 private:
  HashNode **ptr_hash_;
};


#endif
