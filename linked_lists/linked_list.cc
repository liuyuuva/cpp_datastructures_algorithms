#include "linked_list.h"
#include <iostream>


LinkedList::LinkedList()
    :head_(nullptr) {}


LinkedList::~LinkedList(){
  ListNode *current = head_;
  ListNode *to_delete = nullptr;
  head_ = nullptr;

  while (current) {
    to_delete = current;
    current = current->GetNext();
    delete to_delete;
  }
}


int LinkedList::GetSize() const{
  ListNode *iter = head_;
  int count = 0;
  if(this->IsEmpty()){
    return 0;
  }

  while(iter){
    ++count;
    iter = iter->GetNext();
  }

  return count;
}


bool LinkedList::IsEmpty() const{
  return head_ == nullptr;
}


int LinkedList::ValueAt(int index) const{
  ListNode *iter = head_;

  if(index > this->GetSize()){
    std::cout << "Invlid index!" << std::endl;
    exit(1);
  }

  for (int i = 1; i < index; ++i){
    iter = iter->GetNext();
  }

  return iter->GetData();
}


void LinkedList::PushFront(int value){
  ListNode *to_be_pushed = new ListNode(value);

  to_be_pushed->SetNext(head_);
  head_ = to_be_pushed;
}


int LinkedList::PopFront(){
  int returned;
  if (this->IsEmpty()){
    std::cout << "Cannot pop: empty list."<<std::endl;
  }
  
  ListNode *to_be_popped = head_;
  returned = head_->GetData();
  head_ = to_be_popped->GetNext();
  delete to_be_popped;
  return returned;
}


void LinkedList::PushBack(int value){
  ListNode *to_be_pushed = new ListNode(value);

  ListNode *tail = head_;

  while(tail->GetNext())
    tail = tail->GetNext();

  tail->SetNext(to_be_pushed);
}


int LinkedList::PopBack(){
  int returned;
  if (this->IsEmpty()){
    std::cout <<"Cannot pop back: empty list." <<std::endl;
  }

  ListNode *to_be_popped = head_;
  ListNode *tail = nullptr;

  while(to_be_popped->GetNext()){
    tail = to_be_popped;
    to_be_popped = to_be_popped->GetNext();
  }

  tail->SetNext(nullptr);
  returned = to_be_popped->GetData();
  delete to_be_popped;
  return returned;
}



int LinkedList::Front() const{
  return head_->GetData();
}


int LinkedList::Back() const{
  ListNode *tail = head_;
  while(tail->GetNext()){
    tail = tail->GetNext();
  }

  return tail->GetData();
}


void LinkedList::Insert(int index, int value){
  ListNode *to_be_inerted = new ListNode(value);
  ListNode *iter = head_;
  ListNode *prev_iter = nullptr;
  
  if (index > this->GetSize()){
    std::cout<<"Error: invalid index. " << std::endl;
    exit(1);
  }

  if (index == 1) {
    this->PushFront(value);
    return;
  }

  if (index == this->GetSize()){
    this->PushBack(value);
    return;
  }

  for (int i =1; i < index; ++i){
    prev_iter = iter;
    iter = iter->GetNext();
  }

  
  to_be_inerted->SetNext(iter);
  prev_iter->SetNext(to_be_inerted);
}



void LinkedList::Erase(int index){
  ListNode *iter = head_;
  ListNode *prev_iter = nullptr;
  
  if (index > this->GetSize()){
    std::cout<< "Error: Invalid index." << std::endl;
    exit(1);
  }

  if (index == 1)
    this->PopFront();
  else if (index == this->GetSize())
    this->PopBack();

  for (int i = 1; i < index; ++i){
    prev_iter = iter;
    iter = iter->GetNext();
  }

  prev_iter->SetNext(iter->GetNext());

  delete iter;
}


int LinkedList::ValueNFromEnd(int n){
  ListNode *iter = head_;
  
  if(n == 1)
   return this->Back();
  else if (n == this->GetSize())
    return this->Front();

  for (int i=1; i<=this->GetSize() - n;++i){
    iter = iter->GetNext();
  }

  return iter->GetData();
}


void LinkedList::Reverse(){
  ListNode *next = head_->GetNext()->GetNext();
  ListNode *current = head_->GetNext();
  ListNode *prev = head_;

  while(next){
    current->SetNext(prev);

    prev = current;

    current = next;

    next = next->GetNext();
  }

  current->SetNext(prev);
  head_->SetNext(nullptr);
  head_ = current;
}


void LinkedList::RemoveValue(int value){
  
  if(this->IsEmpty())
  {
    std::cout << "Error: List is empty" << std::endl;
    return;
  }
  
  ListNode *iter = head_;
  ListNode *to_be_removed = nullptr;

  while(iter == head_){
    if (iter->GetData() == value){
      static_cast<void>(this->PopFront());
      std::cout << "poping the head value" << std::endl;
      iter = head_;
    }
    else{
      break;
    }
  }
     
  //now iter is still at head, but the data is not the value to removed.
  while(iter->GetNext()->GetNext()){
    if (iter->GetNext()->GetData() == value){
      to_be_removed = iter->GetNext();
      iter->SetNext(iter->GetNext()->GetNext());

      delete to_be_removed;
      std::cout << "removing values in the middle" << std::endl;
    }
    iter = iter->GetNext();
  }

  iter = iter->GetNext();
  if (!iter->GetNext() && iter->GetData() == value)
    static_cast<void>(this->PopBack());
  
  
}
    

std::ostream& operator<< (std::ostream& out, const LinkedList& list){
  ListNode *iter = list.head_;

  while(iter){
    out << iter->GetData() << " ";
    iter = iter->GetNext();
  }

  return out;
}
  


