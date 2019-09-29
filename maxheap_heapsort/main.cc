#include "max_heap.h"
#include <iostream>
#include <array>

int main(int argc, char *argv[])
{
  int *a = new int[10] { 10, 23, 33, 41, 19, 13, 7, 5, 11, 80 };


  MaxHeap h1(a, 10);
  MaxHeap h2;
  std::cout << "h2 is empty? " << h2.IsEmpty() << std::endl;
  
  h2.Insert(7);
  h2.Insert(15);
  h2.Insert(99);
  h2.Insert(72);
  h2.Insert(69);
  h2.Insert(63);
  h2.Insert(3);
  h2.Insert(31);
  h2.Insert(100);
     
  std::cout << h1 << std::endl;
  std::cout << h2 <<std::endl;

  std::cout << "h1's size is: " << h1.GetSize() << std::endl;
  std::cout << "h2's size is: " << h2.GetSize() << std::endl;

  std::cout << "h2's max is: " << h2.ExtractMax() << std::endl;
  std::cout << "h2's size is: " << h2.GetSize() << std::endl;
  std::cout << h2 << std::endl;
  std::cout << "63 is in h2? " << h2.IsInHeap(63) << std::endl;
  std::cout << "Removing 63 from h2." <<std::endl;
  h2.RemoveValue(63);
  std::cout << "Is 63 in h2 now? "<< h2.IsInHeap(63) << std::endl;
  std::cout << h2 << std::endl;
  std::cout << h2.IsLeaf(h2.GetIndex(72))<<std::endl;

  int *sort = new int[15] {
    365, 298, 79, 411, 314, 2019, 815, 608, 423, 17, 821, 530, 214, 120, 521
        };

  std::cout << "Before sorting" << std::endl;
  for(int i = 0; i<15; ++i)
    std::cout << sort[i] << " ";
  std::cout << std::endl;
  
  
  int* result =  HeapSort(sort, 15);

  for(int i = 0; i<15; ++i)
    std::cout << result[i] << " ";

  std::cout << std::endl;

  delete[] result;
  return 0;
}
