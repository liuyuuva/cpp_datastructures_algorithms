#include "max_heap.h"
#include <iostream>

MaxHeap::MaxHeap(int *source_array, int size) {
  if (size > kListCapacity){
    std::cout << "Array size exceeds the heap limit." << std::endl;
    return;
  }
    
  pheap_ = source_array;
  size_ = size;
  capacity_ = kListCapacity;
  this->Heapify();
}

MaxHeap::MaxHeap(){
  pheap_ = new int [kListCapacity];
  capacity_ = kListCapacity;
  size_ = 0;
}

MaxHeap::~MaxHeap() {
  size_ = 0;
  std::cout << "Deleting heap." << std::endl;
  delete[] pheap_;
}

int MaxHeap::GetSize() { return size_; }

int MaxHeap::GetMax() { return pheap_[0]; }

void MaxHeap::PrintHeap() {
  for (idx_t idx = 0; idx < size_; ++idx)
    std::cout << pheap_[idx] << " ";
  std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& out, MaxHeap &heap) {
  for (idx_t idx = 0; idx < heap.GetSize(); ++idx)
    out << heap.pheap_[idx] << " ";

  out << std::endl;
  return out;
}

bool MaxHeap::IsEmpty() { return size_ == 0; }

bool MaxHeap::IsInHeap(int value) {
  bool found = false;
  for (idx_t index = 0; index < size_; ++index) {
    if (pheap_[index] == value)
      found = true;
  }
  return found;
}

int MaxHeap::GetIndex(int value) {
  int idx = -1;
  for (idx_t i = 0; i < size_; ++i) {
    if (pheap_[i] == value)
      idx = i;
  }
  
  return idx;
}

bool MaxHeap::IsLeaf(idx_t index) { return index >= (size_ / 2); }

idx_t MaxHeap::LeftChild(idx_t index) {
  if (this->IsLeaf(index)) {
    std::cout << "No left child for a leaf. " << std::endl;
    return 0;
  } else
    return 2 * index + 1;
}

idx_t MaxHeap::RightChild(idx_t index) {
  if (this->IsLeaf(index)) {
    std::cout << "No right child for a leaf. " << std::endl;
    return 0;
  } else
    return 2 * index + 2;
}

idx_t MaxHeap::Parent(idx_t index) {
  if (index == 0) {
    std::cout << "Index is root!" << std::endl;
    return 0;
  } else {
    return (index - 1) / 2;
  }
}

void MaxHeap::Heapify() {
  for (idx_t idx = size_ / 2 - 1; idx >= 0; --idx)
    this->SiftDown(idx);
}

void MaxHeap::Swap(idx_t idx1, idx_t idx2) {
  if (idx1 >= size_ || idx2 >= size_) {
    std::cout << "Invalid indices!" << std::endl;
    return;
  }

  int tmp = pheap_[idx1];
  pheap_[idx1] = pheap_[idx2];
  pheap_[idx2] = tmp;
}

void MaxHeap::SiftDown(idx_t to_sift) {
  while (!IsLeaf(to_sift)) {
    idx_t larger_child = LeftChild(to_sift);
    if (larger_child < size_ - 1 &&
        pheap_[larger_child] < pheap_[larger_child + 1])
      ++larger_child;

    if (pheap_[to_sift] >= pheap_[larger_child])
      return;

    int tmp = pheap_[to_sift];
    pheap_[to_sift] = pheap_[larger_child];
    pheap_[larger_child] = tmp;

    //    to_sift = larger_child;
  }
}



void MaxHeap::Insert(int value) {
  if (size_ == capacity_) {
    std::cout << "Heap full. Cannot insert. " << std::endl;
    return;
  }
  idx_t to_add = size_;
  pheap_[to_add] = value;
  ++size_;

  this->Heapify();
}

void MaxHeap::RemoveValue(int value){
  idx_t idx_to_remove = this->GetIndex(value);
  pheap_[idx_to_remove] = pheap_[size_-1];
  size_--;
  this->Heapify();
}

int MaxHeap::ExtractMax(){
  int to_exact = pheap_[0];
  pheap_[0] = pheap_[size_-1];
  size_-=1;
  this->Heapify();
  return to_exact;
}


int* HeapSort(int* list, int size){
  MaxHeap to_be_sorted(list, size);
  int* result = new int[size];
  for (int i = 0; i<size; ++i){
    int current_max = to_be_sorted.ExtractMax();
    result[i] = current_max;
  }

  return result;
}
