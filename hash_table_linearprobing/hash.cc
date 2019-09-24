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
 
  for(int i = 0; i < kListLength; ++i){
    if (ptr_hash_[i] !=nullptr){
      to_del = ptr_hash_[i];
      delete to_del;
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
  else {
    int i = 1;
    while(ptr_hash_[hash_res+i]!=nullptr && (hash_res+i) <kListLength){
      
      if (ptr_hash_[hash_res+i]->GetKey() == key) {
        std::cout << "Key already in hash!" << std::endl;
        return;
      }
      
      ++i;
    }
    if((hash_res+i)==kListLength) {
      std::cout << "Array full!" << std::endl;
      return;
    } //TODO: will add array expansion later
    ptr_hash_[hash_res+i] = to_add;
  }
}


bool Hash::IsInHash(int key){
  int hash_res = HashFun(key);

  if(ptr_hash_[hash_res]==nullptr)
    return false;
  else{
    for (int i = 0; ptr_hash_[hash_res+i]!=nullptr; ++i)
    {
      if (ptr_hash_[hash_res+i]->GetKey() == key){
        return true;
      }
    }
    return false;
  }
}



int Hash::GetValue(int key){

  int hash_res = HashFun(key);
  int i = 0;
  while (ptr_hash_[hash_res+i]) {
    if (ptr_hash_[hash_res+i]->GetKey() == key)
      return ptr_hash_[hash_res+i]->GetValue();
    ++i;
  }
  return INT32_MIN;
}


void Hash::RemoveValue(int key){
  int hash_res = HashFun(key);
  int i = 0;
  HashNode *to_delete = nullptr;
  HashNode *to_move = nullptr;
  int to_move_index = 0;
  while(ptr_hash_[hash_res+i]!=nullptr && (hash_res+i)<kListLength){
    if(ptr_hash_[hash_res+i]->GetKey()==key){
      to_delete = ptr_hash_[hash_res+i];
      if (ptr_hash_[hash_res+i+1] == nullptr)
        to_move = nullptr;
      else{
        int j =1;
        while(ptr_hash_[hash_res+i+j]!=nullptr && ptr_hash_[hash_res+i+j]->GetKey()<=key)
          ++j;
          to_move_index = hash_res+i+j;
          to_move = ptr_hash_[hash_res+i+j];
      }
      break;
    }
    ++i;
  }
      
   
    
  if (!to_delete){
    std::cout << "Key not found in hash!" << std::endl;
    return;
  }
  
  delete to_delete;
  if(to_move){
    ptr_hash_[hash_res+i] = to_move;
    ptr_hash_[to_move_index] = nullptr;
  }
    
}
    
void Hash::PrintHash(){

  for(int i = 0; i < kListLength; ++i){
    if (ptr_hash_[i] == nullptr)
      std::cout << "NULL ";
    else{
      std::cout << "(" << ptr_hash_[i]->GetKey() << ", " << ptr_hash_[i]->GetValue() << ") ";
      }
  }
  std::cout << std::endl;
}
    

        
    
