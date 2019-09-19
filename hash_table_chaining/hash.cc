#include "hash.h"
#include <iostream>

Hash::Hash() {
  ptr_hash_ = new HashNode*[kListLength];
  for (int i = 0; i < kListLength; ++i) {
    ptr_hash_[i] = nullptr;
  }
}


Hash::~Hash(){
  HashNode* to_del = nullptr;
  HashNode* head = nullptr;
  HashNode* iter = nullptr;
  for(int i = 0; i < kListLength; ++i){
    if (ptr_hash_[i] !=nullptr){
      head = ptr_hash_[i];
      iter = ptr_hash_[i]->GetNext();
      while(iter)
      {
        to_del = iter;
        iter = iter->GetNext();
        std::cout << "deleting a node" << std::endl;
        delete to_del;
      }
      delete head;
      std::cout << "deleting a node" << std::endl;
    }
  }
  std::cout << "deleting the HashNode pointer array" << std::endl;
  delete[] ptr_hash_;
}


int Hash::HashFun(int key){
  
  return (key % kListLength);
}

void Hash::Add(int key, int value){

  HashNode * to_add = new HashNode(key, value);
  int hash_res = HashFun(key);

  if (ptr_hash_[hash_res] == nullptr)
    ptr_hash_[hash_res] = to_add;
  else{
    HashNode * iter = ptr_hash_[hash_res];
    while(iter->GetNext())
      iter = iter->GetNext();

    iter->SetNext(to_add);
  }
}

bool Hash::IsInHash(int key){
  int hash_res = HashFun(key);

  if(ptr_hash_[hash_res]==nullptr)
    return false;
  else{
    HashNode * iter = ptr_hash_[hash_res];
    while(iter){
      if (iter->GetKey() == key)
        return true;
      iter = iter->GetNext();
    }

    return false;
  }
}

int Hash::GetValue(int key){

  if(!IsInHash(key)){
    std::cout << "Key not in tree!" << std::endl;
    return INT32_MIN;
  }
  int hash_res = HashFun(key);
  
  HashNode * iter = ptr_hash_[hash_res];
  while (iter) {
    if (iter->GetKey() == key)
      return iter->GetValue();
    iter = iter->GetNext();
  }
  return INT32_MIN;
}


void Hash::RemoveValue(int key){
  // if (!IsInHash(key)) {
  //   std::cout << "Key not in tree!" << std::endl;
  //   return;
  // }

  int hash_res = HashFun(key);
  HashNode *iter = ptr_hash_[hash_res];
  HashNode *prev = iter;

  if (ptr_hash_[hash_res]->GetKey() == key){
    HashNode * to_delete = ptr_hash_[hash_res];
    ptr_hash_[hash_res] = ptr_hash_[hash_res]->GetNext();
    delete to_delete;
  }
  else{
    while (iter->GetKey() != key){
      prev = iter;
      iter =  iter->GetNext();
    }
    
    prev->SetNext(iter->GetNext());
    delete iter;
  }
}

    
void Hash::PrintHash(){

  for(int i = 1; i < kListLength; ++i){
    if (ptr_hash_[i] == nullptr)
      std::cout << "NULL" << std::endl;
    else{
      std::cout << "(" << ptr_hash_[i]->GetKey() << ", " << ptr_hash_[i]->GetValue() << ")";
      HashNode* iter = ptr_hash_[i]->GetNext();
      while(iter){
        std::cout << " --> ";
        std::cout << "(" << iter->GetKey() << ", " << iter->GetValue() << ")";
        iter = iter->GetNext();
      }
      std::cout << std::endl;
    }
  }
}
        
    
