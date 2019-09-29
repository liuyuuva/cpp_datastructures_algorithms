#ifndef MAX_HEAP_H
#define MAX_HEAP_H
#include <iostream>

constexpr int kListCapacity = 20;
typedef  int idx_t;

class MaxHeap{
 public:
  MaxHeap(int* source, int size); 
  MaxHeap(); 
  ~MaxHeap(); 

  void Insert(int value); 
  int GetMax(); 
  int GetSize();
  bool IsEmpty();
  int ExtractMax();
  void SiftDown(idx_t to_sift);

  void RemoveValue(int value);
  void Heapify();
  bool IsInHeap(int value);
  int GetIndex(int value); 
  bool IsLeaf(idx_t idx); 
  void PrintHeap(); 
  idx_t LeftChild(idx_t idx);
  idx_t RightChild(idx_t idx);
  idx_t Parent(idx_t idx);
  void Swap(idx_t idx1, idx_t idx2);// done
  
  friend std::ostream& operator<< (std::ostream& out, MaxHeap& heap);
  
  
 private:
  int *pheap_;
  int size_;
  int capacity_;
};


int*  HeapSort(int* list, int size);
  

#endif
