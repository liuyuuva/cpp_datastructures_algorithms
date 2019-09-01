#include "array.h"
#include <iostream>



int main(int argc, char *argv[])
{
  Array a(10);
  for(int i = 0; i < 18; i++){
    a.Push(i);
  }
  std::cout << a[15] << std::endl;
  std::cout << a.ValueAtIndex(5) << std::endl;
  //  std::cout << a.ValueAtIndex(18) << std::endl;
  std::cout << a << std::endl;
  static_cast<void>(a.Pop());
  std::cout << a <<std::endl;
  std::cout << "----------------------" << std::endl;
  
  Array d(2);
  d.Push(1);
  d.Push(2);
  std::cout << d <<std::endl;
  static_cast<void>(d.Pop());
  std::cout << d <<std::endl;
  static_cast<void>(d.Pop());
  std::cout << d <<std::endl;
  std::cout << "d is empty?"<< d.IsEmpty() << std::endl;
  std::cout << "d's capacity is: " << d.GetCapacity() << std::endl;
  std::cout << "-----------------------" << std::endl;
  
  
  Array b(20);
  for(int i = 0; i < 18; i++){
    b.Push(i);
  }
  std::cout << b<< std::endl;
  std::cout << "-----------------------" <<std::endl;
  Array c(17);
  std::cout << "Array a is empty? " <<a.IsEmpty()<<std::endl;
  std::cout << "Array c is empty? " <<c.IsEmpty()<<std::endl;
  std::cout << "-----------------------" <<std::endl;

  Array e(20);
  for(int i=0; i < 20; i++){
    e.Push(i);
  }
  std::cout << e<< std::endl;
  e.SizeUp();
  std::cout << "e's capacity is now: " << e.GetCapacity() << std::endl;
  std::cout << e << std::endl;

  // while (e.GetSize() > 7){
  //   static_cast<void>(e.Pop());
  // }
  // e.SizeDown();
  // std::cout << "e's capacity is now: " << e.GetCapacity() << std::endl;
  // std::cout << e << std::endl;
  // std::cout << "----------------------------------------------" << std::endl;


  Array f(16);
  std::cout << "f's capacity is now: " << f.GetCapacity() << std::endl;
  std::cout << "f's size is: " << f.GetSize() << std::endl;
  for(int i=0; i<30; i++){
    f.Push(i);
  }
  std::cout << f << std::endl;
  std::cout << "f's capacity is now: " << f.GetCapacity() << std::endl;
  std::cout << "----------------------------------------------------------" << std::endl;

  while(f.GetSize() > 6){
    static_cast<void>(f.Pop());
  }
  std::cout << f << std::endl;
  std::cout << "f's capacity is now: " << f.GetCapacity() << std::endl;
  std::cout << "f's size is now: " << f.GetSize() << std::endl;
  std::cout << "----------------------------------------------------------" << std::endl;

  Array g(f);
  std::cout << "After copying, g is: "<< std::endl;
  std::cout << g << endl;
  std::cout << "---------------------------------------------------------------" << std::endl;

  g.Insert(2, 100);
  std::cout << "After inserting, g is: "<< g << std::endl;
  std::cout << "g's size is: " << g.GetSize() << std::endl;
  std::cout << "-----------------------------------------------------" << std::endl;

  Array h(16);
  for(int i = 0; i < 16; i++){
    h.Push(i);
  }
  std::cout << "h's capacity and size are: "<< h.GetCapacity() << " and " << h.GetSize()<< std::endl;
  std::cout << h << std::endl;
  h.Insert(3, 1000);
  std::cout << "h's capacity and size are: "<< h.GetCapacity() << " and " << h.GetSize()<< std::endl;
  std::cout << h << std::endl;
  // while(h.GetSize() > 5)
  //   h.Delete(5);
  
  // std::cout << h << std::endl;
  // std::cout << "h's capacity and size are: "<< h.GetCapacity() << " and " << h.GetSize()<< std::endl;
  std::cout << h.Find(3) << std::endl;
  std::cout << h.Find(49) << std::endl;  
  return 0;
}
