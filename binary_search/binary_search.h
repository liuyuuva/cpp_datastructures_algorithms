#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

typedef int idx_t;

idx_t binary_search(int* list, int value, idx_t beg, idx_t end){
  
  while (beg <= end){
    int mid = (beg + end )/2;
    if (list[mid] == value)
      return mid;
    else if (list[mid] > value)
      return binary_search(list,  value, beg, mid - 1);
    else
      return binary_search(list,  value, mid + 1, end);
      
  }
  return -1;
}

#endif
