#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "list_node.h"
#include <iostream>

class LinkedList{
 private:
  ListNode *head_;

 public:
  LinkedList();
  LinkedList(const LinkedList&) = delete;
  ~LinkedList();
  int GetSize() const;
  bool IsEmpty() const;
  int ValueAt(int index) const; //let index starts from 1
  void PushFront(int value);
  int PopFront();
  void PushBack (int value);
  int PopBack();
  int Front() const;
  int Back() const;
  void Insert(int index, int value);
  void Erase(int index);
  int ValueNFromEnd(int n); //Return the value of the nth node from the end. The value 1 means the tail.
  void Reverse();
  void RemoveValue(int value);

  friend std::ostream& operator<<(std::ostream& out, const LinkedList& list);

};


#endif
