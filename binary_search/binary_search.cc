#include "binary_search.h"
#include <iostream>

int main(int argc, char *argv[])
{
  int *sort_list = new int[10] { 11, 22, 33, 44, 55, 66, 77, 88, 99, 112 };
  int to_find  = 15;
  idx_t result = -1;
  result = binary_search(sort_list, to_find, 0, 9) ;
  if (result > 0)
    std::cout << "Value's index is: " << result << std::endl;
  else
    std::cout << "Value not in list" << std::endl;
  delete[] sort_list;
  return 0;
}
