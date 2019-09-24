#include "hash.h"
#include <iostream>

int main(int argc, char *argv[])
{
  Hash a;
  a.Add(75, 8);
  a.Add(11, 2);
  a.Add(25, 7);
  a.Add(27, 0);
  a.Add(28, 1);
  a.Add(113, 9);
  a.Add(16, 22);
  a.Add(26, 40);
  a.Add(85, 50);
  a.Add(105, 1);
  
  std::cout << "27 is in the hash? " << a.IsInHash(27) << std::endl;
  std::cout << "25 is in the hash? " << a.IsInHash(25) << std::endl;
  std::cout << "13 is in the hash? " << a. IsInHash(13) << std::endl;

  std::cout << "Value for 113 is: " << a.GetValue(113) << std::endl;
  std::cout << "Value for 15 is : " << a.GetValue(15) << std::endl;

  std::cout << "Hash before deleting " << std::endl;
  a.PrintHash();

  a.RemoveValue(85);
  std::cout << "Hash after deleting " << std::endl;
  a.PrintHash();
  return 0;
}
